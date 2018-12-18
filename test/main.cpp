#include <iostream>
#include <string>
#include "Combo.h"
#include "ComboArray.h"
#include "ConstraintSet.h"
#include "ConstraintType.h"
#include "Date.h"
#include "DateConstraint.h"
#include "DestConstraint.h"
#include "GeoInfo.h"
#include "ImaClient.h"
#include "ImaCore.h"
#include "ilcplex/ilocplex.h"
#include "JourneyInfo.h"
#include "SolutionArray.h"
#include "Solution.h"
#include "TripInfo.h"

int main(int argc, char **argv)
{
    using namespace ima;

    if (argc < 4) {
        std::cerr << "No input file or search redius specified" << std::endl;
        return -1;
    }

    if (argc > 4) {
        std::cerr << "More than two arguments provided" << std::endl;
        return -1;
    }

    ConstraintSet globalSet = ImaCore::parse(argv[1]);
    const DateConstraint &globalPeriod = static_cast<const DateConstraint&>(globalSet.get(ConstraintType::Date));
    Date start = globalPeriod.getLB();
    Date end = globalPeriod.getLB();
    JourneyInfo newJourney(start, end);
    newJourney.setSearchRadius(std::stoi(argv[2]));
    newJourney.setQueryNum(std::stoi(argv[3]));
    newJourney.setConstraintSet(globalSet);

    for (int i = 0; i < globalSet.getNumOfLocals(); ++i) {
        const ConstraintSet &localSet = globalSet.getLocal(i);
        const DateConstraint &localPeriod = static_cast<const DateConstraint&>(localSet.get(ConstraintType::Date));
        const DestConstraint &dest = static_cast<const DestConstraint&>(localSet.get(ConstraintType::Dest));
        GeoInfo locInfo = ImaClient::getGeoInfo(dest.get());
        Date start = localPeriod.getLB();
        Date end = localPeriod.getUB();
        TripInfo newTrip(start, end, locInfo);
        newTrip.setConstraintSet(localSet);
        newJourney.addTripInfo(newTrip);
    }

    ImaClient::resolve(newJourney); // Fetch all the hotel data needed from GDS
    IloEnv env;
    IloTimer timer(env);
    timer.start();
    ImaCore::optimizeLocal(newJourney);
    ImaCore::optimizeGlobal(newJourney);
    timer.stop();
    std::cout << "Aggregate CPU Time: " << timer.getTime() << " sec(s)" << std::endl;
    for (int i = 0; i < newJourney.getNumOfTrips(); ++i) {
        std::cout << "+-+-+-+-+-+-+-+-+-+- Trip " << i + 1<< " Start -+-+-+-+-+-+-+-+-+-+" << std::endl;
        TripInfo &trip = newJourney.getTripInfo(i);
        const ComboArray &comboArr = trip.getComboArr();
        for (int j = 0; j < comboArr.getNumOfCombos(); ++j) {
            const Combo &combo = comboArr.getCombo(j);
            std::cout << "+-+-+-+-+-+-+-+-+-+- Combo " << j + 1 << " at " << combo.getPrice() <<  " -+-+-+-+-+-+-+-+-+-+" << std::endl;
            for (int k = 0; k < combo.getNumOfHotels(); ++k) {
                const Hotel &hotel = combo.getHotel(k);
                hotel.printInfo();
            }
        }
        std::cout << "+-+-+-+-+-+-+-+-+-+- Trip End -+-+-+-+-+-+-+-+-+-+" << std::endl;
    }
    const SolutionArray &solArr = newJourney.getSolArr();
    for (int i = 0; i < solArr.getNumOfSols(); ++i) {
        const Solution &sol = solArr.get(i);
        std::cout << "+-+-+-+-+-+-+-+-+-+- Journey Solution " << i + 1 << " at " << sol.getPrice() << " -+-+-+-+-+-+-+-+-+-+" << std::endl;
        for (int j = 0; j < sol.getNumOfTrips(); ++j) {
            const Combo &combo = sol.get(j);
            std::cout << "+-+-+-+-+-+-+-+-+-+- Trip " << j + 1 << " at " << combo.getPrice() <<  " -+-+-+-+-+-+-+-+-+-+" << std::endl;
            for (int k = 0; k < combo.getNumOfHotels(); ++k) {
                const Hotel &hotel = combo.getHotel(k);
                hotel.printInfo();
            }
        }
    }
    return 0;
}

#include <fstream>
#include <iostream>
#include "ConstraintSet.h"
#include "JourneyInfo.h"
#include "ImaCore.h"

using namespace ima;

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cerr << "No input file" << std::endl;
        return -1;
    }

    if (argc > 2) {
        std::cerr << "More than one argument provided" << std::endl;
        return -1;
    }

    std::ifstream filestream(argv[1]);

    if (filestream.fail()) {
        std::cerr << "File not found" << std::endl;
        return -1;
    }

    ConstraintSet global = ImaCore::parse(argv[1]);
    int m = global.getNumOfConstraints();
    int n = global.getNumOfLocals();
    std::cout << "# of global constraints: " << m << std::endl;
    std::cout << "# of trips: " << n << std::endl;
    for (int i = 0; i < n; ++i) {
        ConstraintSet local = global.getLocal(i);
        std::cout << "Trip " << i + 1 << ": " << std::endl;
        std::cout << "Date: " << (local.have(ConstraintType::Date) ? "V" : "X") << std::endl;
        std::cout << "Destination: " << (local.have(ConstraintType::Dest) ? "V" : "X") << std::endl;
        std::cout << "Budget: " << (local.have(ConstraintType::Budget) ? "V" : "X") << std::endl;
        std::cout << "Service Level: " << (local.have(ConstraintType::ServiceLevel)  ? "V" : "X") << std::endl;
        std::cout << "Guest Number:" << (local.have(ConstraintType::GuestNum) ? "V" : "X") << std::endl;
        std::cout << "Distance of One to Hotel: " << (local.have(ConstraintType::DHDist) ? "V" : "X") << std::endl;
        std::cout << "Distance of Hotel to Hotel: " << (local.have(ConstraintType::HHDura) ? "V" : "X") << std::endl;
        std::cout << "If-then: " << (local.have(ConstraintType::IfThen) ? "V" : "X") << std::endl;
    }
    filestream.close();

    return 0;
}

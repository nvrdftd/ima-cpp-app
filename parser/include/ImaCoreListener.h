#pragma once

#include "antlr4-runtime.h"
#include "Amenity.h"
#include "AmenityConstraint.h"
#include "BedType.h"
#include "BedTypeConstraint.h"
#include "BudgetConstraint.h"
#include "Constraint.h"
#include "ConstraintSet.h"
#include "IfThenConstraint.h"
#include "ImaBaseListener.h"
#include "TravelMode.h"
#include <memory>
#include <string>
#include <unordered_map>

namespace ima {
    class ImaCoreListener: public antlrcpp::ImaBaseListener {
        public:
            ImaCoreListener();

            void exitJourney(antlrcpp::ImaParser::JourneyContext *) final;

            void exitSpecStartDate(antlrcpp::ImaParser::SpecStartDateContext *) final;

            void enterTrip(antlrcpp::ImaParser::TripContext *) final;

            void exitTrip(antlrcpp::ImaParser::TripContext *) final;

            void exitSpecEndDate(antlrcpp::ImaParser::SpecEndDateContext *) final;

            void exitSpecTripDest(antlrcpp::ImaParser::SpecTripDestContext *) final;

            void exitSpecBudget(antlrcpp::ImaParser::SpecBudgetContext *) final;

            void exitSpecSerLvl(antlrcpp::ImaParser::SpecSerLvlContext *) final;

            void exitSpecGuestNum(antlrcpp::ImaParser::SpecGuestNumContext *) final;

            void exitSpecBedType(antlrcpp::ImaParser::SpecBedTypeContext *) final;

            void exitSpecAmenity(antlrcpp::ImaParser::SpecAmenityContext *) final;

            void exitSpecHH(antlrcpp::ImaParser::SpecHHContext *) final;

            void exitSpecDH(antlrcpp::ImaParser::SpecDHContext *) final;

            void enterSpecIfThen(antlrcpp::ImaParser::SpecIfThenContext *) final;

            void exitSpecIfThen(antlrcpp::ImaParser::SpecIfThenContext *) final;

            void exitRange(antlrcpp::ImaParser::RangeContext *) final;

            void bedTypeHandler(std::shared_ptr<BedTypeConstraint>, antlrcpp::ImaParser::BedTypeContext *);

            void amenityHandler(std::shared_ptr<AmenityConstraint>, antlrcpp::ImaParser::AmenityContext *);

            TravelMode findTravelMode(antlrcpp::ImaParser::TravelModeContext *) const;

            void insertConstraint(std::shared_ptr<Constraint>);

            void insertConstraint(std::shared_ptr<Constraint>, std::shared_ptr<Constraint>);

            const ConstraintSet &getGlobal() const;
        private:
            bool _inTrip;
            bool _inIfThen;
            float _lb;
            float _ub;
            antlr4::tree::ParseTreeProperty<std::shared_ptr<Constraint> > _constraintTable;
            ConstraintSet _globalSet;
            ConstraintSet *_localSet;
    };
}

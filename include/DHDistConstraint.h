#pragma once

#include "ConstraintType.h"
#include "RangeConstraint.h"
#include "TravelMode.h"
#include <string>

namespace ima {
    class DHDistConstraint: public RangeConstraint<float> {
        public:
            DHDistConstraint();
            DHDistConstraint(float, float);
            void setTravelMode(TravelMode);
            void setDest(const std::string &);
            TravelMode getTravelMode() const;
            const std::string &getDest() const;
        private:
            std::string _dest;
            TravelMode _mode;
    };
}

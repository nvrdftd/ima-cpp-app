#pragma once

#include "RangeConstraint.h"
#include "TravelMode.h"

namespace ima {
    class HHDistConstraint: public RangeConstraint<float> {
        public:
            HHDistConstraint();
            HHDistConstraint(float, float);
            void setTravelMode(TravelMode);
            TravelMode getTravelMode() const;
        private:
            TravelMode _mode;
    };
}

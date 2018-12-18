#pragma once

#include "RangeConstraint.h"
#include "TravelMode.h"

namespace ima {
    class HHDuraConstraint: public RangeConstraint<float> {
        public:
            HHDuraConstraint();
            HHDuraConstraint(float, float);
            void setTravelMode(TravelMode);
            TravelMode getTravelMode() const;
        private:
            TravelMode _mode;
    };
}

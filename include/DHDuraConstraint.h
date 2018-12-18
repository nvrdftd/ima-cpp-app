#pragma once

#include "RangeConstraint.h"
#include "TravelMode.h"
#include <string>

namespace ima {
    class DHDuraConstraint: public RangeConstraint<float> {
        public:
            DHDuraConstraint();
            DHDuraConstraint(float, float);
            void setTravelMode(TravelMode);
            void setDest(const std::string &);
            TravelMode getTravelMode() const;
            const std::string &getDest() const;
        private:
            std::string _dest;
            TravelMode _mode;
    };
}

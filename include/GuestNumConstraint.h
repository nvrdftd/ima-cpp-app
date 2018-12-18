#pragma once

#include "RangeConstraint.h"

namespace ima {
    class GuestNumConstraint: public RangeConstraint<int> {
        public:
            GuestNumConstraint();
            GuestNumConstraint(int, int);
    };
}

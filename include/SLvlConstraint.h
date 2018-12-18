#pragma once

#include "RangeConstraint.h"

namespace ima {
    class SLvlConstraint: public RangeConstraint<int> {
        public:
            SLvlConstraint();
            SLvlConstraint(int, int);
    };
}

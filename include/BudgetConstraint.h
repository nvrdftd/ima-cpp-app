#pragma once

#include "RangeConstraint.h"

namespace ima {
    class BudgetConstraint: public RangeConstraint<float> {
        public:
            BudgetConstraint();
            BudgetConstraint(float, float);
    };
}

#include "BudgetConstraint.h"
#include "ConstraintType.h"
#include "RangeConstraint.h"

namespace ima {
    BudgetConstraint::BudgetConstraint(): RangeConstraint(ConstraintType::Budget, 0, 0) {}
    BudgetConstraint::BudgetConstraint(float LB, float UB): RangeConstraint(ConstraintType::Budget, LB, UB) {}
}

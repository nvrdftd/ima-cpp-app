#include "ConstraintType.h"
#include "RangeConstraint.h"
#include "SLvlConstraint.h"

namespace ima {

    SLvlConstraint::SLvlConstraint(): RangeConstraint(ConstraintType::ServiceLevel, 1, 5) {}
    SLvlConstraint::SLvlConstraint(int LB, int UB): RangeConstraint(ConstraintType::ServiceLevel, LB, UB) {}

}

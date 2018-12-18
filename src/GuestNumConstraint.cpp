#include "ConstraintType.h"
#include "GuestNumConstraint.h"
#include "RangeConstraint.h"

namespace ima {
    GuestNumConstraint::GuestNumConstraint(): RangeConstraint(ConstraintType::GuestNum, 1, 2) {}
    GuestNumConstraint::GuestNumConstraint(int LB, int UB): RangeConstraint(ConstraintType::GuestNum, LB, UB) {}
}

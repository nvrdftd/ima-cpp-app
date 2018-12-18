#include "BedTypeConstraint.h"
#include "ConstraintType.h"
#include "MultiCheckConstraint.h"

namespace ima {
    BedTypeConstraint::BedTypeConstraint(): MultiCheckConstraint(ConstraintType::BedType) {}
}

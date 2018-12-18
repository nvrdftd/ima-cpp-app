#include "ConstraintType.h"
#include "CheckConstraint.h"
#include "DestConstraint.h"
#include <string>

namespace ima {
    DestConstraint::DestConstraint(const std::string &dest): CheckConstraint(ConstraintType::Dest, dest) {}
}

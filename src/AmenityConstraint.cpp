#include "Amenity.h"
#include "AmenityConstraint.h"
#include "ConstraintType.h"
#include "MultiCheckConstraint.h"

namespace ima {

    AmenityConstraint::AmenityConstraint(): MultiCheckConstraint(ConstraintType::Amenity) {}

}

#pragma once

#include "Amenity.h"
#include "ConstraintType.h"
#include "MultiCheckConstraint.h"

namespace ima {

    class AmenityConstraint: public MultiCheckConstraint<Amenity> {
        public:
            AmenityConstraint();
    };

}

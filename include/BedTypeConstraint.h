#pragma once

#include "BedType.h"
#include "MultiCheckConstraint.h"

namespace ima {

    class BedTypeConstraint: public MultiCheckConstraint<BedType> {
        public:
            BedTypeConstraint();
    };

}

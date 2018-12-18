#pragma once

#include "ConstraintType.h"
#include "CheckConstraint.h"
#include <string>

namespace ima {

    class DestConstraint: public CheckConstraint<std::string> {
        public:
            DestConstraint(const std::string &);
    };

}

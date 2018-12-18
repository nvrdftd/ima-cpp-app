#pragma once

#include "ConstraintType.h"

namespace ima {

    class Constraint {
        public:
            Constraint(const ConstraintType &);
            ConstraintType getType() const;
        private:
            ConstraintType _type;
    };

}

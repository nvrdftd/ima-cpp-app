#pragma once

#include "ConstraintType.h"
#include "Constraint.h"

namespace ima {

    template <class T>
    class CheckConstraint: public Constraint {
        public:
            CheckConstraint(const ConstraintType &type, const T &check): Constraint(type), _check(check) {}
            const T &get() const
            {
                return _check;
            }
        private:
            T _check;
    };

}

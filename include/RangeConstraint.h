#pragma once

#include "ConstraintType.h"
#include "Constraint.h"

namespace ima {

    template <class T>
    class RangeConstraint: public Constraint {
        public:
            RangeConstraint(const ConstraintType &type, const T LB, const T UB): Constraint(type), _LB(LB), _UB(UB) {}
            T getLB() const
            {
                return _LB;
            }
            T getUB() const
            {
                return _UB;
            }
            void setLB(const T LB)
            {
                _LB = LB;
            }
            void setUB(const T UB)
            {
                _UB = UB;
            }
        private:
            T _LB;
            T _UB;
    };

}

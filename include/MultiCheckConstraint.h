#pragma once

#include <unordered_set>
#include "ConstraintType.h"
#include "Constraint.h"
#include "EnumHash.h"

namespace ima {

    template <class T>
    class MultiCheckConstraint: public Constraint {
        public:
            MultiCheckConstraint(const ConstraintType &type): Constraint(type) {}
            unsigned int getNumOfChecks() const
            {
                return _checkSet.size();
            }
            void add(const T &check)
            {
                _checkSet.insert(check);
            }
            const T &get(const unsigned int index) const
            {
                auto iter = _checkSet.cbegin();
                for (unsigned int i = 1; i <= index; ++i) {
                    ++iter;
                }
                return *iter;
            }
        private:
            std::unordered_set<T, EnumHash> _checkSet;
    };

}

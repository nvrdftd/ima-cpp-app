#pragma once

#include "ConstraintType.h"
#include "Constraint.h"
#include "EnumHash.h"
#include <unordered_map>
#include <vector>
#include <memory>

namespace ima {

    class ConstraintSet {
        public:
            void add(std::shared_ptr<Constraint>);
            void addLocal(const ConstraintSet &);
            const ConstraintSet &getLocal(unsigned int) const;
            unsigned int getNumOfLocals() const;
            Constraint &get(ConstraintType);
            const Constraint &get(ConstraintType) const;
            Constraint &get(unsigned int);
            const Constraint &get(unsigned int) const;
            bool have(ConstraintType) const;
            unsigned int getNumOfConstraints() const;
            void update(std::shared_ptr<Constraint>);
            void remove(ConstraintType);
        private:
            std::unordered_map<ConstraintType, std::shared_ptr<Constraint>, EnumHash> _constraintMap;
            std::vector<ConstraintSet> _localVec;
    };

}

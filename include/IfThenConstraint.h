#pragma once

#include "Constraint.h"
#include <memory>
#include <vector>

namespace ima {

    class IfThenConstraint: public Constraint {
        public:
            IfThenConstraint();
            void add(std::shared_ptr<Constraint>, std::shared_ptr<Constraint>);
            Constraint &getIf(unsigned int);
            const Constraint &getIf(unsigned int) const;
            std::shared_ptr<Constraint> getIfPtr(unsigned int);
            Constraint &getThen(unsigned int);
            const Constraint &getThen(unsigned int) const;
            std::shared_ptr<Constraint> getThenPtr(unsigned int);
            unsigned int getNumOfIfThens() const;
        private:
            std::vector<std::shared_ptr<Constraint> > _ifVec;
            std::vector<std::shared_ptr<Constraint> > _thenVec;
    };

}

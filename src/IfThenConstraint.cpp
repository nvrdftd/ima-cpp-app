#include "Constraint.h"
#include "IfThenConstraint.h"
#include <memory>

namespace ima {
    IfThenConstraint::IfThenConstraint(): Constraint(ConstraintType::IfThen) {}
    void IfThenConstraint::add(std::shared_ptr<Constraint> ifConstraint, std::shared_ptr<Constraint> thenConstraint)
    {
        _ifVec.push_back(ifConstraint);
        _thenVec.push_back(thenConstraint);
    }

    Constraint &IfThenConstraint::getIf(unsigned int index)
    {
        return *_ifVec.at(index);
    }

    const Constraint &IfThenConstraint::getIf(unsigned int index) const
    {
        return *_ifVec.at(index);
    }

    std::shared_ptr<Constraint> IfThenConstraint::getIfPtr(unsigned int index)
    {
        return _ifVec.at(index);
    }

    Constraint &IfThenConstraint::getThen(unsigned int index)
    {
        return *_thenVec.at(index);
    }

    const Constraint &IfThenConstraint::getThen(unsigned int index) const
    {
        return *_thenVec.at(index);
    }

    std::shared_ptr<Constraint> IfThenConstraint::getThenPtr(unsigned int index)
    {
        return _thenVec.at(index);
    }

    unsigned int IfThenConstraint::getNumOfIfThens() const
    {
        return _ifVec.size();
    }

}

#include <memory>
#include "Constraint.h"
#include "ConstraintSet.h"
#include "ConstraintType.h"

namespace ima {

    void ConstraintSet::add(std::shared_ptr<Constraint> constraint)
    {
        _constraintMap.insert(std::make_pair(constraint->getType(), constraint));
    }

    void ConstraintSet::addLocal(const ConstraintSet &set)
    {
        _localVec.push_back(set);
    }

    const ConstraintSet &ConstraintSet::getLocal(unsigned int index) const
    {
        return _localVec.at(index);
    }

    unsigned int ConstraintSet::getNumOfLocals() const
    {
        return _localVec.size();
    }

    Constraint &ConstraintSet::get(ConstraintType type)
    {
        return *_constraintMap.at(type);
    }

    const Constraint &ConstraintSet::get(ConstraintType type) const
    {
        return *_constraintMap.at(type);
    }

    Constraint &ConstraintSet::get(unsigned int index)
    {
        auto iter = _constraintMap.cbegin();
        for (unsigned int i = 1; i <= index; ++i) {
            ++iter;
        }
        return *(iter->second);
    }

    const Constraint &ConstraintSet::get(unsigned int index) const
    {
        auto iter = _constraintMap.cbegin();
        for (unsigned int i = 1; i <= index; ++i) {
            ++iter;
        }
        return *(iter->second);
    }

    bool ConstraintSet::have(ConstraintType type) const
    {
        return _constraintMap.find(type) != _constraintMap.end();
    }

    unsigned int ConstraintSet::getNumOfConstraints() const
    {
        return _constraintMap.size();
    }

    void ConstraintSet::update(std::shared_ptr<Constraint> c)
    {
        ConstraintType type = c->getType();
        _constraintMap.find(type)->second = c;
    }

    void ConstraintSet::remove(ConstraintType type)
    {
        _constraintMap.erase(_constraintMap.find(type));
    }

}

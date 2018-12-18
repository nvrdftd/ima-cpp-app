#include "Constraint.h"
#include "ConstraintType.h"

namespace ima {

    Constraint::Constraint(const ConstraintType &type): _type(type) {}

    ConstraintType Constraint::getType() const
    {
        return _type;
    }

}

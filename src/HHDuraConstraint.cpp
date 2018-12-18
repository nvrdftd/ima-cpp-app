#include "ConstraintType.h"
#include "HHDuraConstraint.h"
#include "RangeConstraint.h"
#include "TravelMode.h"

namespace ima {
    HHDuraConstraint::HHDuraConstraint(): RangeConstraint(ConstraintType::HHDura, 0, 0) {}
    HHDuraConstraint::HHDuraConstraint(float LB, float UB): RangeConstraint(ConstraintType::HHDura, LB, UB) {}
    void HHDuraConstraint::setTravelMode(TravelMode mode)
    {
        _mode = mode;
    }
    TravelMode HHDuraConstraint::getTravelMode() const
    {
        return _mode;
    }
}

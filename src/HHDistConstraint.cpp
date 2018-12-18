#include "ConstraintType.h"
#include "HHDistConstraint.h"
#include "RangeConstraint.h"
#include "TravelMode.h"

namespace ima {

    HHDistConstraint::HHDistConstraint(): RangeConstraint(ConstraintType::HHDist, 0, 0) {}
    HHDistConstraint::HHDistConstraint(float LB, float UB): RangeConstraint(ConstraintType::HHDist, LB, UB) {}
    void HHDistConstraint::setTravelMode(TravelMode mode)
    {
        _mode = mode;
    }
    TravelMode HHDistConstraint::getTravelMode() const
    {
        return _mode;
    }

}

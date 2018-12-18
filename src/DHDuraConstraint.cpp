#include "ConstraintType.h"
#include "DHDuraConstraint.h"
#include "RangeConstraint.h"
#include "TravelMode.h"

namespace ima {
    DHDuraConstraint::DHDuraConstraint(): RangeConstraint(ConstraintType::DHDura, 0, 0) {}
    DHDuraConstraint::DHDuraConstraint(float LB, float UB): RangeConstraint(ConstraintType::DHDura, LB, UB) {}
    void DHDuraConstraint::setTravelMode(TravelMode mode)
    {
        _mode = mode;
    }
    void DHDuraConstraint::setDest(const std::string &dest)
    {
        _dest = dest;
    }
    TravelMode DHDuraConstraint::getTravelMode() const
    {
        return _mode;
    }
    const std::string &DHDuraConstraint::getDest() const
    {
        return _dest;
    }
}

#include "ConstraintType.h"
#include "DHDistConstraint.h"
#include "RangeConstraint.h"
#include "TravelMode.h"

namespace ima {
    DHDistConstraint::DHDistConstraint(): RangeConstraint(ConstraintType::DHDist, 0, 0) {}
    DHDistConstraint::DHDistConstraint(float LB, float UB): RangeConstraint(ConstraintType::DHDist, LB, UB) {}
    void DHDistConstraint::setTravelMode(TravelMode mode)
    {
        _mode = mode;
    }
    void DHDistConstraint::setDest(const std::string &dest)
    {
        _dest = dest;
    }
    TravelMode DHDistConstraint::getTravelMode() const
    {
        return _mode;
    }
    const std::string &DHDistConstraint::getDest() const
    {
        return _dest;
    }
}

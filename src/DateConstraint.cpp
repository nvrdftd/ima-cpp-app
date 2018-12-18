#include "ConstraintType.h"
#include "Date.h"
#include "DateConstraint.h"
#include "RangeConstraint.h"

namespace ima {
    DateConstraint::DateConstraint(const Date &start): RangeConstraint(ConstraintType::Date, start, start + 1) {}
    DateConstraint::DateConstraint(const Date &start, const Date &end): RangeConstraint(ConstraintType::Date, start, end) {}
}

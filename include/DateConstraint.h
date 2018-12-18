#pragma once

#include "Date.h"
#include "RangeConstraint.h"

namespace ima {
    class DateConstraint: public RangeConstraint<Date> {
        public:
            DateConstraint(const Date &);
            DateConstraint(const Date &, const Date &);
    };
}

#pragma once

#include "ConstraintSet.h"
#include "Date.h"

namespace ima {

    class BaseInfo {
        public:
            BaseInfo(const Date &, const Date &);
            BaseInfo(const BaseInfo &) = default;
            BaseInfo(BaseInfo &&) = default;
            BaseInfo &operator=(const BaseInfo &) = default;
            BaseInfo &operator=(BaseInfo &&) = default;
            Date &getStartDate();
            Date &getEndDate();
            void setStartDate(const Date &);
            void setEndDate(const Date &);
            void setConstraintSet(const ConstraintSet &);
            const ConstraintSet &getConstraintSet() const;
        public:
            Date _startDate;
            Date _endDate;
            ConstraintSet _constraintSet;
    };

}

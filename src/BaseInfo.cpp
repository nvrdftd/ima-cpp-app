#include "BaseInfo.h"
#include "ConstraintSet.h"
#include "Date.h"

namespace ima {

    BaseInfo::BaseInfo(const Date &startDate, const Date &endDate)
    {
        _startDate = startDate;
        _endDate = endDate;
    }

    Date &BaseInfo::getStartDate()
    {
        return _startDate;
    }

    Date &BaseInfo::getEndDate()
    {
        return _endDate;
    }

    void BaseInfo::setStartDate(const Date &date)
    {
        _startDate = date;
    }
    void BaseInfo::setEndDate(const Date &date)
    {
        _endDate = date;
    }

    void BaseInfo::setConstraintSet(const ConstraintSet &constraintSet)
    {
        _constraintSet = constraintSet;
    }

    const ConstraintSet &BaseInfo::getConstraintSet() const
    {
        return _constraintSet;
    }

}

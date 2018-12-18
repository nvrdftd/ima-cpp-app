#include "BaseInfo.h"
#include "Date.h"
#include "JourneyInfo.h"
#include "TripInfo.h"

namespace ima {

    JourneyInfo::JourneyInfo(const Date &startDate, const Date &endDate): BaseInfo(startDate, endDate) {}

    void JourneyInfo::setSearchRadius(unsigned int radius)
    {
        _searchRadius = radius;
    }

    void JourneyInfo::addTripInfo(const TripInfo &info)
    {
        _tripVector.push_back(info);
    }

    TripInfo &JourneyInfo::getTripInfo(unsigned int index)
    {
        return _tripVector[index];
    }

    unsigned int JourneyInfo::getNumOfTrips()
    {
        return _tripVector.size();
    }

    unsigned int JourneyInfo::getSearchRadius()
    {
        return _searchRadius;
    }

    const SolutionArray &JourneyInfo::getSolArr() const
    {
        return _solArr;
    }

    void JourneyInfo::setSolArr(const SolutionArray &solArr)
    {
        _solArr = solArr;
    }

    void JourneyInfo::setQueryNum(unsigned int queryNum)
    {
        _queryNum = queryNum;
    }

    unsigned int JourneyInfo::getQueryNum() const
    {
        return _queryNum;
    }

}

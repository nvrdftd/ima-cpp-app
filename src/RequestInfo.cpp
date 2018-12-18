#include "AnyTwoInfo.h"
#include "Date.h"
#include "GeoInfo.h"
#include "HotelArray.h"
#include "InfoArray.h"
#include "RequestInfo.h"

namespace ima {

    RequestInfo::RequestInfo() {}

    RequestInfo::RequestInfo(
        const Date &checkInDate,
        const Date &checkOutDate,
        const GeoInfo &geoInfo,
        unsigned int radius,
        unsigned int numOfHotels
    ): _checkInDate(checkInDate), _checkOutDate(checkOutDate), _geoInfo(geoInfo), _radius(radius), _numOfHotels(numOfHotels) {}


    Date &RequestInfo::getCheckInDate()
    {
        return _checkInDate;
    }

    Date &RequestInfo::getCheckOutDate()
    {
        return _checkOutDate;
    }

    unsigned int RequestInfo::getRadius()
    {
        return _radius;
    }

    GeoInfo &RequestInfo::getGeoInfo()
    {
        return _geoInfo;
    }

    unsigned int RequestInfo::getNumOfHotels()
    {
        return _numOfHotels;
    }

    HotelArray &RequestInfo::getHotelArr()
    {
        return _hotelArr;
    }

    InfoArray<AnyTwoInfo> &RequestInfo::getAnyTwoInfoArr()
    {
        return _infoArr;
    }

    void RequestInfo::setAnyTwoInfoArr(const InfoArray<AnyTwoInfo> &infoArr)
    {
        _infoArr = infoArr;
    }

}

#pragma once

#include "AnyTwoInfo.h"
#include "Date.h"
#include "GeoInfo.h"
#include "HotelArray.h"
#include "InfoArray.h"

namespace ima {

    class RequestInfo {
        public:
            RequestInfo();
            RequestInfo(const Date &, const Date &, const GeoInfo &, unsigned int, unsigned int);
            Date &getCheckInDate();
            Date &getCheckOutDate();
            unsigned int getRadius();
            unsigned int getNumOfHotels();
            GeoInfo &getGeoInfo();
            HotelArray &getHotelArr();
            InfoArray<AnyTwoInfo> &getAnyTwoInfoArr();
            void setAnyTwoInfoArr(const InfoArray<AnyTwoInfo> &);
        private:
            Date _checkInDate;
            Date _checkOutDate;
            GeoInfo _geoInfo;
            unsigned int _radius;
            unsigned int _numOfHotels;
            HotelArray _hotelArr;
            InfoArray<AnyTwoInfo> _infoArr;
    };

}

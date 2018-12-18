#pragma once

#include <string>
#include "Coordinates.h"

namespace ima {

    class GeoInfo {
        public:
            GeoInfo();
            GeoInfo(const std::string &);
            const std::string &getPlaceText() const;
            Coordinates getCoordinates();
            const Coordinates &getCoordinates() const;
            void setPlaceText(std::string &);
            void setCoordinates(double, double);
            void setCoordinates(const Coordinates &);
        private:
            std::string _placeTextString;
            Coordinates _geolocation;
    };

}

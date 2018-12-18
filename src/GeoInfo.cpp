#include <string>
#include "Coordinates.h"
#include "GeoInfo.h"

namespace ima {

    GeoInfo::GeoInfo() {}

    GeoInfo::GeoInfo(const std::string &placeTextString): _placeTextString(placeTextString) {}

    void GeoInfo::setPlaceText(std::string &placeTextString)
    {
        _placeTextString = placeTextString;
    }

    void GeoInfo::setCoordinates(double latitude, double longitude)
    {
        _geolocation = Coordinates(latitude, longitude);
    }

    void GeoInfo::setCoordinates(const Coordinates &geolocation)
    {
        _geolocation = geolocation;
    }

    const std::string &GeoInfo::getPlaceText() const
    {
        return _placeTextString;
    }

    Coordinates GeoInfo::getCoordinates()
    {
        return _geolocation;
    }

    const Coordinates &GeoInfo::getCoordinates() const
    {
        return _geolocation;
    }

}

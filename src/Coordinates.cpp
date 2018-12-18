#include "Coordinates.h"

namespace ima {

    Coordinates::Coordinates(): _latitude(0), _longitude(0) {}

    Coordinates::Coordinates(double latitude, double longitude): _latitude(latitude), _longitude(longitude) {}

    double Coordinates::getLatitude() const
    {
        return _latitude;
    }

    double Coordinates::getLongitude() const
    {
        return _longitude;
    }

}

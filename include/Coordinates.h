#pragma once

namespace ima {

    class Coordinates {
        public:
            Coordinates();
            Coordinates(double, double);
            Coordinates(const Coordinates &) = default;
            Coordinates(Coordinates &&) = default;
            Coordinates &operator=(const Coordinates &) = default;
            Coordinates &operator=(Coordinates &&) = default;
            double getLatitude() const;
            double getLongitude() const;
        private:
            double _latitude;
            double _longitude;
    };

}

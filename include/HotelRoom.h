#pragma once

#include "BedType.h"

namespace ima {

    class HotelRoom {
        public:
            HotelRoom(BedType, unsigned int, double);
            BedType getBedType() const;
            unsigned int getNumOfBeds() const;
            unsigned int getNumOfGuests() const;
            double getPrice() const;
        private:
            BedType _bedType;
            unsigned int _numOfBeds;
            unsigned int _numOfGuests;
            double _price;
    };

}

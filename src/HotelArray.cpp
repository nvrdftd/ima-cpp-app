#include "Hotel.h"
#include "HotelArray.h"

namespace ima {

    void HotelArray::addHotel(const Hotel &hotel)
    {
        _hotelVector.push_back(hotel);
    }

    Hotel &HotelArray::operator[](int index)
    {
        return _hotelVector[index];
    }

    unsigned int HotelArray::getNumOfHotels()
    {
        return _hotelVector.size();
    }

}

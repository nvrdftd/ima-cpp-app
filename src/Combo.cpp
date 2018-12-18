#include "Combo.h"
#include "Hotel.h"

namespace ima {

    Combo::Combo(double price): _price(price) {}

    void Combo::addHotel(const Hotel &newHotel)
    {
        _hotelVector.push_back(newHotel);
    }

    const Hotel &Combo::getHotel(unsigned int index) const
    {
        return _hotelVector[index];
    }

    unsigned int Combo::getNumOfHotels() const
    {
        return _hotelVector.size();
    }

    double Combo::getPrice() const
    {
        return _price;
    }

}

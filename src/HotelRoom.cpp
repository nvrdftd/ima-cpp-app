#include "BedType.h"
#include "HotelRoom.h"

namespace ima {

    HotelRoom::HotelRoom(BedType bedType, unsigned int numOfBeds, double price): _bedType(bedType), _numOfBeds(numOfBeds), _price(price)
    {
        unsigned int num;
        switch (bedType) {
            case BedType::Single:
                num = 1;
                break;
            case BedType::Twin:
                num = 1;
                break;
            case BedType::Double:
                num = 2;
                break;
            case BedType::Queen:
                num = 2;
                break;
            case BedType::King:
                num = 2;
                break;
            default:
                num = 0;
        }
        _numOfGuests = num * numOfBeds;
    }

    BedType HotelRoom::getBedType() const
    {
        return _bedType;
    }

    unsigned int HotelRoom::getNumOfBeds() const
    {
        return _numOfBeds;
    }

    unsigned int HotelRoom::getNumOfGuests() const
    {
        return _numOfGuests;
    }

    double HotelRoom::getPrice() const
    {
        return _price;
    }

}

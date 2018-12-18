#include <iostream>
#include <string>
#include "Amenity.h"
#include "BedType.h"
#include "Coordinates.h"
#include "Date.h"
#include "Hotel.h"
#include "HotelRoom.h"

namespace ima {

    Hotel::Hotel(
        const std::string &code,
        const std::string &name,
        const Coordinates &geoloc,
        const Date &checkInDate,
        const Date &checkOutDate
    ): _hotelCode(code), _hotelName(name), _geolocation(geoloc), _checkInDate(checkInDate), _checkOutDate(checkOutDate) {}

    void Hotel::addRoom(const HotelRoom &hotelRoom)
    {
        _roomVector.push_back(hotelRoom);
    }

    void Hotel::deleteRoom(unsigned int index)
    {
        _roomVector.erase(_roomVector.begin() + index);
    }

    void Hotel::clearRooms()
    {
        _roomVector.clear();
    }

    void Hotel::addAmenity(unsigned int amenityCode)
    {
        _amenitySet.insert(amenityCode);
    }
    void Hotel::addAward(unsigned int rating)
    {
        _awardSet.insert(rating);
    }

    HotelRoom &Hotel::getRoom(unsigned int index)
    {
        return _roomVector.at(index);
    }

    bool Hotel::isAmenity(unsigned int key) const
    {
        return _amenitySet.find(key) != _amenitySet.end();
    }
    bool Hotel::isAward(unsigned int key) const
    {
        return _awardSet.find(key) != _awardSet.end();
    }

    Coordinates &Hotel::getCoordinates()
    {
        return _geolocation;
    }

    std::string Hotel::getHotelName() const
    {
        return _hotelName;
    }

    std::string Hotel::getHotelCode() const
    {
        return _hotelCode;
    }

    unsigned int Hotel::getNumOfRooms()
    {
        return _roomVector.size();
    }

    unsigned int Hotel::getNumOfAmenities()
    {
        return _amenitySet.size();
    }

    unsigned int Hotel::getNumOfAwards()
    {
        return _awardSet.size();
    }

    const Date &Hotel::getCheckInDate() const
    {
        return _checkInDate;
    }

    const Date &Hotel::getCheckOutDate() const
    {
        return _checkOutDate;
    }

    void Hotel::printInfo() const
    {
        std::cout << "Check-in Date: " << _checkInDate.getDateStr() << std::endl;
        std::cout << "Check-out Date: " << _checkOutDate.getDateStr() << std::endl;
        std::cout << "Hotel Name (Code): " << _hotelName << " (" << _hotelCode << ")" << std::endl;
        std::cout << "Hotel Amenities: ";
        for (unsigned int a: _amenitySet) {
            Amenity amenity = static_cast<Amenity>(a);
            switch (amenity) {
                case Amenity::VendingMachines:
                    std::cout << "Vending Machines";
                    break;
                case Amenity::Hotspots:
                    std::cout << "Wi-Fi";
                    break;
                case Amenity::LaundryService:
                    std::cout << "Laundry Service";
                    break;
                case Amenity::Parking:
                    std::cout << "Parking";
                    break;
                case Amenity::NonSmokingRoom:
                    std::cout << "Non-Smoking Room";
                    break;
                case Amenity::SafeDepositBox:
                    std::cout << "Safe Deposit Box";
                    break;
                default:
                   std::cerr << "Amenity Undefined";
            }
            std::cout << ", ";
        }
        std::cout << std::endl;
        std::cout << "Hotel Awards: ";
        for (auto &award: _awardSet) {
            std::cout << award << "-Star, ";
        }
        std::cout << std::endl;
        for (auto &room: _roomVector) {
            std::cout << "Hotel Room: " << std::endl;
            std::cout << "    Price: " << room.getPrice() << std::endl;
            std::cout << "    BedType: ";
            switch (room.getBedType()) {
                case BedType::Single:
                    std::cout << "Single";
                    break;
                case BedType::Twin:
                    std::cout << "Twin";
                    break;
                case BedType::Double:
                    std::cout << "Double";
                    break;
                case BedType::Queen:
                    std::cout << "Queen";
                    break;
                case BedType::King:
                    std::cout << "King";
                    break;
                default:
                    std::cerr << "BedType Undefined";
            }
            std::cout << std::endl;
            std::cout << "    # of Beds: " << room.getNumOfBeds() << std::endl;
            std::cout << "    # of Guests: " << room.getNumOfGuests() << std::endl;
        }
    }

}

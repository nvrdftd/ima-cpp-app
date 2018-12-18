#pragma once

#include <string>
#include <unordered_set>
#include <vector>
#include "Coordinates.h"
#include "Date.h"
#include "DAG.h"
#include "HotelRoom.h"

namespace ima {

    class Hotel {
        public:
            Hotel(const std::string &, const std::string &, const Coordinates &, const Date &, const Date &);
            void addRoom(const HotelRoom &);
            void deleteRoom(unsigned int);
            void clearRooms();
            void addAmenity(unsigned int);
            void addAward(unsigned int);
            HotelRoom &getRoom(unsigned int);
            bool isAmenity(unsigned int) const;
            bool isAward(unsigned int) const;
            Coordinates &getCoordinates();
            std::string getHotelName() const;
            std::string getHotelCode() const;
            unsigned int getNumOfRooms();
            unsigned int getNumOfAmenities();
            unsigned int getNumOfAwards();
            const Date &getCheckInDate() const;
            const Date &getCheckOutDate() const;
            void printInfo() const;
        private:
            std::string _hotelCode;
            std::string _hotelName;
            Coordinates _geolocation;
            std::unordered_set<unsigned int> _amenitySet;
            std::unordered_set<unsigned int> _awardSet;
            std::vector<HotelRoom> _roomVector;
            Date _checkInDate;
            Date _checkOutDate;
    };

}

#pragma once

#include <vector>
#include "Date.h"
#include "DAG.h"
#include "Hotel.h"

namespace ima {

    class HotelArray {
        public:
            void addHotel(const Hotel &hotel);
            unsigned int getNumOfHotels();
            Hotel &operator[](int);
        private:
            std::vector<Hotel> _hotelVector;
    };
    
}

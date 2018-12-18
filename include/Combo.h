#pragma once

#include <vector>
#include "Hotel.h"

namespace ima {

    class Combo {
        public:
            Combo(double);
            Combo(const Combo &) = default;
            Combo(Combo &&) = default;
            Combo &operator=(const Combo &) = default;
            Combo &operator=(Combo &&) = default;
            void addHotel(const Hotel &);
            const Hotel &getHotel(unsigned int) const;
            unsigned int getNumOfHotels() const;
            double getPrice() const;
        private:
            std::vector<Hotel> _hotelVector;
            double _price;
    };

}

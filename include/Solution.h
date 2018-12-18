#pragma once

#include "Combo.h"
#include "ComboArray.h"

namespace ima {

    class Solution {
        public:
            Solution(double);
            void add(const Combo &);
            const Combo &get(unsigned int) const;
            unsigned int getNumOfTrips() const;
            double getPrice() const;
        private:
            ComboArray _comboArr;
            double _price;
    };

}

#include "Combo.h"
#include "ComboArray.h"
#include "Solution.h"

namespace ima {

    Solution::Solution(double price): _price(price) {}

    void Solution::add(const Combo &combo)
    {
        _comboArr.addCombo(combo);
    }

    const Combo &Solution::get(unsigned int index) const
    {
        return _comboArr.getCombo(index);
    }

    unsigned int Solution::getNumOfTrips() const
    {
        return _comboArr.getNumOfCombos();
    }

    double Solution::getPrice() const
    {
        return _price;
    }

}

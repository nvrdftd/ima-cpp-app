#include "ComboArray.h"
#include "Combo.h"

namespace ima {

    unsigned int ComboArray::getNumOfCombos() const
    {
        return _comboVector.size();
    }

    const Combo &ComboArray::getCombo(unsigned int index) const
    {
        return _comboVector[index];
    }

    void ComboArray::addCombo(const Combo &newCombo)
    {
        _comboVector.push_back(newCombo);
    }

}

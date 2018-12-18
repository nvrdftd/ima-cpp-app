#pragma once

#include <vector>
#include "Combo.h"

namespace ima {

    class ComboArray {
        public:
            unsigned int getNumOfCombos() const;
            const Combo &getCombo(unsigned int) const;
            void addCombo(const Combo &);
        private:
            std::vector<Combo> _comboVector;
    };

}

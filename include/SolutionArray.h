#pragma once

#include "Solution.h"

namespace ima {

    class SolutionArray {
        public:
            void add(const Solution &);
            const Solution &get(unsigned int) const;
            unsigned int getNumOfSols() const;
        private:
            std::vector<Solution> _solVec;
    };

}

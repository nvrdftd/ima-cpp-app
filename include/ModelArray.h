#pragma once

#define IL_STD
#include <vector>
#include "ilcplex/ilocplex.h"

namespace ima {
    class ModelArray {
        public:
            void add(const IloModel &model);
            const IloModel &get(unsigned int index) const;
            unsigned int getNumOfModels() const;
        private:
            std::vector<IloModel> _modelVec;
    };
}

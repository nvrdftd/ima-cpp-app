#pragma once

#include <vector>
#include "ModelArray.h"

namespace ima {
    void ModelArray::add(const IloModel &model)
    {
        _modelVec.push_back(model);
    }

    const IloModel &ModelArray::get(unsigned int index) const
    {
        return _modelVec.at(index);
    }

    unsigned int ModelArray::getNumOfModels() const
    {
        return _modelVec.size();
    }
}

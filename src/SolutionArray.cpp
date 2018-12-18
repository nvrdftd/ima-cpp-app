#include "Solution.h"
#include "SolutionArray.h"

namespace ima {

    void SolutionArray::add(const Solution &sol)
    {
        _solVec.push_back(sol);
    }

    const Solution &SolutionArray::get(unsigned int index) const
    {
        return _solVec.at(index);
    }

    unsigned int SolutionArray::getNumOfSols() const
    {
        return _solVec.size();
    }

}

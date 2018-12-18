#include "AnyTwoInfo.h"
#include "InfoMatrix.h"
#include "RelationInfo.h"

namespace ima {

    bool RelationInfo::isEmpty()
    {
        return _relMap.empty();
    }

    InfoMatrix<AnyTwoInfo> &RelationInfo::getAnyTwoInfoMatrix(unsigned int k1, unsigned int k2)
    {
        for (auto iter = _relMap.begin(); iter != _relMap.end(); ++iter)
        {
            const std::pair<unsigned int, unsigned int> &keyPair = iter->first;
            if (keyPair.first == k1 && keyPair.second == k2) {
                return iter->second;
            }
        }
    }

    void RelationInfo::setAnyTwoInfoMatrix(unsigned int k1, unsigned int k2, const InfoMatrix<AnyTwoInfo> &infoMatrix)
    {
        _relMap.insert(std::make_pair(std::make_pair(k1, k2), infoMatrix));
    }

}

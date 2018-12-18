#pragma once

#include <map>
#include "AnyTwoInfo.h"
#include "InfoMatrix.h"

namespace ima {

    class RelationInfo {
        public:
            bool isEmpty();
            InfoMatrix<AnyTwoInfo> &getAnyTwoInfoMatrix(unsigned int, unsigned int);
            void setAnyTwoInfoMatrix(unsigned int, unsigned int, const InfoMatrix<AnyTwoInfo> &);
        private:
            std::map<std::pair<unsigned int, unsigned int>, InfoMatrix<AnyTwoInfo> > _relMap;
    };

}

#include <string>
#include "AnyTwoInfo.h"

namespace ima {

    AnyTwoInfo::AnyTwoInfo(): _duraVal(0), _distVal(0) {}

    AnyTwoInfo::AnyTwoInfo(
        unsigned int duraVal,
        std::string duraText,
        unsigned int distVal,
        std::string distText
    ): _duraVal(duraVal), _duraText(duraText), _distVal(distVal), _distText(distText) {}

    unsigned int AnyTwoInfo::getDistVal()
    {
        return _distVal;
    }

    std::string &AnyTwoInfo::getDistText()
    {
        return _distText;
    }

    unsigned int AnyTwoInfo::getDuraVal()
    {
        return _duraVal;
    }

    std::string &AnyTwoInfo::getDuraText()
    {
        return _duraText;
    }

}

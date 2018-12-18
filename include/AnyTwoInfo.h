#pragma once

#include <string>

namespace ima {

    class AnyTwoInfo {
        public:
            AnyTwoInfo();
            AnyTwoInfo(unsigned int, std::string , unsigned int, std::string );
            AnyTwoInfo(const AnyTwoInfo &) = default;
            AnyTwoInfo(AnyTwoInfo &&) = default;
            AnyTwoInfo &operator=(const AnyTwoInfo &) = default;
            AnyTwoInfo &operator=(AnyTwoInfo &&) = default;
            unsigned int getDistVal();
            std::string &getDistText();
            unsigned int getDuraVal();
            std::string &getDuraText();
        private:
            unsigned int _duraVal;
            std::string _duraText;
            unsigned int _distVal;
            std::string _distText;
    };

}

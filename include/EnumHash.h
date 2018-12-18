#pragma once

namespace ima {

    struct EnumHash {

        template <typename T>
        unsigned int operator()(T t) const
        {
            return static_cast<unsigned int>(t);
        }
        
    };

}

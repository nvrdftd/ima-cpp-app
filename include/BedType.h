#pragma once
#define NUM_BED_TYPES 5
namespace ima {

    enum struct BedType {
        Single = 0,
        Twin = 1,
        Double = 2,
        Queen = 3,
        King = 4,
        Any = 5
    };

}

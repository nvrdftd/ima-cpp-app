# add libraries to be built
add_library(Ima STATIC
    AnyTwoInfo.cpp
    AmenityConstraint.cpp
    BedTypeConstraint.cpp
    BudgetConstraint.cpp
    BaseInfo.cpp
    Combo.cpp
    ComboArray.cpp
    Constraint.cpp
    ConstraintSet.cpp
    Coordinates.cpp
    Date.cpp
    DateConstraint.cpp
    DestConstraint.cpp
    DHDistConstraint.cpp
    DHDuraConstraint.cpp
    GeoInfo.cpp
    GuestNumConstraint.cpp
    HHDistConstraint.cpp
    HHDuraConstraint.cpp
    Hotel.cpp
    HotelArray.cpp
    HotelRoom.cpp
    IfThenConstraint.cpp
    ImaClient.cpp
    ImaCore.cpp
    JourneyInfo.cpp
    ModelArray.cpp
    RelationInfo.cpp
    RequestInfo.cpp
    Solution.cpp
    SolutionArray.cpp
    SLvlConstraint.cpp
    TripInfo.cpp
)

target_link_libraries(Ima cpprestsdk::cpprest)

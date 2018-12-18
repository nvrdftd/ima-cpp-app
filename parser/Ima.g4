grammar Ima;

import LexerRules;

journey
    : journeySpec+ trip+
    ;

trip
    : TRIP SEMICOLON tripSpec+
    ;

journeySpec
    : DATE THROUGH # specStartDate
    | commonSpec # specGlobal
    ;

tripSpec
    : THROUGH DATE # specEndDate
    | GOTO STRING # specTripDest
    | commonSpec # specLocal
    ;

commonSpec
    : BUDGET range # specBudget
    | SERVICELEVEL range # specSerLvl
    | GUESTNUM range # specGuestNum
    | BEDTYPE bedType (',' bedType)* # specBedType
    | AMENITY amenity (',' amenity)* # specAmenity
    | (HHDIST|HHDURA) (BY travelMode)? range # specHH
    | (DHDIST|DHDURA) TO STRING (BY travelMode)? range # specDH
    | IF commonSpec THEN commonSpec # specIfThen
    ;

range
    : NUM THROUGH NUM unit?
    ;

unit
    : M
    | MIN
    ;

travelMode
    : WALKING
    | TRANSIT
    | DRIVING
    | BICYCLING
    ;

bedType
    : TWIN
    | SINGLE
    | DOUBLE
    | QUEEN
    | KING
    ;

amenity
    : VENDINGMACHINES
    | FREEWIFI
    | PARKING
    | SWIMMINGPOOL
    | LAUNDRYSERVICE
    | LAUNDRYROOM
    | NONSMOKINGROOM
    | SAFEDEPOSITBOX
    | GYM
    ;

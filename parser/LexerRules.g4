lexer grammar LexerRules;

WS
    : [ \r\n\t]+ -> skip
    ;

fragment MONTH
    : [Jj] [Aa] [Nn] ([Uu] [Aa] [Rr] [Yy])?
    | [Ff] [Ee] [Bb] ([Rr] [Uu] [Aa] [Rr] [Yy])?
    | [Mm] [Aa] [Rr] ([Cc] [Hh])?
    | [Aa] [Pp] [Rr] ([Ii] [Ll])?
    | [Mm] [Aa] [Yy]
    | [Jj] [Uu] [Nn] [Ee]?
    | [Jj] [Uu] [Ll] [Yy]?
    | [Aa] [Uu] [Gg] ([Uu] [Ss] [Tt])?
    | [Ss] [Ee] [Pp] ([Tt] [Ee] [Mm] [Bb] [Ee] [Rr])?
    | [Oo] [Cc] [Tt] ([Oo] [Bb] [Ee] [Rr])?
    | [Nn] [Oo] [Vv] ([Ee] [Mm] [Bb] [Ee] [Rr])?
    | [Dd] [Ee] [Cc] ([Ee] [Mm] [Bb] [Ee] [Rr])?
    ;

fragment YEAR
    : DIGIT DIGIT DIGIT DIGIT
    ;

fragment DAY
    : DIGIT DIGIT?
    ;

DATE
    : MONTH ' ' DAY (', ' YEAR)?
    ;

NUM
    : DIGIT+ ('.' DIGIT+)*
    ;

STRING
    : '"' .*? '"'
    ;

fragment LETTER
    : [a-zA-Z]
    ;

fragment DIGIT
    : [0-9]
    ;

TRIP
    : 'trip'
    ;

THROUGH
    : '~'
    ;

SEMICOLON
    : ':'
    ;

MIN
    : 'min'
    ;

M
    : 'm'
    ;

IF
    : 'if'
    ;

THEN
    : 'then'
    ;

BY
    : 'by'
    ;

TO
    : 'to'
    ;

WALKING
    : 'walking'
    ;

TRANSIT
    : 'transit'
    ;

DRIVING
    : 'driving'
    ;

BICYCLING
    : 'bicycling'
    ;

GOTO
    : 'goto'
    ;

BUDGET
    : 'budget'
    ;

HHDIST
    : 'hhdist'
    ;

HHDURA
    : 'hhdura'
    ;

DHDIST
    : 'dhdist'
    ;

DHDURA
    : 'dhdura'
    ;

BEDTYPE
    : 'bedtype'
    ;

AMENITY
    : 'amenity'
    ;

SERVICELEVEL
    : 'servicelevel'
    ;

GUESTNUM
    : 'guestnum'
    ;

TWIN
    : 'twin'
    ;

DOUBLE
    : 'double'
    ;

SINGLE
    : 'single'
    ;

QUEEN
    : 'queen'
    ;

KING
    : 'king'
    ;

VENDINGMACHINES
    : 'vending machines'
    ;

FREEWIFI
    : 'free wifi'
    ;

PARKING
    : 'parking'
    ;

SWIMMINGPOOL
    : 'swimming pool'
    ;

LAUNDRYSERVICE
    : 'laundry service'
    ;

LAUNDRYROOM
    : 'laundry room'
    ;

NONSMOKINGROOM
    : 'non-smoking room'
    ;

SAFEDEPOSITBOX
    : 'safe deposit box'
    ;

GYM
    : 'gym'
    ;

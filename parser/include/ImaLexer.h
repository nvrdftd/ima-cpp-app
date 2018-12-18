
// Generated from Ima.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"


namespace antlrcpp {


class  ImaLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, WS = 2, DATE = 3, NUM = 4, STRING = 5, TRIP = 6, THROUGH = 7, 
    SEMICOLON = 8, MIN = 9, M = 10, IF = 11, THEN = 12, BY = 13, TO = 14, 
    WALKING = 15, TRANSIT = 16, DRIVING = 17, BICYCLING = 18, GOTO = 19, 
    BUDGET = 20, HHDIST = 21, HHDURA = 22, DHDIST = 23, DHDURA = 24, BEDTYPE = 25, 
    AMENITY = 26, SERVICELEVEL = 27, GUESTNUM = 28, TWIN = 29, DOUBLE = 30, 
    SINGLE = 31, QUEEN = 32, KING = 33, VENDINGMACHINES = 34, FREEWIFI = 35, 
    PARKING = 36, SWIMMINGPOOL = 37, LAUNDRYSERVICE = 38, LAUNDRYROOM = 39, 
    NONSMOKINGROOM = 40, SAFEDEPOSITBOX = 41, GYM = 42
  };

  ImaLexer(antlr4::CharStream *input);
  ~ImaLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace antlrcpp

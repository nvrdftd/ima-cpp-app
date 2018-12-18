
// Generated from Ima.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"


namespace antlrcpp {


class  ImaParser : public antlr4::Parser {
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

  enum {
    RuleJourney = 0, RuleTrip = 1, RuleJourneySpec = 2, RuleTripSpec = 3, 
    RuleCommonSpec = 4, RuleRange = 5, RuleUnit = 6, RuleTravelMode = 7, 
    RuleBedType = 8, RuleAmenity = 9
  };

  ImaParser(antlr4::TokenStream *input);
  ~ImaParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class JourneyContext;
  class TripContext;
  class JourneySpecContext;
  class TripSpecContext;
  class CommonSpecContext;
  class RangeContext;
  class UnitContext;
  class TravelModeContext;
  class BedTypeContext;
  class AmenityContext; 

  class  JourneyContext : public antlr4::ParserRuleContext {
  public:
    JourneyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<JourneySpecContext *> journeySpec();
    JourneySpecContext* journeySpec(size_t i);
    std::vector<TripContext *> trip();
    TripContext* trip(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  JourneyContext* journey();

  class  TripContext : public antlr4::ParserRuleContext {
  public:
    TripContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRIP();
    antlr4::tree::TerminalNode *SEMICOLON();
    std::vector<TripSpecContext *> tripSpec();
    TripSpecContext* tripSpec(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TripContext* trip();

  class  JourneySpecContext : public antlr4::ParserRuleContext {
  public:
    JourneySpecContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    JourneySpecContext() : antlr4::ParserRuleContext() { }
    void copyFrom(JourneySpecContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SpecStartDateContext : public JourneySpecContext {
  public:
    SpecStartDateContext(JourneySpecContext *ctx);

    antlr4::tree::TerminalNode *DATE();
    antlr4::tree::TerminalNode *THROUGH();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  SpecGlobalContext : public JourneySpecContext {
  public:
    SpecGlobalContext(JourneySpecContext *ctx);

    CommonSpecContext *commonSpec();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  JourneySpecContext* journeySpec();

  class  TripSpecContext : public antlr4::ParserRuleContext {
  public:
    TripSpecContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TripSpecContext() : antlr4::ParserRuleContext() { }
    void copyFrom(TripSpecContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SpecEndDateContext : public TripSpecContext {
  public:
    SpecEndDateContext(TripSpecContext *ctx);

    antlr4::tree::TerminalNode *THROUGH();
    antlr4::tree::TerminalNode *DATE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  SpecLocalContext : public TripSpecContext {
  public:
    SpecLocalContext(TripSpecContext *ctx);

    CommonSpecContext *commonSpec();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  SpecTripDestContext : public TripSpecContext {
  public:
    SpecTripDestContext(TripSpecContext *ctx);

    antlr4::tree::TerminalNode *GOTO();
    antlr4::tree::TerminalNode *STRING();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  TripSpecContext* tripSpec();

  class  CommonSpecContext : public antlr4::ParserRuleContext {
  public:
    CommonSpecContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    CommonSpecContext() : antlr4::ParserRuleContext() { }
    void copyFrom(CommonSpecContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SpecIfThenContext : public CommonSpecContext {
  public:
    SpecIfThenContext(CommonSpecContext *ctx);

    antlr4::tree::TerminalNode *IF();
    std::vector<CommonSpecContext *> commonSpec();
    CommonSpecContext* commonSpec(size_t i);
    antlr4::tree::TerminalNode *THEN();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  SpecAmenityContext : public CommonSpecContext {
  public:
    SpecAmenityContext(CommonSpecContext *ctx);

    antlr4::tree::TerminalNode *AMENITY();
    std::vector<AmenityContext *> amenity();
    AmenityContext* amenity(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  SpecGuestNumContext : public CommonSpecContext {
  public:
    SpecGuestNumContext(CommonSpecContext *ctx);

    antlr4::tree::TerminalNode *GUESTNUM();
    RangeContext *range();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  SpecSerLvlContext : public CommonSpecContext {
  public:
    SpecSerLvlContext(CommonSpecContext *ctx);

    antlr4::tree::TerminalNode *SERVICELEVEL();
    RangeContext *range();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  SpecDHContext : public CommonSpecContext {
  public:
    SpecDHContext(CommonSpecContext *ctx);

    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *STRING();
    RangeContext *range();
    antlr4::tree::TerminalNode *DHDIST();
    antlr4::tree::TerminalNode *DHDURA();
    antlr4::tree::TerminalNode *BY();
    TravelModeContext *travelMode();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  SpecBudgetContext : public CommonSpecContext {
  public:
    SpecBudgetContext(CommonSpecContext *ctx);

    antlr4::tree::TerminalNode *BUDGET();
    RangeContext *range();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  SpecHHContext : public CommonSpecContext {
  public:
    SpecHHContext(CommonSpecContext *ctx);

    RangeContext *range();
    antlr4::tree::TerminalNode *HHDIST();
    antlr4::tree::TerminalNode *HHDURA();
    antlr4::tree::TerminalNode *BY();
    TravelModeContext *travelMode();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  SpecBedTypeContext : public CommonSpecContext {
  public:
    SpecBedTypeContext(CommonSpecContext *ctx);

    antlr4::tree::TerminalNode *BEDTYPE();
    std::vector<BedTypeContext *> bedType();
    BedTypeContext* bedType(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  CommonSpecContext* commonSpec();

  class  RangeContext : public antlr4::ParserRuleContext {
  public:
    RangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NUM();
    antlr4::tree::TerminalNode* NUM(size_t i);
    antlr4::tree::TerminalNode *THROUGH();
    UnitContext *unit();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RangeContext* range();

  class  UnitContext : public antlr4::ParserRuleContext {
  public:
    UnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *M();
    antlr4::tree::TerminalNode *MIN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  UnitContext* unit();

  class  TravelModeContext : public antlr4::ParserRuleContext {
  public:
    TravelModeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WALKING();
    antlr4::tree::TerminalNode *TRANSIT();
    antlr4::tree::TerminalNode *DRIVING();
    antlr4::tree::TerminalNode *BICYCLING();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TravelModeContext* travelMode();

  class  BedTypeContext : public antlr4::ParserRuleContext {
  public:
    BedTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TWIN();
    antlr4::tree::TerminalNode *SINGLE();
    antlr4::tree::TerminalNode *DOUBLE();
    antlr4::tree::TerminalNode *QUEEN();
    antlr4::tree::TerminalNode *KING();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BedTypeContext* bedType();

  class  AmenityContext : public antlr4::ParserRuleContext {
  public:
    AmenityContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VENDINGMACHINES();
    antlr4::tree::TerminalNode *FREEWIFI();
    antlr4::tree::TerminalNode *PARKING();
    antlr4::tree::TerminalNode *SWIMMINGPOOL();
    antlr4::tree::TerminalNode *LAUNDRYSERVICE();
    antlr4::tree::TerminalNode *LAUNDRYROOM();
    antlr4::tree::TerminalNode *NONSMOKINGROOM();
    antlr4::tree::TerminalNode *SAFEDEPOSITBOX();
    antlr4::tree::TerminalNode *GYM();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AmenityContext* amenity();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace antlrcpp

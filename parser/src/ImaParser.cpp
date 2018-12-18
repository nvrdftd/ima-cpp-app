
// Generated from Ima.g4 by ANTLR 4.7.1


#include "ImaListener.h"

#include "ImaParser.h"


using namespace antlrcpp;
using namespace antlrcpp;
using namespace antlr4;

ImaParser::ImaParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ImaParser::~ImaParser() {
  delete _interpreter;
}

std::string ImaParser::getGrammarFileName() const {
  return "Ima.g4";
}

const std::vector<std::string>& ImaParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ImaParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- JourneyContext ------------------------------------------------------------------

ImaParser::JourneyContext::JourneyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ImaParser::JourneySpecContext *> ImaParser::JourneyContext::journeySpec() {
  return getRuleContexts<ImaParser::JourneySpecContext>();
}

ImaParser::JourneySpecContext* ImaParser::JourneyContext::journeySpec(size_t i) {
  return getRuleContext<ImaParser::JourneySpecContext>(i);
}

std::vector<ImaParser::TripContext *> ImaParser::JourneyContext::trip() {
  return getRuleContexts<ImaParser::TripContext>();
}

ImaParser::TripContext* ImaParser::JourneyContext::trip(size_t i) {
  return getRuleContext<ImaParser::TripContext>(i);
}


size_t ImaParser::JourneyContext::getRuleIndex() const {
  return ImaParser::RuleJourney;
}

void ImaParser::JourneyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJourney(this);
}

void ImaParser::JourneyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJourney(this);
}

ImaParser::JourneyContext* ImaParser::journey() {
  JourneyContext *_localctx = _tracker.createInstance<JourneyContext>(_ctx, getState());
  enterRule(_localctx, 0, ImaParser::RuleJourney);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(21); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(20);
      journeySpec();
      setState(23); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ImaParser::DATE)
      | (1ULL << ImaParser::IF)
      | (1ULL << ImaParser::BUDGET)
      | (1ULL << ImaParser::HHDIST)
      | (1ULL << ImaParser::HHDURA)
      | (1ULL << ImaParser::DHDIST)
      | (1ULL << ImaParser::DHDURA)
      | (1ULL << ImaParser::BEDTYPE)
      | (1ULL << ImaParser::AMENITY)
      | (1ULL << ImaParser::SERVICELEVEL)
      | (1ULL << ImaParser::GUESTNUM))) != 0));
    setState(26); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(25);
      trip();
      setState(28); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == ImaParser::TRIP);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TripContext ------------------------------------------------------------------

ImaParser::TripContext::TripContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImaParser::TripContext::TRIP() {
  return getToken(ImaParser::TRIP, 0);
}

tree::TerminalNode* ImaParser::TripContext::SEMICOLON() {
  return getToken(ImaParser::SEMICOLON, 0);
}

std::vector<ImaParser::TripSpecContext *> ImaParser::TripContext::tripSpec() {
  return getRuleContexts<ImaParser::TripSpecContext>();
}

ImaParser::TripSpecContext* ImaParser::TripContext::tripSpec(size_t i) {
  return getRuleContext<ImaParser::TripSpecContext>(i);
}


size_t ImaParser::TripContext::getRuleIndex() const {
  return ImaParser::RuleTrip;
}

void ImaParser::TripContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTrip(this);
}

void ImaParser::TripContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTrip(this);
}

ImaParser::TripContext* ImaParser::trip() {
  TripContext *_localctx = _tracker.createInstance<TripContext>(_ctx, getState());
  enterRule(_localctx, 2, ImaParser::RuleTrip);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(30);
    match(ImaParser::TRIP);
    setState(31);
    match(ImaParser::SEMICOLON);
    setState(33); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(32);
      tripSpec();
      setState(35); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ImaParser::THROUGH)
      | (1ULL << ImaParser::IF)
      | (1ULL << ImaParser::GOTO)
      | (1ULL << ImaParser::BUDGET)
      | (1ULL << ImaParser::HHDIST)
      | (1ULL << ImaParser::HHDURA)
      | (1ULL << ImaParser::DHDIST)
      | (1ULL << ImaParser::DHDURA)
      | (1ULL << ImaParser::BEDTYPE)
      | (1ULL << ImaParser::AMENITY)
      | (1ULL << ImaParser::SERVICELEVEL)
      | (1ULL << ImaParser::GUESTNUM))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- JourneySpecContext ------------------------------------------------------------------

ImaParser::JourneySpecContext::JourneySpecContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ImaParser::JourneySpecContext::getRuleIndex() const {
  return ImaParser::RuleJourneySpec;
}

void ImaParser::JourneySpecContext::copyFrom(JourneySpecContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SpecStartDateContext ------------------------------------------------------------------

tree::TerminalNode* ImaParser::SpecStartDateContext::DATE() {
  return getToken(ImaParser::DATE, 0);
}

tree::TerminalNode* ImaParser::SpecStartDateContext::THROUGH() {
  return getToken(ImaParser::THROUGH, 0);
}

ImaParser::SpecStartDateContext::SpecStartDateContext(JourneySpecContext *ctx) { copyFrom(ctx); }

void ImaParser::SpecStartDateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSpecStartDate(this);
}
void ImaParser::SpecStartDateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSpecStartDate(this);
}
//----------------- SpecGlobalContext ------------------------------------------------------------------

ImaParser::CommonSpecContext* ImaParser::SpecGlobalContext::commonSpec() {
  return getRuleContext<ImaParser::CommonSpecContext>(0);
}

ImaParser::SpecGlobalContext::SpecGlobalContext(JourneySpecContext *ctx) { copyFrom(ctx); }

void ImaParser::SpecGlobalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSpecGlobal(this);
}
void ImaParser::SpecGlobalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSpecGlobal(this);
}
ImaParser::JourneySpecContext* ImaParser::journeySpec() {
  JourneySpecContext *_localctx = _tracker.createInstance<JourneySpecContext>(_ctx, getState());
  enterRule(_localctx, 4, ImaParser::RuleJourneySpec);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(40);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ImaParser::DATE: {
        _localctx = dynamic_cast<JourneySpecContext *>(_tracker.createInstance<ImaParser::SpecStartDateContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(37);
        match(ImaParser::DATE);
        setState(38);
        match(ImaParser::THROUGH);
        break;
      }

      case ImaParser::IF:
      case ImaParser::BUDGET:
      case ImaParser::HHDIST:
      case ImaParser::HHDURA:
      case ImaParser::DHDIST:
      case ImaParser::DHDURA:
      case ImaParser::BEDTYPE:
      case ImaParser::AMENITY:
      case ImaParser::SERVICELEVEL:
      case ImaParser::GUESTNUM: {
        _localctx = dynamic_cast<JourneySpecContext *>(_tracker.createInstance<ImaParser::SpecGlobalContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(39);
        commonSpec();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TripSpecContext ------------------------------------------------------------------

ImaParser::TripSpecContext::TripSpecContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ImaParser::TripSpecContext::getRuleIndex() const {
  return ImaParser::RuleTripSpec;
}

void ImaParser::TripSpecContext::copyFrom(TripSpecContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SpecEndDateContext ------------------------------------------------------------------

tree::TerminalNode* ImaParser::SpecEndDateContext::THROUGH() {
  return getToken(ImaParser::THROUGH, 0);
}

tree::TerminalNode* ImaParser::SpecEndDateContext::DATE() {
  return getToken(ImaParser::DATE, 0);
}

ImaParser::SpecEndDateContext::SpecEndDateContext(TripSpecContext *ctx) { copyFrom(ctx); }

void ImaParser::SpecEndDateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSpecEndDate(this);
}
void ImaParser::SpecEndDateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSpecEndDate(this);
}
//----------------- SpecLocalContext ------------------------------------------------------------------

ImaParser::CommonSpecContext* ImaParser::SpecLocalContext::commonSpec() {
  return getRuleContext<ImaParser::CommonSpecContext>(0);
}

ImaParser::SpecLocalContext::SpecLocalContext(TripSpecContext *ctx) { copyFrom(ctx); }

void ImaParser::SpecLocalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSpecLocal(this);
}
void ImaParser::SpecLocalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSpecLocal(this);
}
//----------------- SpecTripDestContext ------------------------------------------------------------------

tree::TerminalNode* ImaParser::SpecTripDestContext::GOTO() {
  return getToken(ImaParser::GOTO, 0);
}

tree::TerminalNode* ImaParser::SpecTripDestContext::STRING() {
  return getToken(ImaParser::STRING, 0);
}

ImaParser::SpecTripDestContext::SpecTripDestContext(TripSpecContext *ctx) { copyFrom(ctx); }

void ImaParser::SpecTripDestContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSpecTripDest(this);
}
void ImaParser::SpecTripDestContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSpecTripDest(this);
}
ImaParser::TripSpecContext* ImaParser::tripSpec() {
  TripSpecContext *_localctx = _tracker.createInstance<TripSpecContext>(_ctx, getState());
  enterRule(_localctx, 6, ImaParser::RuleTripSpec);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(47);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ImaParser::THROUGH: {
        _localctx = dynamic_cast<TripSpecContext *>(_tracker.createInstance<ImaParser::SpecEndDateContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(42);
        match(ImaParser::THROUGH);
        setState(43);
        match(ImaParser::DATE);
        break;
      }

      case ImaParser::GOTO: {
        _localctx = dynamic_cast<TripSpecContext *>(_tracker.createInstance<ImaParser::SpecTripDestContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(44);
        match(ImaParser::GOTO);
        setState(45);
        match(ImaParser::STRING);
        break;
      }

      case ImaParser::IF:
      case ImaParser::BUDGET:
      case ImaParser::HHDIST:
      case ImaParser::HHDURA:
      case ImaParser::DHDIST:
      case ImaParser::DHDURA:
      case ImaParser::BEDTYPE:
      case ImaParser::AMENITY:
      case ImaParser::SERVICELEVEL:
      case ImaParser::GUESTNUM: {
        _localctx = dynamic_cast<TripSpecContext *>(_tracker.createInstance<ImaParser::SpecLocalContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(46);
        commonSpec();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommonSpecContext ------------------------------------------------------------------

ImaParser::CommonSpecContext::CommonSpecContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ImaParser::CommonSpecContext::getRuleIndex() const {
  return ImaParser::RuleCommonSpec;
}

void ImaParser::CommonSpecContext::copyFrom(CommonSpecContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SpecIfThenContext ------------------------------------------------------------------

tree::TerminalNode* ImaParser::SpecIfThenContext::IF() {
  return getToken(ImaParser::IF, 0);
}

std::vector<ImaParser::CommonSpecContext *> ImaParser::SpecIfThenContext::commonSpec() {
  return getRuleContexts<ImaParser::CommonSpecContext>();
}

ImaParser::CommonSpecContext* ImaParser::SpecIfThenContext::commonSpec(size_t i) {
  return getRuleContext<ImaParser::CommonSpecContext>(i);
}

tree::TerminalNode* ImaParser::SpecIfThenContext::THEN() {
  return getToken(ImaParser::THEN, 0);
}

ImaParser::SpecIfThenContext::SpecIfThenContext(CommonSpecContext *ctx) { copyFrom(ctx); }

void ImaParser::SpecIfThenContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSpecIfThen(this);
}
void ImaParser::SpecIfThenContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSpecIfThen(this);
}
//----------------- SpecAmenityContext ------------------------------------------------------------------

tree::TerminalNode* ImaParser::SpecAmenityContext::AMENITY() {
  return getToken(ImaParser::AMENITY, 0);
}

std::vector<ImaParser::AmenityContext *> ImaParser::SpecAmenityContext::amenity() {
  return getRuleContexts<ImaParser::AmenityContext>();
}

ImaParser::AmenityContext* ImaParser::SpecAmenityContext::amenity(size_t i) {
  return getRuleContext<ImaParser::AmenityContext>(i);
}

ImaParser::SpecAmenityContext::SpecAmenityContext(CommonSpecContext *ctx) { copyFrom(ctx); }

void ImaParser::SpecAmenityContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSpecAmenity(this);
}
void ImaParser::SpecAmenityContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSpecAmenity(this);
}
//----------------- SpecGuestNumContext ------------------------------------------------------------------

tree::TerminalNode* ImaParser::SpecGuestNumContext::GUESTNUM() {
  return getToken(ImaParser::GUESTNUM, 0);
}

ImaParser::RangeContext* ImaParser::SpecGuestNumContext::range() {
  return getRuleContext<ImaParser::RangeContext>(0);
}

ImaParser::SpecGuestNumContext::SpecGuestNumContext(CommonSpecContext *ctx) { copyFrom(ctx); }

void ImaParser::SpecGuestNumContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSpecGuestNum(this);
}
void ImaParser::SpecGuestNumContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSpecGuestNum(this);
}
//----------------- SpecSerLvlContext ------------------------------------------------------------------

tree::TerminalNode* ImaParser::SpecSerLvlContext::SERVICELEVEL() {
  return getToken(ImaParser::SERVICELEVEL, 0);
}

ImaParser::RangeContext* ImaParser::SpecSerLvlContext::range() {
  return getRuleContext<ImaParser::RangeContext>(0);
}

ImaParser::SpecSerLvlContext::SpecSerLvlContext(CommonSpecContext *ctx) { copyFrom(ctx); }

void ImaParser::SpecSerLvlContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSpecSerLvl(this);
}
void ImaParser::SpecSerLvlContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSpecSerLvl(this);
}
//----------------- SpecDHContext ------------------------------------------------------------------

tree::TerminalNode* ImaParser::SpecDHContext::TO() {
  return getToken(ImaParser::TO, 0);
}

tree::TerminalNode* ImaParser::SpecDHContext::STRING() {
  return getToken(ImaParser::STRING, 0);
}

ImaParser::RangeContext* ImaParser::SpecDHContext::range() {
  return getRuleContext<ImaParser::RangeContext>(0);
}

tree::TerminalNode* ImaParser::SpecDHContext::DHDIST() {
  return getToken(ImaParser::DHDIST, 0);
}

tree::TerminalNode* ImaParser::SpecDHContext::DHDURA() {
  return getToken(ImaParser::DHDURA, 0);
}

tree::TerminalNode* ImaParser::SpecDHContext::BY() {
  return getToken(ImaParser::BY, 0);
}

ImaParser::TravelModeContext* ImaParser::SpecDHContext::travelMode() {
  return getRuleContext<ImaParser::TravelModeContext>(0);
}

ImaParser::SpecDHContext::SpecDHContext(CommonSpecContext *ctx) { copyFrom(ctx); }

void ImaParser::SpecDHContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSpecDH(this);
}
void ImaParser::SpecDHContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSpecDH(this);
}
//----------------- SpecBudgetContext ------------------------------------------------------------------

tree::TerminalNode* ImaParser::SpecBudgetContext::BUDGET() {
  return getToken(ImaParser::BUDGET, 0);
}

ImaParser::RangeContext* ImaParser::SpecBudgetContext::range() {
  return getRuleContext<ImaParser::RangeContext>(0);
}

ImaParser::SpecBudgetContext::SpecBudgetContext(CommonSpecContext *ctx) { copyFrom(ctx); }

void ImaParser::SpecBudgetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSpecBudget(this);
}
void ImaParser::SpecBudgetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSpecBudget(this);
}
//----------------- SpecHHContext ------------------------------------------------------------------

ImaParser::RangeContext* ImaParser::SpecHHContext::range() {
  return getRuleContext<ImaParser::RangeContext>(0);
}

tree::TerminalNode* ImaParser::SpecHHContext::HHDIST() {
  return getToken(ImaParser::HHDIST, 0);
}

tree::TerminalNode* ImaParser::SpecHHContext::HHDURA() {
  return getToken(ImaParser::HHDURA, 0);
}

tree::TerminalNode* ImaParser::SpecHHContext::BY() {
  return getToken(ImaParser::BY, 0);
}

ImaParser::TravelModeContext* ImaParser::SpecHHContext::travelMode() {
  return getRuleContext<ImaParser::TravelModeContext>(0);
}

ImaParser::SpecHHContext::SpecHHContext(CommonSpecContext *ctx) { copyFrom(ctx); }

void ImaParser::SpecHHContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSpecHH(this);
}
void ImaParser::SpecHHContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSpecHH(this);
}
//----------------- SpecBedTypeContext ------------------------------------------------------------------

tree::TerminalNode* ImaParser::SpecBedTypeContext::BEDTYPE() {
  return getToken(ImaParser::BEDTYPE, 0);
}

std::vector<ImaParser::BedTypeContext *> ImaParser::SpecBedTypeContext::bedType() {
  return getRuleContexts<ImaParser::BedTypeContext>();
}

ImaParser::BedTypeContext* ImaParser::SpecBedTypeContext::bedType(size_t i) {
  return getRuleContext<ImaParser::BedTypeContext>(i);
}

ImaParser::SpecBedTypeContext::SpecBedTypeContext(CommonSpecContext *ctx) { copyFrom(ctx); }

void ImaParser::SpecBedTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSpecBedType(this);
}
void ImaParser::SpecBedTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSpecBedType(this);
}
ImaParser::CommonSpecContext* ImaParser::commonSpec() {
  CommonSpecContext *_localctx = _tracker.createInstance<CommonSpecContext>(_ctx, getState());
  enterRule(_localctx, 8, ImaParser::RuleCommonSpec);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(92);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ImaParser::BUDGET: {
        _localctx = dynamic_cast<CommonSpecContext *>(_tracker.createInstance<ImaParser::SpecBudgetContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(49);
        match(ImaParser::BUDGET);
        setState(50);
        range();
        break;
      }

      case ImaParser::SERVICELEVEL: {
        _localctx = dynamic_cast<CommonSpecContext *>(_tracker.createInstance<ImaParser::SpecSerLvlContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(51);
        match(ImaParser::SERVICELEVEL);
        setState(52);
        range();
        break;
      }

      case ImaParser::GUESTNUM: {
        _localctx = dynamic_cast<CommonSpecContext *>(_tracker.createInstance<ImaParser::SpecGuestNumContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(53);
        match(ImaParser::GUESTNUM);
        setState(54);
        range();
        break;
      }

      case ImaParser::BEDTYPE: {
        _localctx = dynamic_cast<CommonSpecContext *>(_tracker.createInstance<ImaParser::SpecBedTypeContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(55);
        match(ImaParser::BEDTYPE);
        setState(56);
        bedType();
        setState(61);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == ImaParser::T__0) {
          setState(57);
          match(ImaParser::T__0);
          setState(58);
          bedType();
          setState(63);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case ImaParser::AMENITY: {
        _localctx = dynamic_cast<CommonSpecContext *>(_tracker.createInstance<ImaParser::SpecAmenityContext>(_localctx));
        enterOuterAlt(_localctx, 5);
        setState(64);
        match(ImaParser::AMENITY);
        setState(65);
        amenity();
        setState(70);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == ImaParser::T__0) {
          setState(66);
          match(ImaParser::T__0);
          setState(67);
          amenity();
          setState(72);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case ImaParser::HHDIST:
      case ImaParser::HHDURA: {
        _localctx = dynamic_cast<CommonSpecContext *>(_tracker.createInstance<ImaParser::SpecHHContext>(_localctx));
        enterOuterAlt(_localctx, 6);
        setState(73);
        _la = _input->LA(1);
        if (!(_la == ImaParser::HHDIST

        || _la == ImaParser::HHDURA)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(76);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == ImaParser::BY) {
          setState(74);
          match(ImaParser::BY);
          setState(75);
          travelMode();
        }
        setState(78);
        range();
        break;
      }

      case ImaParser::DHDIST:
      case ImaParser::DHDURA: {
        _localctx = dynamic_cast<CommonSpecContext *>(_tracker.createInstance<ImaParser::SpecDHContext>(_localctx));
        enterOuterAlt(_localctx, 7);
        setState(79);
        _la = _input->LA(1);
        if (!(_la == ImaParser::DHDIST

        || _la == ImaParser::DHDURA)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(80);
        match(ImaParser::TO);
        setState(81);
        match(ImaParser::STRING);
        setState(84);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == ImaParser::BY) {
          setState(82);
          match(ImaParser::BY);
          setState(83);
          travelMode();
        }
        setState(86);
        range();
        break;
      }

      case ImaParser::IF: {
        _localctx = dynamic_cast<CommonSpecContext *>(_tracker.createInstance<ImaParser::SpecIfThenContext>(_localctx));
        enterOuterAlt(_localctx, 8);
        setState(87);
        match(ImaParser::IF);
        setState(88);
        commonSpec();
        setState(89);
        match(ImaParser::THEN);
        setState(90);
        commonSpec();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RangeContext ------------------------------------------------------------------

ImaParser::RangeContext::RangeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> ImaParser::RangeContext::NUM() {
  return getTokens(ImaParser::NUM);
}

tree::TerminalNode* ImaParser::RangeContext::NUM(size_t i) {
  return getToken(ImaParser::NUM, i);
}

tree::TerminalNode* ImaParser::RangeContext::THROUGH() {
  return getToken(ImaParser::THROUGH, 0);
}

ImaParser::UnitContext* ImaParser::RangeContext::unit() {
  return getRuleContext<ImaParser::UnitContext>(0);
}


size_t ImaParser::RangeContext::getRuleIndex() const {
  return ImaParser::RuleRange;
}

void ImaParser::RangeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRange(this);
}

void ImaParser::RangeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRange(this);
}

ImaParser::RangeContext* ImaParser::range() {
  RangeContext *_localctx = _tracker.createInstance<RangeContext>(_ctx, getState());
  enterRule(_localctx, 10, ImaParser::RuleRange);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(94);
    match(ImaParser::NUM);
    setState(95);
    match(ImaParser::THROUGH);
    setState(96);
    match(ImaParser::NUM);
    setState(98);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ImaParser::MIN

    || _la == ImaParser::M) {
      setState(97);
      unit();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnitContext ------------------------------------------------------------------

ImaParser::UnitContext::UnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImaParser::UnitContext::M() {
  return getToken(ImaParser::M, 0);
}

tree::TerminalNode* ImaParser::UnitContext::MIN() {
  return getToken(ImaParser::MIN, 0);
}


size_t ImaParser::UnitContext::getRuleIndex() const {
  return ImaParser::RuleUnit;
}

void ImaParser::UnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnit(this);
}

void ImaParser::UnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnit(this);
}

ImaParser::UnitContext* ImaParser::unit() {
  UnitContext *_localctx = _tracker.createInstance<UnitContext>(_ctx, getState());
  enterRule(_localctx, 12, ImaParser::RuleUnit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(100);
    _la = _input->LA(1);
    if (!(_la == ImaParser::MIN

    || _la == ImaParser::M)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TravelModeContext ------------------------------------------------------------------

ImaParser::TravelModeContext::TravelModeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImaParser::TravelModeContext::WALKING() {
  return getToken(ImaParser::WALKING, 0);
}

tree::TerminalNode* ImaParser::TravelModeContext::TRANSIT() {
  return getToken(ImaParser::TRANSIT, 0);
}

tree::TerminalNode* ImaParser::TravelModeContext::DRIVING() {
  return getToken(ImaParser::DRIVING, 0);
}

tree::TerminalNode* ImaParser::TravelModeContext::BICYCLING() {
  return getToken(ImaParser::BICYCLING, 0);
}


size_t ImaParser::TravelModeContext::getRuleIndex() const {
  return ImaParser::RuleTravelMode;
}

void ImaParser::TravelModeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTravelMode(this);
}

void ImaParser::TravelModeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTravelMode(this);
}

ImaParser::TravelModeContext* ImaParser::travelMode() {
  TravelModeContext *_localctx = _tracker.createInstance<TravelModeContext>(_ctx, getState());
  enterRule(_localctx, 14, ImaParser::RuleTravelMode);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(102);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ImaParser::WALKING)
      | (1ULL << ImaParser::TRANSIT)
      | (1ULL << ImaParser::DRIVING)
      | (1ULL << ImaParser::BICYCLING))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BedTypeContext ------------------------------------------------------------------

ImaParser::BedTypeContext::BedTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImaParser::BedTypeContext::TWIN() {
  return getToken(ImaParser::TWIN, 0);
}

tree::TerminalNode* ImaParser::BedTypeContext::SINGLE() {
  return getToken(ImaParser::SINGLE, 0);
}

tree::TerminalNode* ImaParser::BedTypeContext::DOUBLE() {
  return getToken(ImaParser::DOUBLE, 0);
}

tree::TerminalNode* ImaParser::BedTypeContext::QUEEN() {
  return getToken(ImaParser::QUEEN, 0);
}

tree::TerminalNode* ImaParser::BedTypeContext::KING() {
  return getToken(ImaParser::KING, 0);
}


size_t ImaParser::BedTypeContext::getRuleIndex() const {
  return ImaParser::RuleBedType;
}

void ImaParser::BedTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBedType(this);
}

void ImaParser::BedTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBedType(this);
}

ImaParser::BedTypeContext* ImaParser::bedType() {
  BedTypeContext *_localctx = _tracker.createInstance<BedTypeContext>(_ctx, getState());
  enterRule(_localctx, 16, ImaParser::RuleBedType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(104);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ImaParser::TWIN)
      | (1ULL << ImaParser::DOUBLE)
      | (1ULL << ImaParser::SINGLE)
      | (1ULL << ImaParser::QUEEN)
      | (1ULL << ImaParser::KING))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AmenityContext ------------------------------------------------------------------

ImaParser::AmenityContext::AmenityContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ImaParser::AmenityContext::VENDINGMACHINES() {
  return getToken(ImaParser::VENDINGMACHINES, 0);
}

tree::TerminalNode* ImaParser::AmenityContext::FREEWIFI() {
  return getToken(ImaParser::FREEWIFI, 0);
}

tree::TerminalNode* ImaParser::AmenityContext::PARKING() {
  return getToken(ImaParser::PARKING, 0);
}

tree::TerminalNode* ImaParser::AmenityContext::SWIMMINGPOOL() {
  return getToken(ImaParser::SWIMMINGPOOL, 0);
}

tree::TerminalNode* ImaParser::AmenityContext::LAUNDRYSERVICE() {
  return getToken(ImaParser::LAUNDRYSERVICE, 0);
}

tree::TerminalNode* ImaParser::AmenityContext::LAUNDRYROOM() {
  return getToken(ImaParser::LAUNDRYROOM, 0);
}

tree::TerminalNode* ImaParser::AmenityContext::NONSMOKINGROOM() {
  return getToken(ImaParser::NONSMOKINGROOM, 0);
}

tree::TerminalNode* ImaParser::AmenityContext::SAFEDEPOSITBOX() {
  return getToken(ImaParser::SAFEDEPOSITBOX, 0);
}

tree::TerminalNode* ImaParser::AmenityContext::GYM() {
  return getToken(ImaParser::GYM, 0);
}


size_t ImaParser::AmenityContext::getRuleIndex() const {
  return ImaParser::RuleAmenity;
}

void ImaParser::AmenityContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAmenity(this);
}

void ImaParser::AmenityContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ImaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAmenity(this);
}

ImaParser::AmenityContext* ImaParser::amenity() {
  AmenityContext *_localctx = _tracker.createInstance<AmenityContext>(_ctx, getState());
  enterRule(_localctx, 18, ImaParser::RuleAmenity);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(106);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ImaParser::VENDINGMACHINES)
      | (1ULL << ImaParser::FREEWIFI)
      | (1ULL << ImaParser::PARKING)
      | (1ULL << ImaParser::SWIMMINGPOOL)
      | (1ULL << ImaParser::LAUNDRYSERVICE)
      | (1ULL << ImaParser::LAUNDRYROOM)
      | (1ULL << ImaParser::NONSMOKINGROOM)
      | (1ULL << ImaParser::SAFEDEPOSITBOX)
      | (1ULL << ImaParser::GYM))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> ImaParser::_decisionToDFA;
atn::PredictionContextCache ImaParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ImaParser::_atn;
std::vector<uint16_t> ImaParser::_serializedATN;

std::vector<std::string> ImaParser::_ruleNames = {
  "journey", "trip", "journeySpec", "tripSpec", "commonSpec", "range", "unit", 
  "travelMode", "bedType", "amenity"
};

std::vector<std::string> ImaParser::_literalNames = {
  "", "','", "", "", "", "", "'trip'", "'~'", "':'", "'min'", "'m'", "'if'", 
  "'then'", "'by'", "'to'", "'walking'", "'transit'", "'driving'", "'bicycling'", 
  "'goto'", "'budget'", "'hhdist'", "'hhdura'", "'dhdist'", "'dhdura'", 
  "'bedtype'", "'amenity'", "'servicelevel'", "'guestnum'", "'twin'", "'double'", 
  "'single'", "'queen'", "'king'", "'vending machines'", "'free wifi'", 
  "'parking'", "'swimming pool'", "'laundry service'", "'laundry room'", 
  "'non-smoking room'", "'safe deposit box'", "'gym'"
};

std::vector<std::string> ImaParser::_symbolicNames = {
  "", "", "WS", "DATE", "NUM", "STRING", "TRIP", "THROUGH", "SEMICOLON", 
  "MIN", "M", "IF", "THEN", "BY", "TO", "WALKING", "TRANSIT", "DRIVING", 
  "BICYCLING", "GOTO", "BUDGET", "HHDIST", "HHDURA", "DHDIST", "DHDURA", 
  "BEDTYPE", "AMENITY", "SERVICELEVEL", "GUESTNUM", "TWIN", "DOUBLE", "SINGLE", 
  "QUEEN", "KING", "VENDINGMACHINES", "FREEWIFI", "PARKING", "SWIMMINGPOOL", 
  "LAUNDRYSERVICE", "LAUNDRYROOM", "NONSMOKINGROOM", "SAFEDEPOSITBOX", "GYM"
};

dfa::Vocabulary ImaParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ImaParser::_tokenNames;

ImaParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x2c, 0x6f, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x3, 0x2, 0x6, 0x2, 0x18, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x19, 0x3, 
    0x2, 0x6, 0x2, 0x1d, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x1e, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x6, 0x3, 0x24, 0xa, 0x3, 0xd, 0x3, 0xe, 0x3, 0x25, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x2b, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x32, 0xa, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x7, 0x6, 0x3e, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x41, 0xb, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x47, 0xa, 0x6, 
    0xc, 0x6, 0xe, 0x6, 0x4a, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 
    0x6, 0x4f, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x5, 0x6, 0x57, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x5f, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x65, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x2, 
    0x2, 0xc, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x2, 
    0x8, 0x3, 0x2, 0x17, 0x18, 0x3, 0x2, 0x19, 0x1a, 0x3, 0x2, 0xb, 0xc, 
    0x3, 0x2, 0x11, 0x14, 0x3, 0x2, 0x1f, 0x23, 0x3, 0x2, 0x24, 0x2c, 0x2, 
    0x76, 0x2, 0x17, 0x3, 0x2, 0x2, 0x2, 0x4, 0x20, 0x3, 0x2, 0x2, 0x2, 
    0x6, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x8, 0x31, 0x3, 0x2, 0x2, 0x2, 0xa, 0x5e, 
    0x3, 0x2, 0x2, 0x2, 0xc, 0x60, 0x3, 0x2, 0x2, 0x2, 0xe, 0x66, 0x3, 0x2, 
    0x2, 0x2, 0x10, 0x68, 0x3, 0x2, 0x2, 0x2, 0x12, 0x6a, 0x3, 0x2, 0x2, 
    0x2, 0x14, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x16, 0x18, 0x5, 0x6, 0x4, 0x2, 
    0x17, 0x16, 0x3, 0x2, 0x2, 0x2, 0x18, 0x19, 0x3, 0x2, 0x2, 0x2, 0x19, 
    0x17, 0x3, 0x2, 0x2, 0x2, 0x19, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x1c, 
    0x3, 0x2, 0x2, 0x2, 0x1b, 0x1d, 0x5, 0x4, 0x3, 0x2, 0x1c, 0x1b, 0x3, 
    0x2, 0x2, 0x2, 0x1d, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1c, 0x3, 0x2, 
    0x2, 0x2, 0x1e, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x3, 0x3, 0x2, 0x2, 
    0x2, 0x20, 0x21, 0x7, 0x8, 0x2, 0x2, 0x21, 0x23, 0x7, 0xa, 0x2, 0x2, 
    0x22, 0x24, 0x5, 0x8, 0x5, 0x2, 0x23, 0x22, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0x25, 0x3, 0x2, 0x2, 0x2, 0x25, 0x23, 0x3, 0x2, 0x2, 0x2, 0x25, 0x26, 
    0x3, 0x2, 0x2, 0x2, 0x26, 0x5, 0x3, 0x2, 0x2, 0x2, 0x27, 0x28, 0x7, 
    0x5, 0x2, 0x2, 0x28, 0x2b, 0x7, 0x9, 0x2, 0x2, 0x29, 0x2b, 0x5, 0xa, 
    0x6, 0x2, 0x2a, 0x27, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x29, 0x3, 0x2, 0x2, 
    0x2, 0x2b, 0x7, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 0x7, 0x9, 0x2, 0x2, 
    0x2d, 0x32, 0x7, 0x5, 0x2, 0x2, 0x2e, 0x2f, 0x7, 0x15, 0x2, 0x2, 0x2f, 
    0x32, 0x7, 0x7, 0x2, 0x2, 0x30, 0x32, 0x5, 0xa, 0x6, 0x2, 0x31, 0x2c, 
    0x3, 0x2, 0x2, 0x2, 0x31, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x31, 0x30, 0x3, 
    0x2, 0x2, 0x2, 0x32, 0x9, 0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x7, 0x16, 
    0x2, 0x2, 0x34, 0x5f, 0x5, 0xc, 0x7, 0x2, 0x35, 0x36, 0x7, 0x1d, 0x2, 
    0x2, 0x36, 0x5f, 0x5, 0xc, 0x7, 0x2, 0x37, 0x38, 0x7, 0x1e, 0x2, 0x2, 
    0x38, 0x5f, 0x5, 0xc, 0x7, 0x2, 0x39, 0x3a, 0x7, 0x1b, 0x2, 0x2, 0x3a, 
    0x3f, 0x5, 0x12, 0xa, 0x2, 0x3b, 0x3c, 0x7, 0x3, 0x2, 0x2, 0x3c, 0x3e, 
    0x5, 0x12, 0xa, 0x2, 0x3d, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x41, 0x3, 
    0x2, 0x2, 0x2, 0x3f, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x3, 0x2, 
    0x2, 0x2, 0x40, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x41, 0x3f, 0x3, 0x2, 0x2, 
    0x2, 0x42, 0x43, 0x7, 0x1c, 0x2, 0x2, 0x43, 0x48, 0x5, 0x14, 0xb, 0x2, 
    0x44, 0x45, 0x7, 0x3, 0x2, 0x2, 0x45, 0x47, 0x5, 0x14, 0xb, 0x2, 0x46, 
    0x44, 0x3, 0x2, 0x2, 0x2, 0x47, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x48, 0x46, 
    0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 0x3, 0x2, 0x2, 0x2, 0x49, 0x5f, 0x3, 
    0x2, 0x2, 0x2, 0x4a, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4e, 0x9, 0x2, 
    0x2, 0x2, 0x4c, 0x4d, 0x7, 0xf, 0x2, 0x2, 0x4d, 0x4f, 0x5, 0x10, 0x9, 
    0x2, 0x4e, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4f, 0x3, 0x2, 0x2, 0x2, 
    0x4f, 0x50, 0x3, 0x2, 0x2, 0x2, 0x50, 0x5f, 0x5, 0xc, 0x7, 0x2, 0x51, 
    0x52, 0x9, 0x3, 0x2, 0x2, 0x52, 0x53, 0x7, 0x10, 0x2, 0x2, 0x53, 0x56, 
    0x7, 0x7, 0x2, 0x2, 0x54, 0x55, 0x7, 0xf, 0x2, 0x2, 0x55, 0x57, 0x5, 
    0x10, 0x9, 0x2, 0x56, 0x54, 0x3, 0x2, 0x2, 0x2, 0x56, 0x57, 0x3, 0x2, 
    0x2, 0x2, 0x57, 0x58, 0x3, 0x2, 0x2, 0x2, 0x58, 0x5f, 0x5, 0xc, 0x7, 
    0x2, 0x59, 0x5a, 0x7, 0xd, 0x2, 0x2, 0x5a, 0x5b, 0x5, 0xa, 0x6, 0x2, 
    0x5b, 0x5c, 0x7, 0xe, 0x2, 0x2, 0x5c, 0x5d, 0x5, 0xa, 0x6, 0x2, 0x5d, 
    0x5f, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x33, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x35, 
    0x3, 0x2, 0x2, 0x2, 0x5e, 0x37, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x39, 0x3, 
    0x2, 0x2, 0x2, 0x5e, 0x42, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x4b, 0x3, 0x2, 
    0x2, 0x2, 0x5e, 0x51, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x59, 0x3, 0x2, 0x2, 
    0x2, 0x5f, 0xb, 0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x7, 0x6, 0x2, 0x2, 
    0x61, 0x62, 0x7, 0x9, 0x2, 0x2, 0x62, 0x64, 0x7, 0x6, 0x2, 0x2, 0x63, 
    0x65, 0x5, 0xe, 0x8, 0x2, 0x64, 0x63, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 
    0x3, 0x2, 0x2, 0x2, 0x65, 0xd, 0x3, 0x2, 0x2, 0x2, 0x66, 0x67, 0x9, 
    0x4, 0x2, 0x2, 0x67, 0xf, 0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 0x9, 0x5, 
    0x2, 0x2, 0x69, 0x11, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x9, 0x6, 0x2, 
    0x2, 0x6b, 0x13, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x9, 0x7, 0x2, 0x2, 
    0x6d, 0x15, 0x3, 0x2, 0x2, 0x2, 0xd, 0x19, 0x1e, 0x25, 0x2a, 0x31, 0x3f, 
    0x48, 0x4e, 0x56, 0x5e, 0x64, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ImaParser::Initializer ImaParser::_init;


// Generated from Ima.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "ImaListener.h"


namespace antlrcpp {

/**
 * This class provides an empty implementation of ImaListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ImaBaseListener : public ImaListener {
public:

  virtual void enterJourney(ImaParser::JourneyContext * /*ctx*/) override { }
  virtual void exitJourney(ImaParser::JourneyContext * /*ctx*/) override { }

  virtual void enterTrip(ImaParser::TripContext * /*ctx*/) override { }
  virtual void exitTrip(ImaParser::TripContext * /*ctx*/) override { }

  virtual void enterSpecStartDate(ImaParser::SpecStartDateContext * /*ctx*/) override { }
  virtual void exitSpecStartDate(ImaParser::SpecStartDateContext * /*ctx*/) override { }

  virtual void enterSpecGlobal(ImaParser::SpecGlobalContext * /*ctx*/) override { }
  virtual void exitSpecGlobal(ImaParser::SpecGlobalContext * /*ctx*/) override { }

  virtual void enterSpecEndDate(ImaParser::SpecEndDateContext * /*ctx*/) override { }
  virtual void exitSpecEndDate(ImaParser::SpecEndDateContext * /*ctx*/) override { }

  virtual void enterSpecTripDest(ImaParser::SpecTripDestContext * /*ctx*/) override { }
  virtual void exitSpecTripDest(ImaParser::SpecTripDestContext * /*ctx*/) override { }

  virtual void enterSpecLocal(ImaParser::SpecLocalContext * /*ctx*/) override { }
  virtual void exitSpecLocal(ImaParser::SpecLocalContext * /*ctx*/) override { }

  virtual void enterSpecBudget(ImaParser::SpecBudgetContext * /*ctx*/) override { }
  virtual void exitSpecBudget(ImaParser::SpecBudgetContext * /*ctx*/) override { }

  virtual void enterSpecSerLvl(ImaParser::SpecSerLvlContext * /*ctx*/) override { }
  virtual void exitSpecSerLvl(ImaParser::SpecSerLvlContext * /*ctx*/) override { }

  virtual void enterSpecGuestNum(ImaParser::SpecGuestNumContext * /*ctx*/) override { }
  virtual void exitSpecGuestNum(ImaParser::SpecGuestNumContext * /*ctx*/) override { }

  virtual void enterSpecBedType(ImaParser::SpecBedTypeContext * /*ctx*/) override { }
  virtual void exitSpecBedType(ImaParser::SpecBedTypeContext * /*ctx*/) override { }

  virtual void enterSpecAmenity(ImaParser::SpecAmenityContext * /*ctx*/) override { }
  virtual void exitSpecAmenity(ImaParser::SpecAmenityContext * /*ctx*/) override { }

  virtual void enterSpecHH(ImaParser::SpecHHContext * /*ctx*/) override { }
  virtual void exitSpecHH(ImaParser::SpecHHContext * /*ctx*/) override { }

  virtual void enterSpecDH(ImaParser::SpecDHContext * /*ctx*/) override { }
  virtual void exitSpecDH(ImaParser::SpecDHContext * /*ctx*/) override { }

  virtual void enterSpecIfThen(ImaParser::SpecIfThenContext * /*ctx*/) override { }
  virtual void exitSpecIfThen(ImaParser::SpecIfThenContext * /*ctx*/) override { }

  virtual void enterRange(ImaParser::RangeContext * /*ctx*/) override { }
  virtual void exitRange(ImaParser::RangeContext * /*ctx*/) override { }

  virtual void enterUnit(ImaParser::UnitContext * /*ctx*/) override { }
  virtual void exitUnit(ImaParser::UnitContext * /*ctx*/) override { }

  virtual void enterTravelMode(ImaParser::TravelModeContext * /*ctx*/) override { }
  virtual void exitTravelMode(ImaParser::TravelModeContext * /*ctx*/) override { }

  virtual void enterBedType(ImaParser::BedTypeContext * /*ctx*/) override { }
  virtual void exitBedType(ImaParser::BedTypeContext * /*ctx*/) override { }

  virtual void enterAmenity(ImaParser::AmenityContext * /*ctx*/) override { }
  virtual void exitAmenity(ImaParser::AmenityContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace antlrcpp

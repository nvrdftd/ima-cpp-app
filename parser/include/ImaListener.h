
// Generated from Ima.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "ImaParser.h"


namespace antlrcpp {

/**
 * This interface defines an abstract listener for a parse tree produced by ImaParser.
 */
class  ImaListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterJourney(ImaParser::JourneyContext *ctx) = 0;
  virtual void exitJourney(ImaParser::JourneyContext *ctx) = 0;

  virtual void enterTrip(ImaParser::TripContext *ctx) = 0;
  virtual void exitTrip(ImaParser::TripContext *ctx) = 0;

  virtual void enterSpecStartDate(ImaParser::SpecStartDateContext *ctx) = 0;
  virtual void exitSpecStartDate(ImaParser::SpecStartDateContext *ctx) = 0;

  virtual void enterSpecGlobal(ImaParser::SpecGlobalContext *ctx) = 0;
  virtual void exitSpecGlobal(ImaParser::SpecGlobalContext *ctx) = 0;

  virtual void enterSpecEndDate(ImaParser::SpecEndDateContext *ctx) = 0;
  virtual void exitSpecEndDate(ImaParser::SpecEndDateContext *ctx) = 0;

  virtual void enterSpecTripDest(ImaParser::SpecTripDestContext *ctx) = 0;
  virtual void exitSpecTripDest(ImaParser::SpecTripDestContext *ctx) = 0;

  virtual void enterSpecLocal(ImaParser::SpecLocalContext *ctx) = 0;
  virtual void exitSpecLocal(ImaParser::SpecLocalContext *ctx) = 0;

  virtual void enterSpecBudget(ImaParser::SpecBudgetContext *ctx) = 0;
  virtual void exitSpecBudget(ImaParser::SpecBudgetContext *ctx) = 0;

  virtual void enterSpecSerLvl(ImaParser::SpecSerLvlContext *ctx) = 0;
  virtual void exitSpecSerLvl(ImaParser::SpecSerLvlContext *ctx) = 0;

  virtual void enterSpecGuestNum(ImaParser::SpecGuestNumContext *ctx) = 0;
  virtual void exitSpecGuestNum(ImaParser::SpecGuestNumContext *ctx) = 0;

  virtual void enterSpecBedType(ImaParser::SpecBedTypeContext *ctx) = 0;
  virtual void exitSpecBedType(ImaParser::SpecBedTypeContext *ctx) = 0;

  virtual void enterSpecAmenity(ImaParser::SpecAmenityContext *ctx) = 0;
  virtual void exitSpecAmenity(ImaParser::SpecAmenityContext *ctx) = 0;

  virtual void enterSpecHH(ImaParser::SpecHHContext *ctx) = 0;
  virtual void exitSpecHH(ImaParser::SpecHHContext *ctx) = 0;

  virtual void enterSpecDH(ImaParser::SpecDHContext *ctx) = 0;
  virtual void exitSpecDH(ImaParser::SpecDHContext *ctx) = 0;

  virtual void enterSpecIfThen(ImaParser::SpecIfThenContext *ctx) = 0;
  virtual void exitSpecIfThen(ImaParser::SpecIfThenContext *ctx) = 0;

  virtual void enterRange(ImaParser::RangeContext *ctx) = 0;
  virtual void exitRange(ImaParser::RangeContext *ctx) = 0;

  virtual void enterUnit(ImaParser::UnitContext *ctx) = 0;
  virtual void exitUnit(ImaParser::UnitContext *ctx) = 0;

  virtual void enterTravelMode(ImaParser::TravelModeContext *ctx) = 0;
  virtual void exitTravelMode(ImaParser::TravelModeContext *ctx) = 0;

  virtual void enterBedType(ImaParser::BedTypeContext *ctx) = 0;
  virtual void exitBedType(ImaParser::BedTypeContext *ctx) = 0;

  virtual void enterAmenity(ImaParser::AmenityContext *ctx) = 0;
  virtual void exitAmenity(ImaParser::AmenityContext *ctx) = 0;


};

}  // namespace antlrcpp

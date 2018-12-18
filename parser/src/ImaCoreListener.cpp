#include "antlr4-runtime.h"
#include "Amenity.h"
#include "AmenityConstraint.h"
#include "BedTypeConstraint.h"
#include "BudgetConstraint.h"
#include "BedType.h"
#include "Constraint.h"
#include "ConstraintType.h"
#include "ConstraintSet.h"
#include "Date.h"
#include "DateConstraint.h"
#include "DestConstraint.h"
#include "DHDistConstraint.h"
#include "DHDuraConstraint.h"
#include "GuestNumConstraint.h"
#include "HHDistConstraint.h"
#include "HHDuraConstraint.h"
#include "IfThenConstraint.h"
#include "ImaCoreListener.h"
#include "ImaParser.h"
#include "SLvlConstraint.h"
#include "TravelMode.h"
#include <exception>
#include <string>
#include <unordered_map>
#include <memory>

namespace ima {

    class SpecException: public std::exception {
        const char *what() const noexcept override
        {
            return "Missing required spec: e.g. dates, destinations, budgets";
        }
    };

    ImaCoreListener::ImaCoreListener(): _inTrip(false), _inIfThen(false), _localSet(nullptr), _lb(0), _ub(0) {}

    void ImaCoreListener::exitJourney(antlrcpp::ImaParser::JourneyContext *ctx)
    {

        if (!_globalSet.have(ConstraintType::Date)) throw SpecException();

        int m = _globalSet.getNumOfConstraints();
        int n = _globalSet.getNumOfLocals();
        for (int i = 0; i < n; ++i) {
            const ConstraintSet &localSet = _globalSet.getLocal(i);
            if (!localSet.have(ConstraintType::Date)) throw SpecException();
            if (!localSet.have(ConstraintType::Dest)) throw SpecException();
            if (!localSet.have(ConstraintType::Budget)) throw SpecException();
            if (i == n - 1) {
                const DateConstraint &globalPeriod = static_cast<const DateConstraint&>(_globalSet.get(ConstraintType::Date));
                const DateConstraint &localPeriod = static_cast<const DateConstraint&>(localSet.get(ConstraintType::Date));
                std::shared_ptr<DateConstraint> newPeriod = std::make_shared<DateConstraint>(globalPeriod.getLB(), localPeriod.getUB());
                _globalSet.update(newPeriod);
            }
        }
    }

    void ImaCoreListener::exitSpecStartDate(antlrcpp::ImaParser::SpecStartDateContext *ctx)
    {
        Date startDate(ctx->DATE()->getText());
        std::shared_ptr<DateConstraint> date = std::make_shared<DateConstraint>(startDate);
        _globalSet.add(date);
    }

    void ImaCoreListener::enterTrip(antlrcpp::ImaParser::TripContext *ctx)
    {
        if (_globalSet.have(ConstraintType::Date)) {
            _inTrip = true;
            _localSet = new ConstraintSet();
        } else {
            throw std::runtime_error("Journey start date undefined");
        }
    }

    void ImaCoreListener::exitTrip(antlrcpp::ImaParser::TripContext *ctx)
    {
        _inTrip = false;
        _globalSet.addLocal(*_localSet);
        delete _localSet;
    }

    void ImaCoreListener::exitSpecEndDate(antlrcpp::ImaParser::SpecEndDateContext *ctx)
    {
        DateConstraint &dates = static_cast<DateConstraint&>(_globalSet.get(ConstraintType::Date));
        Date startDate = dates.getLB();
        Date endDate(ctx->DATE()->getText());
        if (startDate >= endDate) {
            throw std::runtime_error("More than one stay night should be specified.");
        }
        dates.setLB(endDate);
        std::shared_ptr<DateConstraint> newDates = std::make_shared<DateConstraint>(startDate, endDate);
        _localSet->add(newDates);
    }

    void ImaCoreListener::exitSpecTripDest(antlrcpp::ImaParser::SpecTripDestContext *ctx)
    {
        std::shared_ptr<DestConstraint> dest = std::make_shared<DestConstraint>(ctx->STRING()->getText());
        _localSet->add(dest);
    }

    void ImaCoreListener::exitSpecBudget(antlrcpp::ImaParser::SpecBudgetContext *ctx)
    {
        std::shared_ptr<BudgetConstraint> newBudget = std::make_shared<BudgetConstraint>(_lb, _ub);
        insertConstraint(newBudget);
        _constraintTable.put(ctx, newBudget);
    }

    void ImaCoreListener::exitSpecSerLvl(antlrcpp::ImaParser::SpecSerLvlContext *ctx)
    {
        std::shared_ptr<SLvlConstraint> newSLvl = std::make_shared<SLvlConstraint>(_lb, _ub);
        insertConstraint(newSLvl);
        _constraintTable.put(ctx, newSLvl);
    }

    void ImaCoreListener::exitSpecGuestNum(antlrcpp::ImaParser::SpecGuestNumContext *ctx)
    {
        std::shared_ptr<GuestNumConstraint> newGuestNum = std::make_shared<GuestNumConstraint>(_lb, _ub);
        insertConstraint(newGuestNum);
        _constraintTable.put(ctx, newGuestNum);
    }

    void ImaCoreListener::exitSpecBedType(antlrcpp::ImaParser::SpecBedTypeContext *ctx)
    {
        std::shared_ptr<BedTypeConstraint> newBedTypes = std::make_shared<BedTypeConstraint>();

        for (auto type: ctx->bedType()) {
            bedTypeHandler(newBedTypes, type);
        }

        insertConstraint(newBedTypes);
        _constraintTable.put(ctx, newBedTypes);
    }

    void ImaCoreListener::exitSpecAmenity(antlrcpp::ImaParser::SpecAmenityContext *ctx)
    {
        std::shared_ptr<AmenityConstraint> newAmenities = std::make_shared<AmenityConstraint>();

        for (auto amenity: ctx->amenity()) {
            amenityHandler(newAmenities, amenity);
        }

        insertConstraint(newAmenities);
        _constraintTable.put(ctx, newAmenities);
    }

    void ImaCoreListener::exitSpecHH(antlrcpp::ImaParser::SpecHHContext *ctx)
    {
        TravelMode mode;

        if (ctx->travelMode()) {
            mode = findTravelMode(ctx->travelMode());
        } else {
            mode = TravelMode::Driving;
        }

        if (ctx->HHDIST()) {
            std::shared_ptr<HHDistConstraint> newHHDist = std::make_shared<HHDistConstraint>(_lb, _ub);
            newHHDist->setTravelMode(mode);
            insertConstraint(newHHDist);
            _constraintTable.put(ctx, newHHDist);
        } else if (ctx->HHDURA()) {
            std::shared_ptr<HHDuraConstraint> newHHDura = std::make_shared<HHDuraConstraint>(_lb, _ub);
            newHHDura->setTravelMode(mode);
            insertConstraint(newHHDura);
            _constraintTable.put(ctx, newHHDura);
        } else {
            throw std::runtime_error("Unexpected crash");
        }
    }

    void ImaCoreListener::exitSpecDH(antlrcpp::ImaParser::SpecDHContext *ctx)
    {

            std::string dest(ctx->STRING()->getText());
            TravelMode mode;

            if (ctx->travelMode()) {
                mode = findTravelMode(ctx->travelMode());
            } else {
                mode = TravelMode::Driving;
            }

            if (ctx->DHDIST()) {
                std::shared_ptr<DHDistConstraint> newDHDist = std::make_shared<DHDistConstraint>(_lb, _ub);
                newDHDist->setTravelMode(mode);
                newDHDist->setDest(dest);
                insertConstraint(newDHDist);
                _constraintTable.put(ctx, newDHDist);
            } else if (ctx->DHDURA()) {
                std::shared_ptr<DHDuraConstraint> newDHDura = std::make_shared<DHDuraConstraint>(_lb, _ub);
                newDHDura->setTravelMode(mode);
                newDHDura->setDest(dest);
                insertConstraint(newDHDura);
                _constraintTable.put(ctx, newDHDura);
            } else {
                throw std::runtime_error("Unexpected crash");
            }
    }

    void ImaCoreListener::enterSpecIfThen(antlrcpp::ImaParser::SpecIfThenContext *ctx)
    {
        _inIfThen = true;
    }

    void ImaCoreListener::exitSpecIfThen(antlrcpp::ImaParser::SpecIfThenContext *ctx)
    {
        std::shared_ptr<Constraint> ifConstraint = _constraintTable.removeFrom(ctx->commonSpec(0));
        std::shared_ptr<Constraint> thenConstraint = _constraintTable.removeFrom(ctx->commonSpec(1));
        insertConstraint(ifConstraint, thenConstraint);
        _inIfThen = false;
    }

    void ImaCoreListener::exitRange(antlrcpp::ImaParser::RangeContext *ctx)
    {
        _lb = std::stof(ctx->NUM(0)->getText());
        _ub = std::stof(ctx->NUM(1)->getText());
    }

    void ImaCoreListener::bedTypeHandler(std::shared_ptr<BedTypeConstraint> bedTypes, antlrcpp::ImaParser::BedTypeContext *ctx)
    {
        if (ctx->TWIN()) {
            bedTypes->add(BedType::Twin);
        } else if (ctx->SINGLE()) {
            bedTypes->add(BedType::Single);
        } else if (ctx->DOUBLE()) {
            bedTypes->add(BedType::Double);
        } else if (ctx->QUEEN()) {
            bedTypes->add(BedType::Queen);
        } else if (ctx->KING()) {
            bedTypes->add(BedType::King);
        } else {
            throw std::runtime_error("Undefined bed type");
        }
    }

    void ImaCoreListener::amenityHandler(std::shared_ptr<AmenityConstraint> amenities, antlrcpp::ImaParser::AmenityContext *ctx)
    {
        if (ctx->VENDINGMACHINES()) {
            amenities->add(Amenity::VendingMachines);
        } else if (ctx->FREEWIFI()) {
            amenities->add(Amenity::Hotspots);
        } else if (ctx->PARKING()) {
            amenities->add(Amenity::Parking);
        } else if (ctx->LAUNDRYSERVICE()) {
            amenities->add(Amenity::LaundryService);
        } else if (ctx->NONSMOKINGROOM()) {
            amenities->add(Amenity::NonSmokingRoom);
        } else if (ctx->SAFEDEPOSITBOX()) {
            amenities->add(Amenity::SafeDepositBox);
        } else {
            throw std::runtime_error("Undefined amenity");
        }
    }

    TravelMode ImaCoreListener::findTravelMode(antlrcpp::ImaParser::TravelModeContext *ctx) const
    {
        if (ctx->WALKING()) {
            return TravelMode::Walking;
        } else if (ctx->DRIVING()) {
            return TravelMode::Driving;
        } else if (ctx->BICYCLING()) {
            return TravelMode::Bicycling;
        } else if (ctx->TRANSIT()) {
            return TravelMode::Transit;
        } else {
            throw std::runtime_error("Undefined travel mode");
        }
    }

    void ImaCoreListener::insertConstraint(std::shared_ptr<Constraint> c)
    {
        if (_inIfThen) {
            return;
        }

        ConstraintType type = c->getType();
        bool haveGlobal = _globalSet.have(type);
        bool haveLocal = false;

        if (_localSet) {
            haveLocal = _localSet->have(type);
        }

        if (_inTrip) {
            if (haveLocal) {
                _localSet->update(c);
            } else {
                _localSet->add(c);
            }
        } else {
            if (haveGlobal) {
                _globalSet.update(c);
            } else {
                _globalSet.add(c);
            }
        }
    }

    void ImaCoreListener::insertConstraint(std::shared_ptr<Constraint> ifConstraint, std::shared_ptr<Constraint> thenConstraint)
    {
        ConstraintType type = ConstraintType::IfThen;
        bool haveGlobal = _globalSet.have(type);
        bool haveLocal = false;

        if (_localSet) {
            haveLocal = _localSet->have(type);
        }

        std::shared_ptr<IfThenConstraint> _ifThens = std::make_shared<IfThenConstraint>();
        _ifThens->add(ifConstraint, thenConstraint);

        if (_inTrip) {
            if (haveLocal) {
                IfThenConstraint &ifThens = static_cast<IfThenConstraint&>(_localSet->get(type));
                for (int i = 0; i < ifThens.getNumOfIfThens(); ++i) {
                    std::shared_ptr<Constraint> ifConstraint = ifThens.getIfPtr(i);
                    std::shared_ptr<Constraint> thenConstraint = ifThens.getThenPtr(i);
                    _ifThens->add(ifConstraint, thenConstraint);
                }
                _localSet->update(_ifThens);
            } else {
                _localSet->add(_ifThens);
            }
        } else {
            if (haveGlobal) {
                IfThenConstraint &ifThens = static_cast<IfThenConstraint&>(_globalSet.get(type));
                for (int i = 0; i < ifThens.getNumOfIfThens(); ++i) {
                    std::shared_ptr<Constraint> ifConstraint = ifThens.getIfPtr(i);
                    std::shared_ptr<Constraint> thenConstraint = ifThens.getThenPtr(i);
                    _ifThens->add(ifConstraint, thenConstraint);
                }
                _globalSet.update(_ifThens);
            } else {
                _globalSet.add(_ifThens);
            }
        }
    }

    const ConstraintSet &ImaCoreListener::getGlobal() const
    {
        return _globalSet;
    }

}

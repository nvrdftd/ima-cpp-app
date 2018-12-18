#include <fstream>
#include <stdexcept>
#include <string>
#include <unordered_set>

#include "antlr4-runtime.h"
#include "Amenity.h"
#include "AmenityConstraint.h"
#include "BedType.h"
#include "BudgetConstraint.h"
#include "BedTypeConstraint.h"
#include "Combo.h"
#include "ComboArray.h"
#include "ConstraintType.h"
#include "ConstraintSet.h"
#include "DHDistConstraint.h"
#include "DHDuraConstraint.h"
#include "DAG.h"
#include "GuestNumConstraint.h"
#include "HotelArray.h"
#include "HHDistConstraint.h"
#include "HHDuraConstraint.h"
#include "ImaCore.h"
#include "ImaCoreListener.h"
#include "ImaLexer.h"
#include "ImaParser.h"
#include "ilcplex/ilocplex.h"
#include "JourneyInfo.h"
#include "ModelArray.h"
#include "SLvlConstraint.h"
#include "Solution.h"
#include "SolutionArray.h"

namespace ima {

    void ImaCore::optimizeGlobal(JourneyInfo &_journey)
    {
        IloEnv _env;
        IloTimer coreTimer(_env);
        coreTimer.start();

        IloModel model(_env);
        IloNum2dArray price2dArr(_env);
        IloBoolVar2dArray x2dArr(_env);
        IloExpr budgetExpr(_env);

        IloInt numOfTrips = _journey.getNumOfTrips();

        for (IloInt i = 0; i < numOfTrips; ++i) {
            const TripInfo &trip = _journey.getTripInfo(i);
            const ComboArray &comboArr = trip.getComboArr();
            IloInt numOfCombos = comboArr.getNumOfCombos();
            IloNumArray priceArr(_env);
            IloBoolVarArray xArr(_env, numOfCombos);
            for (IloInt j = 0; j < numOfCombos; ++j) {
                IloNum comboPrice = comboArr.getCombo(j).getPrice();
                priceArr.add(comboPrice);
            }
            price2dArr.add(priceArr);
            x2dArr.add(xArr);
            budgetExpr += IloScalProd(priceArr, xArr);
            model.add(xArr);
            /*
            **  The constraint below asserts that
            **  only one of these combos will be chosen for each edge on the graph.
            */
            model.add(IloSum(xArr) == 1);
        }

        model.add(IloMinimize(_env, budgetExpr));
        budgetExpr.end();

        SolutionArray solArr;
        ModelArray modelArr;

        const ConstraintSet &cSet = _journey.getConstraintSet();

        modelArr.add(toGlobalModel(_env, x2dArr, cSet, _journey));

        if (cSet.have(ConstraintType::IfThen)) {
            IfThenConstraint ifThens = static_cast<const IfThenConstraint&>(cSet.get(ConstraintType::IfThen));
            for (IloInt i = 0; i < ifThens.getNumOfIfThens(); ++i) {
                std::shared_ptr<Constraint> ifConstraint = ifThens.getIfPtr(i);
                std::shared_ptr<Constraint> thenConstraint = ifThens.getThenPtr(i);
                ConstraintSet newSet = cSet;
                if (newSet.have(ifConstraint->getType())) {
                    newSet.update(ifConstraint);
                } else {
                    newSet.add(ifConstraint);
                }
                if (newSet.have(thenConstraint->getType())) {
                    newSet.update(thenConstraint);
                } else {
                    newSet.add(thenConstraint);
                }
                modelArr.add(toGlobalModel(_env, x2dArr, newSet, _journey));
            }
        }

        IloCplex cplex(_env);
        cplex.setParam(IloCplex::Param::MIP::Pool::RelGap, 0.3);
        std::cout << "==================== Global Optimization ====================" << std::endl;

        IloInt nModels = modelArr.getNumOfModels();

        for (IloInt i = 0; i < nModels; ++i) {

            std::cout << "===== Model " << i + 1 << " =====" << std::endl;

            const IloModel &subModel = modelArr.get(i);

            model.add(subModel);

            try {
                cplex.extract(model);
                cplex.populate();
                std::cout << "solution status: " << cplex.getStatus() << std::endl;
                std::cout << "Total cost: " << cplex.getObjValue() << std::endl;
                std::cout << "# of solutions: " << cplex.getSolnPoolNsolns() << std::endl;
                std::cout << "# of constraints: " << cplex.getNrows() << std::endl;

                for (IloInt s = 0; s < cplex.getSolnPoolNsolns(); ++s) {

                    Solution sol(cplex.getObjValue(s));
                    for (IloInt i = 0; i < _journey.getNumOfTrips(); ++i) {
                        const TripInfo &trip = _journey.getTripInfo(i);
                        const ComboArray &comboArr = trip.getComboArr();
                        IloInt numOfCombos = comboArr.getNumOfCombos();
                        for (IloInt j = 0; j < numOfCombos; ++j) {
                            if (cplex.getValue(x2dArr[i][j], s) == 1) {
                                sol.add(comboArr.getCombo(j));
                                break;
                            }
                        }

                    }
                    solArr.add(sol);
                }

            } catch (...) {
                std::cerr << "Optimization Error" << std::endl;
            }
            cplex.clearModel();
            model.remove(subModel);
            _journey.setSolArr(solArr);
        }
        coreTimer.stop();
        std::cout << "Aggregate CPU Time: " << coreTimer.getTime() << " sec(s)" << std::endl;
    }

    void ImaCore::optimizeLocal(JourneyInfo &_journey)
    {
        for (IloInt t = 0; t < _journey.getNumOfTrips(); ++t) {
            IloEnv _env;
            IloTimer coreTimer(_env);
            coreTimer.start();
            TripInfo &trip = _journey.getTripInfo(t);
            DAG<RelationInfo, RequestInfo> &infoDAG = trip.getDAG();

            IloInt numOfEdges = infoDAG.getNumOfEdges();
            IloInt numOfNodes = infoDAG.getNumOfNodes();

            IloModel model(_env);
            IloBoolVar3dArray x3dArr(_env);
            IloExpr budgetExpr(_env);

            for (IloInt i = 0; i < numOfEdges; ++i) {

                HotelArray &hotelArr = infoDAG.getEdgeData(i).getHotelArr();
                IloInt numOfHotels = hotelArr.getNumOfHotels();

                IloBoolVar2dArray x2dArr(_env);

                for (IloInt j = 0; j < numOfHotels; ++j) {

                    Hotel &hotel = hotelArr[j];
                    IloInt numOfRooms = hotel.getNumOfRooms();
                    IloBoolVarArray xArr(_env, numOfRooms);
                    IloNumArray priceArr(_env);

                    for (IloInt k = 0; k < numOfRooms; ++k) {

                        HotelRoom &room = hotel.getRoom(k);
                        IloNum price = room.getPrice();
                        priceArr.add(price);
                    }
                    model.add(xArr);
                    x2dArr.add(xArr);
                    budgetExpr += IloScalProd(xArr, priceArr);
                }
                x3dArr.add(x2dArr);
            }

            model.add(IloMinimize(_env, budgetExpr));
            budgetExpr.end();

            /*
            ** The following are the constraints
            ** that define a directed acyclic graph that represents the whole trip.
            */
            IloExpr tmpExpr(_env);
            for (IloInt i: infoDAG.getOEdgeId(0)) {
                HotelArray &hotelArr = infoDAG.getEdgeData(i).getHotelArr();
                for (IloInt j = 0; j < hotelArr.getNumOfHotels(); ++j) {
                    for (IloInt k = 0; k < hotelArr[j].getNumOfRooms(); ++k) {
                        tmpExpr += x3dArr[i][j][k];
                    }
                }
            }

            model.add(tmpExpr == 1);
            tmpExpr.clear();

            for (IloInt i: infoDAG.getIEdgeId(numOfNodes - 1)) {
                HotelArray &hotelArr = infoDAG.getEdgeData(i).getHotelArr();
                for (IloInt j = 0; j < hotelArr.getNumOfHotels(); ++j) {
                    for (IloInt k = 0; k < hotelArr[j].getNumOfRooms(); ++k) {
                        tmpExpr += x3dArr[i][j][k];
                    }
                }
            }

            model.add(tmpExpr == 1);
            tmpExpr.clear();

            for (IloInt v = 1; v < numOfNodes - 1; ++v) {
                for (IloInt u: infoDAG.getIEdgeId(v)) {
                    HotelArray &hotelArr = infoDAG.getEdgeData(u).getHotelArr();
                    for (IloInt i = 0; i < hotelArr.getNumOfHotels(); ++i) {
                        for (IloInt j = 0; j < hotelArr[i].getNumOfRooms(); ++j) {
                            tmpExpr += x3dArr[u][i][j];
                        }
                    }
                }

                for (IloInt w: infoDAG.getOEdgeId(v)) {
                    HotelArray &hotelArr = infoDAG.getEdgeData(w).getHotelArr();
                    for (IloInt i = 0; i < hotelArr.getNumOfHotels(); ++i) {
                        for (IloInt j = 0; j < hotelArr[i].getNumOfRooms(); ++j) {
                            tmpExpr -= x3dArr[w][i][j];
                        }
                    }
                }
                model.add(tmpExpr == 0);
                tmpExpr.clear();
            }

            tmpExpr.end();

            /*
            ** Suppose that there are a number of submodels in which a set of different types of constraints is specified.
            ** These submodels are stored in a SubModelArray object, which will be added to the main model, and solved
            ** sequentially one at a time.
            */

            ComboArray newComboArr;
            ModelArray modelArr;

            const ConstraintSet &cSet = trip.getConstraintSet();

            modelArr.add(toLocalModel(_env, x3dArr, cSet, infoDAG));

            if (cSet.have(ConstraintType::IfThen)) {
                IfThenConstraint ifThens = static_cast<const IfThenConstraint&>(cSet.get(ConstraintType::IfThen));
                for (IloInt i = 0; i < ifThens.getNumOfIfThens(); ++i) {
                    std::shared_ptr<Constraint> ifConstraint = ifThens.getIfPtr(i);
                    std::shared_ptr<Constraint> thenConstraint = ifThens.getThenPtr(i);
                    ConstraintSet newSet = cSet;
                    if (newSet.have(ifConstraint->getType())) {
                        newSet.update(ifConstraint);
                    } else {
                        newSet.add(ifConstraint);
                    }
                    if (newSet.have(thenConstraint->getType())) {
                        newSet.update(thenConstraint);
                    } else {
                        newSet.add(thenConstraint);
                    }
                    modelArr.add(toLocalModel(_env, x3dArr, newSet, infoDAG));
                }
            }

            IloCplex cplex(_env);
            cplex.setParam(IloCplex::Param::MIP::Pool::RelGap, 0.3);

            std::cout << "==================== Local Optimization ====================" << std::endl;

            IloInt nModels = modelArr.getNumOfModels();

            for (IloInt i = 0; i < nModels; ++i) {

                std::cout << "===== Model " << i + 1 << " =====" << std::endl;

                const IloModel &subModel = modelArr.get(i);
                model.add(subModel);

                try {
                    cplex.extract(model);
                    cplex.populate();
                    std::cout << "solution status: " << cplex.getStatus() << std::endl;
                    std::cout << "Total cost: " << cplex.getObjValue() << std::endl;
                    std::cout << "# of solutions: " << cplex.getSolnPoolNsolns() << std::endl;
                    std::cout << "# of constraints: " << cplex.getNrows() << std::endl;

                    for (IloInt s = 0; s < cplex.getSolnPoolNsolns(); ++s) {

                        Combo newCombo(cplex.getObjValue(s));

                        for (IloInt i = 0; i < infoDAG.getNumOfEdges(); ++i) {

                            HotelArray &hotelArr = infoDAG.getEdgeData(i).getHotelArr();
                            IloInt numOfHotels = hotelArr.getNumOfHotels();

                            for (IloInt j = 0; j < numOfHotels; ++j) {

                                IloInt numOfRooms = hotelArr[j].getNumOfRooms();

                                for (IloInt k = 0; k < numOfRooms; ++k) {
                                    if (cplex.getValue(x3dArr[i][j][k], s) == 1) {
                                        Hotel newHotel = hotelArr[j];
                                        const HotelRoom &room = newHotel.getRoom(k);
                                        newHotel.clearRooms();
                                        newHotel.addRoom(room);
                                        newCombo.addHotel(newHotel);
                                        break;
                                    }
                                }
                            }
                        }
                        newComboArr.addCombo(newCombo);
                    }

                } catch (...) {
                    std::cerr << "Optimization Error" << std::endl;
                }
                cplex.clearModel();
                model.remove(subModel);
                trip.setComboArr(newComboArr);
            }
            coreTimer.stop();
            std::cout << "Aggregate CPU Time: " << coreTimer.getTime() << " sec(s)" << std::endl;
        }
    }
    ConstraintSet ImaCore::parse(const std::string &filename)
    {
        std::ifstream is(filename);
        antlr4::ANTLRInputStream input(is);
        antlrcpp::ImaLexer lexer(&input);
        antlr4::CommonTokenStream tokens(&lexer);
        antlrcpp::ImaParser parser(&tokens);
        ImaCoreListener listener;
        antlr4::tree::ParseTree *tree = parser.journey();
        antlr4::tree::ParseTreeWalker treeWalker;
        treeWalker.walk(&listener, tree);
        is.close();
        return listener.getGlobal();
    }
    IloModel ImaCore::toLocalModel(
        IloEnv &env,
        IloBoolVar3dArray &x3dArr,
        const ConstraintSet &constraintSet,
        DAG<RelationInfo, RequestInfo> &infoDAG
    )
    {
        IloModel model(env);

        IloInt numOfEdges = infoDAG.getNumOfEdges();
        IloInt numOfNodes = infoDAG.getNumOfNodes();

        for (IloInt i = 0; i < constraintSet.getNumOfConstraints(); ++i) {
            const Constraint &constraint = constraintSet.get(i);
            switch (constraint.getType()) {
                case ConstraintType::Budget: {
                    const BudgetConstraint &budget = static_cast<const BudgetConstraint&>(constraint);
                    IloNum LB = budget.getLB();
                    IloNum UB = budget.getUB();

                    if (LB < 0 || UB < 0) {
                        throw std::range_error("Unacceptable Bounds");
                    }

                    IloExpr budgetExpr(env);

                    for (IloInt i = 0; i < numOfEdges; ++i) {

                        HotelArray &hotelArr = infoDAG.getEdgeData(i).getHotelArr();
                        IloInt numOfHotels = hotelArr.getNumOfHotels();

                        for (IloInt j = 0; j < numOfHotels; ++j) {

                            Hotel &hotel = hotelArr[j];
                            IloInt numOfRooms = hotel.getNumOfRooms();
                            IloNumArray priceArr(env);

                            for (IloInt k = 0; k < numOfRooms; ++k) {
                                HotelRoom &room = hotel.getRoom(k);
                                IloNum price = room.getPrice();
                                priceArr.add(price);
                            }

                            budgetExpr += IloScalProd(x3dArr[i][j], priceArr);
                        }
                    }
                    model.add(LB <= budgetExpr <= UB);
                    budgetExpr.end();
                    break;
                }
                case ConstraintType::HHDist: {
                    const HHDistConstraint &hhdist = static_cast<const HHDistConstraint&>(constraint);
                    IloNum LB = hhdist.getLB();
                    IloNum UB = hhdist.getUB();
                    for (IloInt v = 1; v < numOfNodes - 1; ++v) {
                        for (IloInt u: infoDAG.getIEdgeId(v)) {
                            for (IloInt w: infoDAG.getOEdgeId(v)) {
                                /* If two hotels are selected,
                                ** ensure that the distance between the two,
                                ** is satisfied by the specified bounds.
                                */
                                InfoMatrix<AnyTwoInfo> &infoMatrix = infoDAG.getNodeData(v).getAnyTwoInfoMatrix(u, w);
                                for (IloInt m = 0; m < x3dArr[u].getSize(); ++m) {
                                    for (IloInt n = 0; n < x3dArr[w].getSize(); ++n) {
                                        IloExpr sum1 = IloSum(x3dArr[u][m]);
                                        IloExpr sum2 = IloSum(x3dArr[w][n]);
                                        IloNum distVal = infoMatrix.getElement(m, n).getDistVal();
                                        IloIfThen ifThen(
                                            env,
                                            (sum1 == 1) && (sum2 == 1),
                                            (LB <= sum1 * distVal <= UB) || (LB <= sum2 * distVal <= UB)
                                        );
                                        model.add(ifThen);
                                    }
                                }
                            }
                        }
                    }
                    break;
                }
                case ConstraintType::HHDura: {
                    const HHDuraConstraint &hhdura = static_cast<const HHDuraConstraint&>(constraint);
                    IloNum LB = hhdura.getLB();
                    IloNum UB = hhdura.getUB();
                    for (IloInt v = 1; v < numOfNodes - 1; ++v) {
                        for (IloInt u: infoDAG.getIEdgeId(v)) {
                            for (IloInt w: infoDAG.getOEdgeId(v)) {
                                /* If two hotels are selected,
                                ** ensure that the distance between the two,
                                ** is satisfied by the specified bounds.
                                */
                                InfoMatrix<AnyTwoInfo> &infoMatrix = infoDAG.getNodeData(v).getAnyTwoInfoMatrix(u, w);
                                for (IloInt m = 0; m < x3dArr[u].getSize(); ++m) {
                                    for (IloInt n = 0; n < x3dArr[w].getSize(); ++n) {
                                        IloExpr sum1 = IloSum(x3dArr[u][m]);
                                        IloExpr sum2 = IloSum(x3dArr[w][n]);
                                        IloNum duraVal = infoMatrix.getElement(m, n).getDuraVal();
                                        IloIfThen ifThen(
                                            env,
                                            (sum1 == 1) && (sum2 == 1),
                                            (LB <= sum1 * duraVal <= UB) || (LB <= sum2 * duraVal <= UB)
                                        );
                                        model.add(ifThen);
                                    }
                                }
                            }
                        }
                    }
                    break;
                }
                case ConstraintType::DHDist: {
                    const DHDistConstraint &dhdist = static_cast<const DHDistConstraint&>(constraint);
                    IloNum LB = dhdist.getLB();
                    IloNum UB = dhdist.getUB();
                    for (IloInt i = 0; i < numOfEdges; ++i) {
                        InfoArray<AnyTwoInfo> &infoArr = infoDAG.getEdgeData(i).getAnyTwoInfoArr();
                        for (IloInt n = 0; n < x3dArr[i].getSize(); ++n) {
                            IloExpr sum = IloSum(x3dArr[i][n]);
                            IloNum distVal = infoArr.get(n).getDistVal();
                            IloIfThen ifThen(
                                env,
                                (sum == 1),
                                (LB <= sum * distVal <= UB)
                            );
                            model.add(ifThen);
                        }
                    }
                    break;
                }
                case ConstraintType::DHDura: {
                    const DHDuraConstraint &dhdura = static_cast<const DHDuraConstraint&>(constraint);
                    IloNum LB = dhdura.getLB();
                    IloNum UB = dhdura.getUB();
                    for (IloInt i = 0; i < numOfEdges; ++i) {
                        InfoArray<AnyTwoInfo> &infoArr = infoDAG.getEdgeData(i).getAnyTwoInfoArr();
                        for (IloInt n = 0; n < x3dArr[i].getSize(); ++n) {
                            IloExpr sum = IloSum(x3dArr[i][n]);
                            IloNum duraVal = infoArr.get(n).getDuraVal();
                            IloIfThen ifThen(
                                env,
                                (sum == 1),
                                (LB <= sum * duraVal <= UB)
                            );
                            model.add(ifThen);
                        }
                    }
                    break;
                }
                case ConstraintType::ServiceLevel: {
                    const SLvlConstraint &slvl = static_cast<const SLvlConstraint&>(constraint);
                    IloInt LB = slvl.getLB();
                    IloInt UB = slvl.getUB();
                    if (LB > 5 || UB > 5) {
                        throw std::range_error("Unrecoginzable service level");
                    }

                    for (IloInt i = 0; i < x3dArr.getSize(); ++i) {
                        HotelArray &hotelArr = infoDAG.getEdgeData(i).getHotelArr();
                        for (IloInt j = 0; j < x3dArr[i].getSize(); ++j) {
                            IloOr orExpr(env);
                            Hotel &hotel = hotelArr[j];
                            for (IloInt k = LB; k <= UB; ++k) {
                                orExpr.add(IloSum(x3dArr[i][j]) * hotel.isAward(k) == IloTrue);
                            }
                            IloIfThen ifThen(
                                env,
                                (IloSum(x3dArr[i][j]) == 1),
                                orExpr
                            );
                            model.add(ifThen);
                        }
                    }
                    break;
                }
                case ConstraintType::Amenity: {
                    const AmenityConstraint amenities = static_cast<const AmenityConstraint&>(constraint);
                        for (IloInt i = 0; i < x3dArr.getSize(); ++i) {
                            HotelArray &hotelArr = infoDAG.getEdgeData(i).getHotelArr();
                            for (IloInt j = 0; j < x3dArr[i].getSize(); ++j) {
                                Hotel &hotel = hotelArr[j];
                                IloAnd andExpr(env);
                                for (IloInt a = 0; a < amenities.getNumOfChecks(); ++a) {
                                    unsigned int amenityCode = static_cast<unsigned int>(amenities.get(a));
                                    if (amenityCode >= NUM_OTA_CODES) {
                                        throw std::range_error("Unacceptable Bound");
                                    }
                                    andExpr.add(IloSum(x3dArr[i][j]) * hotel.isAmenity(amenityCode) == IloTrue);
                                }
                                IloIfThen ifThen(
                                    env,
                                    (IloSum(x3dArr[i][j]) == 1),
                                    andExpr
                                );
                                model.add(ifThen);
                            }
                        }
                    break;
                }
                case ConstraintType::GuestNum: {
                    const GuestNumConstraint &guestNum = static_cast<const GuestNumConstraint&>(constraint);
                    IloInt LB = guestNum.getLB();
                    IloInt UB = guestNum.getUB();
                    if (LB == 0 || UB == 0) {
                        throw std::range_error("Unacceptable Bound");
                    }
                    for (IloInt i = 0; i < x3dArr.getSize(); ++i) {
                        HotelArray &hotelArr = infoDAG.getEdgeData(i).getHotelArr();
                        for (IloInt j = 0; j < x3dArr[i].getSize(); ++j) {
                            Hotel &hotel = hotelArr[j];
                            for (IloInt k = 0; k < x3dArr[i][j].getSize(); ++k) {
                                HotelRoom &room = hotel.getRoom(k);
                                IloInt numOfGuests = room.getNumOfGuests();
                                IloIfThen ifThen(
                                    env,
                                    (x3dArr[i][j][k] == IloTrue),
                                    (LB <= x3dArr[i][j][k] * numOfGuests <= UB)
                                );
                                model.add(ifThen);
                            }
                        }
                    }
                    break;
                }
                case ConstraintType::BedType: {
                    const BedTypeConstraint &bedTypes = static_cast<const BedTypeConstraint&>(constraint);
                    for (IloInt i = 0; i < x3dArr.getSize(); ++i) {
                        HotelArray &hotelArr = infoDAG.getEdgeData(i).getHotelArr();
                        for (IloInt j = 0; j < x3dArr[i].getSize(); ++j) {
                            Hotel &hotel = hotelArr[j];
                            for (IloInt k = 0; k < x3dArr[i][j].getSize(); ++k) {
                                IloOr orExpr(env);
                                HotelRoom &room = hotel.getRoom(k);
                                IloInt roomBedCode = static_cast<IloInt>(room.getBedType());
                                for (IloInt c = 0; c < bedTypes.getNumOfChecks(); ++c) {
                                    IloInt bedTypeCode = static_cast<IloInt>(bedTypes.get(c));
                                    if (bedTypeCode >= NUM_BED_TYPES) {
                                        throw std::range_error("Unacceptable Bound");
                                    }
                                    orExpr.add(bedTypeCode == x3dArr[i][j][k] * roomBedCode);
                                }
                                IloIfThen ifThen(
                                    env,
                                    (x3dArr[i][j][k] == IloTrue),
                                    orExpr
                                );
                                model.add(ifThen);
                            }
                        }
                    }
                    break;
                }
            }
        }
        return model;
    }

    IloModel ImaCore::toGlobalModel(
        IloEnv &env,
        IloBoolVar2dArray &x2dArr,
        const ConstraintSet &constraintSet,
        JourneyInfo &journey
    )
    {
        IloInt numOfTrips = journey.getNumOfTrips();
        IloModel model(env);
        for (IloInt i = 0; i < constraintSet.getNumOfConstraints(); ++i) {
            const Constraint &constraint = constraintSet.get(i);
            switch (constraint.getType()) {
                case ConstraintType::Budget: {
                    const BudgetConstraint &budget = static_cast<const BudgetConstraint&>(constraint);
                    IloNum LB = budget.getLB();
                    IloNum UB = budget.getUB();
                    if (LB < 0 || UB < 0) {
                        throw std::range_error("Unacceptable Bounds");
                    }

                    IloExpr budgetExpr(env);

                    for (IloInt i = 0; i < numOfTrips; ++i) {
                        const TripInfo &trip = journey.getTripInfo(i);
                        const ComboArray &comboArr = trip.getComboArr();
                        IloInt numOfCombos = comboArr.getNumOfCombos();

                        IloNumArray priceArr(env);

                        for (IloInt j = 0; j < numOfCombos; ++j) {
                            IloNum comboPrice = comboArr.getCombo(j).getPrice();
                            priceArr.add(comboPrice);
                        }

                        budgetExpr += IloScalProd(priceArr, x2dArr[i]);
                    }

                    model.add(LB <= budgetExpr <= UB);
                    budgetExpr.end();
                    break;
                }
            }

        }
        return model;

    }
}

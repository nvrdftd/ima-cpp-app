#pragma once

#define IL_STD
#define NUM_OTA_CODES 330
#define NUM_SERVICE_LEVELS 5

#include <vector>
#include "Constraint.h"
#include "ConstraintSet.h"
#include "DAG.h"
#include "ilcplex/ilocplex.h"
#include "JourneyInfo.h"
ILOSTLBEGIN

namespace ima {

    template <class T>
    using Ilo2dArray = IloArray<IloArray<T> >;

    template <class T>
    using Ilo3dArray = Ilo2dArray<IloArray<T> >;

    typedef IloArray<IloNumArray> IloNum2dArray;
    typedef IloArray<IloBoolVarArray> IloBoolVar2dArray;
    typedef Ilo2dArray<IloNumArray> IloNum3dArray;
    typedef Ilo2dArray<IloBoolVarArray> IloBoolVar3dArray;
    typedef IloArray<IloBoolArray> IloBool2dArray;
    typedef Ilo2dArray<IloBoolArray> IloBool3dArray;
    typedef IloArray<IloIntArray> IloInt2dArray;
    typedef Ilo2dArray<IloIntArray> IloInt3dArray;
    typedef Ilo3dArray<IloNumArray> IloNum4dArray;

    class ImaCore {
        public:
            static void optimizeLocal(JourneyInfo &);
            static void optimizeGlobal(JourneyInfo &);
            static ConstraintSet parse(const std::string &);
            static IloModel toLocalModel(
                IloEnv &env,
                IloBoolVar3dArray &x3dArr,
                const ConstraintSet &,
                DAG<RelationInfo, RequestInfo> &
            );
            static IloModel toGlobalModel(
                IloEnv &,
                IloBoolVar2dArray &,
                const ConstraintSet &,
                JourneyInfo &
            );
    };
}

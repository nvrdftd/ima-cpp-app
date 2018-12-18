#pragma once

#include "BaseInfo.h"
#include "ComboArray.h"
#include "Date.h"
#include "DAG.h"
#include "GeoInfo.h"
#include "RelationInfo.h"
#include "RequestInfo.h"

namespace ima {

    class TripInfo: public BaseInfo {
        public:
            TripInfo(const Date &, const Date &, const GeoInfo &);
            TripInfo(const TripInfo &) = default;
            TripInfo(TripInfo &&) = default;
            TripInfo &operator=(const TripInfo &) = default;
            TripInfo &operator=(TripInfo &&) = default;
            GeoInfo &getGeoInfo();
            DAG<RelationInfo, RequestInfo> &getDAG();
            const ComboArray &getComboArr() const;
            void setComboArr(const ComboArray &);
        private:
            GeoInfo _geoInfo;
            DAG<RelationInfo, RequestInfo> _infoDAG;
            ComboArray _comboArr;
    };

}

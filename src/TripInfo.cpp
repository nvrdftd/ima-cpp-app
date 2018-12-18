#include "BaseInfo.h"
#include "ComboArray.h"
#include "Date.h"
#include "DAG.h"
#include "GeoInfo.h"
#include "TripInfo.h"

namespace ima {

    TripInfo::TripInfo(const Date &startDate, const Date &endDate, const GeoInfo &geoInfo): BaseInfo(startDate, endDate), _geoInfo(geoInfo) {}

    GeoInfo &TripInfo::getGeoInfo()
    {
        return _geoInfo;
    }

    DAG<RelationInfo, RequestInfo> &TripInfo::getDAG()
    {
        return _infoDAG;
    }

    const ComboArray &TripInfo::getComboArr() const
    {
        return _comboArr;
    }

    void TripInfo::setComboArr(const ComboArray &comboArr)
    {
        _comboArr = comboArr;
    }

}

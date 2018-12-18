#pragma once

#include <string>
#include "DAG.h"
#include "GeoInfo.h"
#include "JourneyInfo.h"
#include "RelationInfo.h"
#include "RequestInfo.h"
#include "TravelMode.h"

#define MAX_NUM_ELEMENTS 25
#define CONCURRENT_API_CALL_LIMIT 5
#define WAIT_TIME_MILLISECONDS 200

namespace ima {

    class ImaClient {
        public:
            static GeoInfo getGeoInfo(const std::string &);
            static void printGeoInfo(const GeoInfo &);
            static void getAnyTwoHotelsRel(GraphEdge<RequestInfo> &, GraphEdge<RequestInfo> &, GraphNode<RelationInfo, RequestInfo> &, TravelMode);
            static void getAnyLocHotelRel(const GeoInfo &, GraphEdge<RequestInfo> &, TravelMode);
            static void getHotels(RequestInfo &);
            static void resolve(JourneyInfo &);
            static void printDAG(DAG<RelationInfo, RequestInfo> &infoDAG);
    };

}

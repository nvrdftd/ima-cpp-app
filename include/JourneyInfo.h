#pragma once

#include <vector>
#include "BaseInfo.h"
#include "Date.h"
#include "DAG.h"
#include "SolutionArray.h"
#include "TripInfo.h"

namespace ima {

    class JourneyInfo: public BaseInfo {
        public:
            JourneyInfo() = default;
            JourneyInfo(const Date &, const Date &);
            JourneyInfo(const JourneyInfo &) = default;
            JourneyInfo(JourneyInfo &&) = default;
            JourneyInfo &operator=(const JourneyInfo &) = default;
            JourneyInfo &operator=(JourneyInfo &&) = default;
            void setSearchRadius(unsigned int);
            void addTripInfo(const TripInfo &);
            TripInfo &getTripInfo(unsigned int);
            unsigned int getNumOfTrips();
            unsigned int getSearchRadius();
            const SolutionArray &getSolArr() const;
            void setSolArr(const SolutionArray &);
            void setQueryNum(unsigned int);
            unsigned int getQueryNum() const;
        private:
            unsigned int _searchRadius;
            unsigned int _queryNum;
            std::vector<TripInfo> _tripVector;
            SolutionArray _solArr;
    };

}

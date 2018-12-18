#include <cpprest/json.h>
#include <pplx/pplxtasks.h>
#include <cpprest/base_uri.h>
#include <cpprest/uri_builder.h>
#include <cpprest/http_client.h>
#include <cpprest/http_msg.h>
#include <cstdlib>
#include <string>
#include <vector>
#include <chrono>
#include <stdexcept>
#include <thread>
#include <memory>
#include <utility>
#include "AnyTwoInfo.h"
#include "BedType.h"
#include "Coordinates.h"
#include "Constraint.h"
#include "ConstraintSet.h"
#include "ConstraintType.h"
#include "DHDistConstraint.h"
#include "DHDuraConstraint.h"
#include "Date.h"
#include "DAG.h"
#include "GeoInfo.h"
#include "Hotel.h"
#include "HotelRoom.h"
#include "HotelArray.h"
#include "HHDistConstraint.h"
#include "HHDuraConstraint.h"
#include "ImaClient.h"
#include "InfoMatrix.h"
#include "JourneyInfo.h"
#include "RequestInfo.h"
#include "TravelMode.h"
#include "TripInfo.h"

namespace ima {

    GeoInfo ImaClient::getGeoInfo(const std::string &placeTextString)
    {

        GeoInfo info(placeTextString);
        // Google translates a literal string to a geolocation.
        std::string apikey(std::getenv("GOOGLE_PLACES_API_KEY"));
        std::string apiEndpoint("https://maps.googleapis.com/maps/api/place/findplacefromtext/");
        std::string inputtype("textquery");
        std::string fields("geometry/location");
        web::uri apiuri(apiEndpoint);
        web::http::client::http_client client(apiuri);
        web::uri_builder builder("json");
        builder.append_query("input", placeTextString);
        builder.append_query("key", apikey);
        builder.append_query("inputtype", inputtype);
        builder.append_query("fields", fields);

        pplx::task<void> async = client.request(web::http::methods::GET, builder.to_string())
        .then([&] (web::http::http_response response) {
            return response.extract_json();
        })
        .then([&] (web::json::value val) {
                 const web::json::array &jsonArr = val.at("candidates").as_array();
                 for(auto iter = jsonArr.cbegin(); iter != jsonArr.cend(); ++iter)
                 {
                     const web::json::value &geo = iter->at("geometry");
                     const web::json::value &loc = geo.at("location");
                     const web::json::value &lat = loc.at("lat");
                     const web::json::value &lng = loc.at("lng");
                     info.setCoordinates(lat.as_double(), lng.as_double());
                 }
        });

        try {
            async.wait();
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        return info;
    }

    void ImaClient::printGeoInfo(const GeoInfo &info)
    {
        std::cout << "Place: " << info.getPlaceText() << std::endl;
        const Coordinates &geoloc = info.getCoordinates();
        std::cout << "Coordinates: " << geoloc.getLatitude() << ", " <<
        geoloc.getLongitude() << std::endl;
    }

    void ImaClient::resolve(JourneyInfo &journey)
    {
        unsigned int radius = journey.getSearchRadius();
        unsigned int numOfQueryResults = journey.getQueryNum();
        // if (numOfQueryResults > MAX_NUM_ELEMENTS) {
        //     std::cerr << "Warning: number of hotels exceeds max 25; Reduced to max" << std::endl;
        //     numOfQueryResults = MAX_NUM_ELEMENTS;
        // }

        for (int t = 0; t < journey.getNumOfTrips(); ++t) {
            TripInfo &trip = journey.getTripInfo(t);
            Date &startDate = trip.getStartDate();
            Date &endDate = trip.getEndDate();
            GeoInfo &geoInfo = trip.getGeoInfo();
            const ConstraintSet &localSet = trip.getConstraintSet();
            DAG<RelationInfo, RequestInfo> &infoDAG = trip.getDAG();

            unsigned int numOfNights = endDate - startDate;

            for (int i = 0; i <= numOfNights; ++i) {
                infoDAG.insert(RelationInfo());
            }

            std::cout
            << "Trip starts from " << startDate.getDateStr() << " to " << endDate.getDateStr()
            << " for " << numOfNights << " night(s)"
            << std::endl;

            std::vector<std::thread> reqThreads;

            for (int s = 0; s < numOfNights; ++s) {
                for (int d = s + 1; d <= numOfNights; ++d) {
                    Date fromDate = startDate + s;
                    Date toDate = startDate + d;
                    RequestInfo newReqInfo(fromDate, toDate, geoInfo, radius, numOfQueryResults);
                    infoDAG.setEdgeData(s, d, newReqInfo);
                    reqThreads.push_back(std::thread([&infoDAG, s, d] () {
                        getHotels(infoDAG.getEdgeData(s, d));
                    }));
                    if (reqThreads.size() % CONCURRENT_API_CALL_LIMIT == 0) {
                        std::this_thread::sleep_for(std::chrono::milliseconds(WAIT_TIME_MILLISECONDS));
                    }
                }
            }

            for (int i = 0; i < reqThreads.size(); ++i) {
                reqThreads[i].join();
            }

            bool haveHHDist = localSet.have(ConstraintType::HHDist);
            bool haveHHDura = localSet.have(ConstraintType::HHDura);

            if (haveHHDist || haveHHDura) {

                TravelMode mode;

                if (haveHHDist) {
                    const Constraint &constraint = localSet.get(ConstraintType::HHDist);
                    const HHDistConstraint &hhdist = static_cast<const HHDistConstraint&>(constraint);
                    mode = hhdist.getTravelMode();
                }

                if (haveHHDura) {
                    const Constraint &constraint = localSet.get(ConstraintType::HHDura);
                    const HHDuraConstraint &hhdura = static_cast<const HHDuraConstraint&>(constraint);
                    mode = hhdura.getTravelMode();
                }

                std::vector<std::thread> hhThreads;

                for (int v = 1; v < numOfNights; ++v) {
                    for (int u = v - 1; u >= 0; --u) {
                        for (int w = v + 1; w <= numOfNights; ++w) {
                            hhThreads.push_back(std::thread([&infoDAG, u, v, w, mode] () {
                                getAnyTwoHotelsRel(
                                    infoDAG.getEdge(u, v),
                                    infoDAG.getEdge(v, w),
                                    infoDAG.getNode(v),
                                    mode
                                );
                            }));
                        }
                    }
                }

                for (int i = 0; i < hhThreads.size(); ++i) {
                    hhThreads[i].join();
                }
            }

            bool haveDHDist = localSet.have(ConstraintType::DHDist);
            bool haveDHDura = localSet.have(ConstraintType::DHDura);

            if (haveDHDist || haveDHDura) {

                TravelMode mode;
                std::string locStr;

                if (haveDHDist) {
                    const Constraint &constraint = localSet.get(ConstraintType::DHDist);
                    const DHDistConstraint &dhdist = static_cast<const DHDistConstraint&>(constraint);
                    mode = dhdist.getTravelMode();
                    locStr = dhdist.getDest();
                }

                if (haveDHDura) {
                    const Constraint &constraint = localSet.get(ConstraintType::DHDura);
                    const DHDuraConstraint &dhdura = static_cast<const DHDuraConstraint&>(constraint);
                    mode = dhdura.getTravelMode();
                    locStr = dhdura.getDest();
                }

                std::vector<std::thread> dhThreads;

                GeoInfo locInfo = getGeoInfo(locStr);

                for (int s = 0; s < numOfNights; ++s) {
                    for (int d = s + 1; d <= numOfNights; ++d) {
                        dhThreads.push_back(std::thread([&locInfo, &infoDAG, s, d, mode] () {
                            getAnyLocHotelRel(locInfo, infoDAG.getEdge(s, d), mode);
                        }));
                        if (dhThreads.size() % CONCURRENT_API_CALL_LIMIT == 0) {
                            std::this_thread::sleep_for(std::chrono::milliseconds(WAIT_TIME_MILLISECONDS));
                        }
                    }
                }

                for (int i = 0; i < dhThreads.size(); ++i) {
                    dhThreads[i].join();
                }
            }
        }
    }

    void ImaClient::getHotels(RequestInfo &reqInfo)
    {
        std::string apikey(std::getenv("AMADEUS_API_KEY"));
        std::string apiEndpoint("https://api.sandbox.amadeus.com/v1.2/");
        web::uri apiuri(apiEndpoint);
        web::http::client::http_client client(apiuri);
        web::uri_builder builder("hotels/search-circle");

        const Coordinates &geoloc = reqInfo.getGeoInfo().getCoordinates();

        builder.append_query("latitude", geoloc.getLatitude());
        builder.append_query("longitude", geoloc.getLongitude());
        builder.append_query("check_in", reqInfo.getCheckInDate().getDateStr());
        builder.append_query("check_out", reqInfo.getCheckOutDate().getDateStr());
        builder.append_query("radius", reqInfo.getRadius());
        builder.append_query("apikey", apikey);
        builder.append_query("number_of_results", reqInfo.getNumOfHotels());

        pplx::task<void> async = client.request(web::http::methods::GET, builder.to_string())
        .then([&] (web::http::http_response response) {
            return response.extract_json();
        })
        .then([&] (web::json::value val) {
            HotelArray &hotelArr = reqInfo.getHotelArr();
            const web::json::array &jsonArr = val.at("results").as_array();
            for (auto hotelIter = jsonArr.cbegin(); hotelIter != jsonArr.cend(); ++hotelIter) {

                 const web::json::value &hotelCode = hotelIter->at("property_code");
                 const web::json::value &hotelName = hotelIter->at("property_name");
                 const web::json::value &loc = hotelIter->at("location");
                 const web::json::array &roomArr = hotelIter->at("rooms").as_array();
                 const web::json::array &amenityArr = hotelIter->at("amenities").as_array();
                 const web::json::value &lat = loc.at("latitude");
                 const web::json::value &lng = loc.at("longitude");

                 Coordinates geoloc(lat.as_double(), lng.as_double());
                 Hotel newHotel(hotelCode.as_string(), hotelName.as_string(), geoloc, reqInfo.getCheckInDate(), reqInfo.getCheckOutDate());

                 try {
                     const web::json::array &awardArr = hotelIter->at("awards").as_array();
                     for (auto awardIter = awardArr.cbegin(); awardIter != awardArr.cend(); ++awardIter) {
                         const web::json::value &rating = awardIter->at("rating");
                         unsigned int award = std::stoi(rating.as_string());
                         newHotel.addAward(award);
                     }
                 } catch (std::exception &e) {
                     // std::cout << "No award acknowledged." << std::endl;
                 }

                 for (auto amenityIter = amenityArr.cbegin(); amenityIter != amenityArr.cend(); ++amenityIter) {
                     const web::json::value &OTACode = amenityIter->at("ota_code");
                     newHotel.addAmenity(OTACode.as_integer());
                 }

                 for (auto roomIter = roomArr.cbegin(); roomIter != roomArr.cend(); ++roomIter) {
                     const web::json::value &totalAmount = roomIter->at("total_amount");
                     const web::json::value &amount = totalAmount.at("amount");
                     double price = std::stod(amount.as_string());

                     BedType bedType;
                     unsigned int numOfBeds;

                     const web::json::value &roomTypeCode = roomIter->at("room_type_code");
                     const char *code = roomTypeCode.as_string().c_str();

                     switch (code[1]) {
                         case '1':
                            numOfBeds = 1;
                            break;
                         case '2':
                            numOfBeds = 2;
                            break;
                         case '3':
                            numOfBeds = 3;
                            break;
                         default:
                            numOfBeds = 0;
                     }

                     switch (code[2]) {
                         case 'S':
                            bedType = BedType::Single;
                            break;
                         case 'T':
                            bedType = BedType::Twin;
                            break;
                         case 'D':
                            bedType = BedType::Double;
                            break;
                         case 'Q':
                            bedType = BedType::Queen;
                            break;
                         case 'K':
                            bedType = BedType::King;
                            break;
                         default:
                            bedType = BedType::Any;
                     }

                     HotelRoom newRoom(bedType, numOfBeds, price);
                     newHotel.addRoom(newRoom);
                 }
                 hotelArr.addHotel(newHotel);
             }
        });

        try {
            async.wait();
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    void ImaClient::getAnyTwoHotelsRel(
        GraphEdge<RequestInfo> &aEdge,
        GraphEdge<RequestInfo> &bEdge,
        GraphNode<RelationInfo, RequestInfo> &node,
        TravelMode travelMode)
    {
        std::string origins;
        std::string destinations;
        std::string mode;

        HotelArray &aHotelArr = aEdge.getData().getHotelArr();
        HotelArray &bHotelArr = bEdge.getData().getHotelArr();

        int m = aHotelArr.getNumOfHotels();
        int n = bHotelArr.getNumOfHotels();

        for (int i = 0; i < m; ++i) {
            const Coordinates &coordinates = aHotelArr[i].getCoordinates();
            std::string geoLatLng(std::to_string(coordinates.getLatitude()));
            geoLatLng.append(",");
            geoLatLng.append(std::to_string(coordinates.getLongitude()));
            origins.append(geoLatLng);
            if (i < m - 1) {
                origins.append("|");
            }
        }

        for (int i = 0; i < n; ++i) {
            const Coordinates &coordinates = bHotelArr[i].getCoordinates();
            std::string geoLatLng(std::to_string(coordinates.getLatitude()));
            geoLatLng.append(",");
            geoLatLng.append(std::to_string(coordinates.getLongitude()));
            destinations.append(geoLatLng);
            if (i < n - 1) {
                destinations.append("|");
            }
        }

        switch (travelMode) {
            case TravelMode::Driving:
                mode = "driving";
                break;
            case TravelMode::Walking:
                mode = "walking";
                break;
            case TravelMode::Bicycling:
                mode = "bicycling";
                break;
            case TravelMode::Transit:
                mode = "transit";
                break;
            default:
                std::cerr << "Warning: unrecognizable travel mode; default to transit mode" << std::endl;
                mode = "transit";
        }

        InfoMatrix<AnyTwoInfo> infoMatrix(m, n);

        // Google evaluate a distance between any two specified hotels with respect to the transport type
        std::string apikey(std::getenv("GOOGLE_DISTANCE_API_KEY"));
        std::string apiEndpoint("https://maps.googleapis.com/maps/api/distancematrix/");
        web::uri apiuri(apiEndpoint);
        web::http::client::http_client client(apiuri);
        web::uri_builder builder("json");
        builder.append_query("origins", origins);
        builder.append_query("destinations", destinations);
        builder.append_query("mode", mode);
        builder.append_query("key", apikey);

        pplx::task<void> async = client.request(web::http::methods::GET, builder.to_string())
        .then([&] (web::http::http_response response) {
            return response.extract_json();
        })
        .then([&] (web::json::value val) {
                 const web::json::array &jsonArr = val.at("rows").as_array();

                 unsigned int i = 0;
                 for (auto aIter = jsonArr.cbegin(); aIter != jsonArr.cend(); ++aIter)
                 {
                     unsigned j = 0;
                     const web::json::array &jsonRow = aIter->at("elements").as_array();
                     for (auto bIter = jsonRow.cbegin(); bIter != jsonRow.cend(); ++bIter)
                     {
                         const web::json::value &duration = bIter->at("duration");
                         const web::json::value &distance = bIter->at("distance");
                         const web::json::value &duraVal = duration.at("value");
                         const web::json::value &distVal = distance.at("value");
                         const web::json::value &duraText = duration.at("text");
                         const web::json::value &distText = distance.at("text");
                         AnyTwoInfo anyTwoInfo(duraVal.as_integer() / 60, duraText.as_string(), distVal.as_integer(), distText.as_string());
                         infoMatrix.setElement(anyTwoInfo, i, j);
                         ++j;
                    }
                    ++i;
                 }
        });

        try {
            async.wait();
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        node.getData().setAnyTwoInfoMatrix(aEdge.getEdgeId(), bEdge.getEdgeId(), infoMatrix);
    }

    void ImaClient::getAnyLocHotelRel(
        const GeoInfo &locInfo,
        GraphEdge<RequestInfo> &edge,
        TravelMode travelMode
    )
    {
        std::string destinations;
        std::string mode;

        HotelArray &hotelArr = edge.getData().getHotelArr();

        int m = hotelArr.getNumOfHotels();

        for (int i = 0; i < m; ++i) {
            Coordinates coordinates = hotelArr[i].getCoordinates();
            std::string geoLatLng(std::to_string(coordinates.getLatitude()));
            geoLatLng.append(",");
            geoLatLng.append(std::to_string(coordinates.getLongitude()));
            destinations.append(geoLatLng);
            if (i < m - 1) {
                destinations.append("|");
            }
        }

        const Coordinates &coordinates = locInfo.getCoordinates();

        std::string origins(std::to_string(coordinates.getLatitude()));
        origins.append(",");
        origins.append(std::to_string(coordinates.getLongitude()));

        switch (travelMode) {
            case TravelMode::Driving:
                mode = "driving";
                break;
            case TravelMode::Walking:
                mode = "walking";
                break;
            case TravelMode::Bicycling:
                mode = "bicycling";
                break;
            case TravelMode::Transit:
                mode = "transit";
                break;
            default:
                std::cerr << "Warning: unrecognizable travel mode; default to transit mode" << std::endl;
                mode = "transit";
        }

        InfoArray<AnyTwoInfo> infoArr;

        std::string apikey(std::getenv("GOOGLE_DISTANCE_API_KEY"));
        std::string apiEndpoint("https://maps.googleapis.com/maps/api/distancematrix/");
        web::uri apiuri(apiEndpoint);
        web::http::client::http_client client(apiuri);
        web::uri_builder builder("json");
        builder.append_query("origins", origins);
        builder.append_query("destinations", destinations);
        builder.append_query("mode", mode);
        builder.append_query("key", apikey);

        pplx::task<void> async = client.request(web::http::methods::GET, builder.to_string())
        .then([&] (web::http::http_response response) {
            return response.extract_json();
        })
        .then([&] (web::json::value val) {
                 const web::json::array &jsonArr = val.at("rows").as_array();

                 unsigned int i = 0;
                 for (auto aIter = jsonArr.cbegin(); aIter != jsonArr.cend(); ++aIter)
                 {
                     unsigned j = 0;
                     const web::json::array &jsonRow = aIter->at("elements").as_array();
                     for (auto bIter = jsonRow.cbegin(); bIter != jsonRow.cend(); ++bIter)
                     {
                         const web::json::value &duration = bIter->at("duration");
                         const web::json::value &distance = bIter->at("distance");
                         const web::json::value &duraVal = duration.at("value");
                         const web::json::value &distVal = distance.at("value");
                         const web::json::value &duraText = duration.at("text");
                         const web::json::value &distText = distance.at("text");
                         AnyTwoInfo anyTwoInfo(duraVal.as_integer() / 60, duraText.as_string(), distVal.as_integer(), distText.as_string());
                         infoArr.add(anyTwoInfo);
                         ++j;
                    }
                    ++i;
                 }
        });

        try {
            async.wait();
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        edge.getData().setAnyTwoInfoArr(infoArr);

    }

    void ImaClient::printDAG(DAG<RelationInfo, RequestInfo> &infoDAG)
    {
        unsigned int numOfEdges = infoDAG.getNumOfEdges();
        unsigned int numOfNodes = infoDAG.getNumOfNodes();

        std::cout << "# of edges: " << numOfEdges << std::endl;

        for (int i = 0; i < numOfNodes; ++i) {
            std::cout << "Node " << i << std::endl;
            for (auto x: infoDAG.getNode(i).getINodeId()) {
                std::cout << "Edge " << infoDAG.getEdge(x, i).getEdgeId() << " from Node " << x << std::endl;
            }
            for (auto x: infoDAG.getNode(i).getONodeId()) {
                std::cout << "Edge " << infoDAG.getEdge(i, x).getEdgeId() << " to Node " << x << std::endl;
            }
            std::cout << std::endl;
        }

        for (int i = 0; i < numOfEdges; ++i) {
            HotelArray &arr = infoDAG.getEdgeData(i).getHotelArr();
            std::cout << "# of Hotels: "<< arr.getNumOfHotels() << std::endl;
            std::cout << "==================== Hotel List ====================" << std::endl;
            for (int i = 0; i < arr.getNumOfHotels(); ++i) {
                arr[i].printInfo();
            }
        }
    }

}

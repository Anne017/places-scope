#ifndef SCOPE_QUERY_H_
#define SCOPE_QUERY_H_

#include <api/client.h>

#include <unity/scopes/SearchQueryBase.h>
#include <unity/scopes/ReplyProxyFwd.h>

#include <scope/localization.h>

namespace scope {

class CatTypes {
public:
    std::map<std::string, std::string> TYPES_EST;
    std::pair<std::string, std::string> TYPES_EST_ALL;
    std::map<std::string, std::string> TYPES_EST_FUN;
    std::pair<std::string, std::string> TYPES_EST_FUN_ALL;
    std::map<std::string, std::string> TYPES_EST_WORSH;
    std::pair<std::string, std::string> TYPES_EST_WORSH_ALL;
    std::map<std::string, std::string> TYPES_EST_STORE;
    std::pair<std::string, std::string> TYPES_EST_STORE_ALL;
    std::map<std::string, std::string> TYPES_EST_LODGING;
    std::pair<std::string, std::string> TYPES_EST_LODGING_ALL;
    std::map<std::string, std::string> TYPES_EST_TRANSPORT;
    std::pair<std::string, std::string> TYPES_EST_TRANSPORT_ALL;
    std::map<std::string, std::string> TYPES_EST_FOOD;
    std::pair<std::string, std::string> TYPES_EST_FOOD_ALL;
    std::map<std::string, std::string> TYPES_HEALTH;
    std::pair<std::string, std::string> TYPES_HEALTH_ALL;
    std::map<std::string, std::string> TYPES_FINANCE;
    std::pair<std::string, std::string> TYPES_FINANCE_ALL;
    CatTypes() {}
    void set() {
        TYPES_EST_ALL = {_("Establishments"), "establishment"};
        TYPES_EST = {
            {_("Art gallery"), "art_gallery"},
            {_("Atm"), "atm"},
            {_("Beauty Salon"), "beauty_salon"},
            {_("Car Rental"), "car_rental"},
            {_("Car Repair"), "car_repair"},
            {_("Car Wash"), "car_wash"},
            {_("Cemetry"), "cemetery"},
            {_("City Hall"), "city_hall"},
            {_("Courthouse"), "courthouse"},
            {_("Electrician"), "electrician"},
            {_("Embassy"), "embassy"},
            {_("Fire Station"), "fire_station"},
            {_("Florist"), "florist"},
            {_("Funeral Home"), "funeral_home"},
            {_("General Contractor"), "general_contractor"},
            {_("Hair Care"), "hair_care"},
            {_("Hospital"), "hospital"},
            {_("Laundry"), "laundry"},
            {_("Local Government Office"), "local_government_office"},
            {_("Locksmith"), "locksmith"},
            {_("Moving Company"), "moving_company"},
            {_("Painter"), "painter"},
            {_("Plumber"), "plumber"},
            {_("Police"), "police"},
            {_("Post Office"), "post_office"},
            {_("Real Estate Agency"), "real_estate_agency"},
            {_("Roofing Contractor"), "roofing_contractor"},
            {_("School"), "school"},
            {_("Storage"), "storage"},
            {_("Travel Agency"), "travel_agency"},
            {_("University"), "university"}
        };
        TYPES_EST_FUN_ALL = {_("Fun"), "amusement_park|aquarium|bar|bowling_alley|cafe|casino|gym|library|movie_rental|movie_theater|museum|night_club|park|shopping_mall|spa|stadium|zoo"};
        TYPES_EST_FUN = {
            {_("Amusement Park"), "amusement_park"},
            {_("Aquarium"), "aquarium"},
            {_("Bar"), "bar"},
            {_("Bowling Alley"), "bowling_alley"},
            {_("Cafe"), "cafe"},
            {_("Casino"), "casino"},
            {_("Gym"), "gym"},
            {_("Library"), "library"},
            {_("Movie Rental"), "movie_rental"},
            {_("Movie Theater"), "movie_theater"},
            {_("Museum"), "museum"},
            {_("Night Club"), "night_club"},
            {_("Park"), "park"},
            {_("Shopping Mall"), "shopping_mall"},
            {_("Spa"), "spa"},
            {_("Stadium"), "stadium"},
            {_("Zoo"), "zoo"}
        };
        TYPES_EST_WORSH_ALL = {_("Place of Worship"), "place_of_worship"};
        TYPES_EST_WORSH = {
            {_("Church"), "church"},
            {_("Hindu Temple"), "hindu_temple"},
            {_("Mosque"), "mosque"},
            {_("synagogue"), "synagogue"}
        };
        TYPES_EST_STORE_ALL = {_("Store"), "store"};
        TYPES_EST_STORE = {
            {_("Bicycle Store"), "bicycle_store"},
            {_("Book Store"), "book_store"},
            {_("Car Dealer"), "car_dealer"},
            {_("Clothing Store"), "clothing_store"},
            {_("Convenience Store"), "convenience_store"},
            {_("Department Store"), "department_store"},
            {_("Electronics Store"), "electronics_store"},
            {_("Furniture Store"), "furniture_store"},
            {_("Grocery or Supermarket"), "grocery_or_supermarket"},
            {_("Hardware Store"), "hardware_store"},
            {_("Home Goods Store"), "home_goods_store"},
            {_("Jewelry Store"), "jewelry_store"},
            {_("Liquor Store"), "liquor_store"},
            {_("Pet Store"), "pet_store"},
            {_("Shoe Store"), "shoe_store"}
        };
        TYPES_EST_LODGING_ALL = {_("Lodging"), "lodging"};
        TYPES_EST_LODGING = {
            {_("Campground"), "campground"},
            {_("RV Park"), "rv_park"}
        };
        TYPES_EST_TRANSPORT_ALL = {_("Transport"), "airport|bus_station|gas_station|parking|subway_station|taxi_stand|train_station"};
        TYPES_EST_TRANSPORT = {
            {_("Airport"), "airport"},
            {_("Bus Station"), "bus_station"},
            {_("Gas Station"), "gas_station"},
            {_("Parking"), "parking"},
            {_("Subway Station"), "subway_station"},
            {_("Taxi Stand"), "taxi_stand"},
            {_("Train Station"), "train_station"}
        };
        TYPES_EST_FOOD_ALL = {_("Food"), "food"};
        TYPES_EST_FOOD = {
            {_("Bakery"), "bakery"},
            {_("Meal Delivery"), "meal_delivery"},
            {_("Meal Takeaway"), "meal_takeaway"},
            {_("Restaurant"), "restaurant"}
        };
        TYPES_HEALTH_ALL = {_("Health"), "health"};
        TYPES_HEALTH = {
            {_("Doctor"), "doctor"},
            {_("Dentist"), "dentist"},
            {_("Pharmacy"), "pharmacy"},
            {_("Physiotherapist"), "physiotherapist"},
            {_("Veterinary Care"), "veterinary_care"}
        };
        TYPES_FINANCE_ALL = {_("Finance"), "finance"};
        TYPES_FINANCE = {
            {_("Bank"), "bank"},
            {_("Lawyer"), "lawyer"},
            {_("Insurance Agency"), "insurance_agency"}
        };
    }
};

/**
 * Represents an individual query.
 *
 * A new Query object will be constructed for each query. It is
 * given query information, metadata about the search, and
 * some scope-specific configuration.
 */
class Query: public unity::scopes::SearchQueryBase {
public:
    Query(const unity::scopes::CannedQuery &query,
          const unity::scopes::SearchMetadata &metadata, api::Config::Ptr config);

    ~Query() = default;

    void cancelled() override;

    void run(const unity::scopes::SearchReplyProxy &reply) override;

private:
    api::Client client_;
    void initScope();
    int s_radius;
    CatTypes constTypes;
};

}

#endif // SCOPE_QUERY_H_



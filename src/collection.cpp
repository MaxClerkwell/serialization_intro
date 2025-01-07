#include "collection.hpp"
#include <iomanip>
#include <sstream>

void Collection::add_thingee() {
    thingees.emplace_back();
}

void Collection::add_thingee(const nlohmann::json &j) {
    thingees.emplace_back(j);
}

nlohmann::json Collection::dump_json() const {
    nlohmann::json j_array = nlohmann::json::array();
    for (const auto &thingee : thingees) {
        j_array.push_back(thingee.dump_json());
    }
    return j_array;
}

void Collection::remove_thingee(const std::string &uuid) {
    auto it = std::remove_if(thingees.begin(), thingees.end(),
                             [&uuid](const Thingee_T &t) { return t.dump_json().at("uuid") == uuid; });
    thingees.erase(it, thingees.end());
}

double Collection::calculate_value() const {
    double total = 0.0;
    for (const auto &thingee : thingees) {
        total += thingee.dump_json().at("dollar_value").get<double>();
    }
    return total;
}

// Pretty-Print Funktion
std::string Collection::pretty_print() const {
    std::ostringstream output;
    output << "Collection of Thingees:\n";
    output << "=======================\n";

    if (thingees.empty()) {
        output << "No Thingees in the collection.\n";
        return output.str();
    }

    for (const auto &thingee : thingees) {
        auto json = thingee.dump_json();
        output << "UUID: " << json.at("uuid") << "\n";
        output << "Value: $" << std::fixed << std::setprecision(2) << json.at("dollar_value").get<double>() << "\n";
        output << "-----------------------\n";
    }

    output << "Total Value: $" << std::fixed << std::setprecision(2) << calculate_value() << "\n";
    return output.str();
}

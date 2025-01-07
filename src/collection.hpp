#ifndef COLLECTION_HPP
#define COLLECTION_HPP

#include "thingee.hpp"
#include <vector>
#include <string>

class Collection {
    std::vector<Thingee_T> thingees;

public:
    void add_thingee();
    void add_thingee(const nlohmann::json &j);
    nlohmann::json dump_json() const;
    void remove_thingee(const std::string &uuid);
    double calculate_value() const;

    // Pretty-Print Funktion für die Konsolenausgabe
    std::string pretty_print() const;
};

#endif // COLLECTION_HPP

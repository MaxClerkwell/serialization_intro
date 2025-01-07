#ifndef THINGEE_HPP
#define THINGEE_HPP

#include <string>
#include <nlohmann/json.hpp>

class Thingee_T {
    std::string uuid;
    double dollar_value;

public:
    // Default-Konstruktor: generiert zufällige UUID und Dollar-Wert
    Thingee_T();

    // Konstruktor: erstellt Thingee_T aus einem JSON-Objekt
    Thingee_T(const nlohmann::json &j);

    // Methode: Gibt das Objekt als JSON zurück
    nlohmann::json dump_json() const;
};

#endif // THINGEE_HPP

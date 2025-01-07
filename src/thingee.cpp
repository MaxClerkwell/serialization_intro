#include "thingee.hpp"
#include <random>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <uuid/uuid.h>

// Helper-Funktion: Runden auf zwei Nachkommastellen
double round_to_two_decimals(double value) {
    return std::round(value * 100.0) / 100.0;
}

// Default-Konstruktor: Generiert zufällige UUID und Dollarwert mit zwei Nachkommastellen
Thingee_T::Thingee_T() {
    // Generiere zufällige UUID
    uuid_t bin_uuid;
    uuid_generate(bin_uuid);
    char uuid_str[37];
    uuid_unparse(bin_uuid, uuid_str);
    uuid = uuid_str;

    // Generiere zufälligen Dollarwert (zwischen 1.00 und 100.00)
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(1.0, 100.0);
    dollar_value = round_to_two_decimals(dis(gen));
}

// Konstruktor: Erstelle Thingee_T aus einem JSON-Objekt
Thingee_T::Thingee_T(const nlohmann::json &j) {
    try {
        uuid = j.at("uuid").get<std::string>();
        dollar_value = j.at("dollar_value").get<double>();

        // Validierung: Dollarwert auf zwei Nachkommastellen prüfen
        if (round_to_two_decimals(dollar_value) != dollar_value) {
            throw std::invalid_argument("Dollar value must have exactly two decimal places.");
        }

        dollar_value = round_to_two_decimals(dollar_value);
    } catch (const nlohmann::json::exception &e) {
        throw std::invalid_argument("Invalid JSON structure for Thingee_T: " + std::string(e.what()));
    }
}

// Methode: Gibt das Objekt als JSON zurück
nlohmann::json Thingee_T::dump_json() const {
    return nlohmann::json{{"uuid", uuid}, {"dollar_value", dollar_value}};
}

#include "CLI/CLI.hpp"
#include "thingee.hpp"
#include "collection.hpp"
#include <fstream>
#include <iostream>

int main(int argc, char **argv) {
    CLI::App app{"Thingee Collection"};

    std::string filePath;
    app.add_option("-f,--file", filePath, "Input file path");

    std::string outputPath;
    app.add_option("-o,--output", outputPath, "Output file path");

    int generateCount = 0;
    app.add_option("-g,--generate", generateCount, "Generate a collection of Thingees");

    std::string removeUuid;
    app.add_option("-r,--remove", removeUuid, "Remove a Thingee by UUID");

    CLI11_PARSE(app, argc, argv);

    Collection collection;
    // Prüfe, ob ein Filepath angegeben wurde und lade die Collection
if (!filePath.empty()) {
    std::ifstream inFile(filePath);
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open file " << filePath << std::endl;
        return 1;
    }

    nlohmann::json j;
    inFile >> j;
    for (const auto &thingee_json : j) {
        collection.add_thingee(thingee_json);
    }
}

// Prüfe, ob -g/--generate angegeben wurde und füge entsprechende Anzahl Thingees hinzu
if (generateCount > 0) {
    for (int i = 0; i < generateCount; ++i) {
        collection.add_thingee();
    }
}

// Prüfe, ob -r/--remove angegeben wurde und entferne Thingee anhand der UUID
if (!removeUuid.empty()) {
    collection.remove_thingee(removeUuid);
}

// Prüfe, ob -o/--output angegeben wurde und schreibe die Collection in die Datei
if (!outputPath.empty()) {
    std::ofstream outFile(outputPath);
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open output file " << outputPath << std::endl;
        return 1;
    }

    outFile << collection.dump_json().dump(4);
} else {
    // Andernfalls gebe die Collection im Terminal aus
    std::cout << collection.pretty_print() << std::endl;
}


    return 0;
}
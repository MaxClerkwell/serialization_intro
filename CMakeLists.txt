cmake_minimum_required(VERSION 3.15)
project(ThingeeCollection)

# FetchContent für CLI11 und nlohmann/json
include(FetchContent)

FetchContent_Declare(
    CLI11
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG v2.3.2
)
FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.2
)

FetchContent_MakeAvailable(CLI11 json)

# Hauptanwendung
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/thingee.cpp
    src/collection.cpp
)

# Verlinke Bibliotheken
target_link_libraries(${PROJECT_NAME} PRIVATE CLI11::CLI11 nlohmann_json::nlohmann_json uuid)

# Include-Directories
target_include_directories(${PROJECT_NAME} PRIVATE ${CLI11_SOURCE_DIR}/include)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED YES)

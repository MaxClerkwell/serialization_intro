# Thingee Collection

## Overview
This project demonstrates a C++ application that uses the **CLI11** and **nlohmann/json** libraries to manage, serialize, and deserialize internal data objects. It focuses on the following key concepts:

1. **Object-Oriented Design:** Classes like `Thingee_T` and `Collection` encapsulate application logic and data.
2. **Serialization and Deserialization:** Data objects are saved to JSON format for persistence and later restored.
3. **Command-Line Interaction:** The CLI11 library is used for robust handling of command-line arguments.

The main purpose of this application is to showcase how internal data objects can be serialized to store the state of the application and deserialized to resume from that state. This is analogous to how word processor files (e.g., Microsoft Word documents) store the state of an application, allowing the user to save their work and reload it later. By serializing a document to a file, the application saves its current state, which can then be restored through deserialization.

---

## Features

### Core Functionalities
1. **Manage Individual Objects (`Thingee_T`)**:
   - Each `Thingee_T` object has a randomly generated UUID and a dollar value rounded to two decimal places.
   - `Thingee_T` can be constructed from a JSON object or serialized to JSON.

2. **Manage a Collection of Objects (`Collection`)**:
   - A `Collection` holds multiple `Thingee_T` objects in a `std::vector`.
   - Objects can be added (randomly generated or from JSON).
   - Objects can be removed by their UUID.
   - The total value of all objects can be calculated.
   - Supports pretty-printed output for the console and serialized JSON for persistence.

3. **Command-Line Interface**:
   - Generate new objects (`-g` or `--generate`) and add them to the collection.
   - Load a collection from a file (`-f` or `--file`).
   - Remove an object by UUID (`-r` or `--remove`).
   - Save the collection to a file (`-o` or `--output`).
   - Display the collection in the terminal if no file output is specified.

### Serialization and Deserialization
- **Serialization:** Converts the current state of the `Collection` to JSON and saves it to a file. This allows the state to be restored later.
- **Deserialization:** Reads a JSON file and reconstructs the `Collection` and its `Thingee_T` objects.

This process is designed to preserve the state of the application. For example, if you generate a collection of `Thingee_T` objects and save it, you can later reload it and resume operations without losing any data.

---

## Why Serialization?
Serialization is a critical concept in software engineering for:

- **State Preservation:** By saving application data as JSON, the state can be restored later.
- **Data Interchange:** JSON is a widely used format that allows data to be shared across platforms and programming languages.
- **Crash Recovery:** Serialized data can act as a snapshot of the application's state, enabling recovery in case of a crash.

### Analogy: Word Documents
Consider Microsoft Word. When you save a Word document, you are serializing the state of the application at that moment—the text, formatting, and layout are all written to a file. When you reopen the document, the application deserializes the file, restoring the state so you can continue editing.

This project applies the same principle:
- The `Collection` and its `Thingee_T` objects represent the state of the application.
- JSON serialization ensures that this state can be saved and restored seamlessly.

---

## Usage

### Build Instructions

1. Clone the repository and navigate to the project directory.
2. Build the project using CMake:

   ```bash
   cmake -B build && cmake --build ./build
   ```

3. The executable file will be located in the `build` directory.

### Command-Line Options

#### Generate New Objects
Generate a specified number of random `Thingee_T` objects and add them to the collection:

```bash
./ThingeeCollection -g <count>
```

- Example: Generate 5 objects and display them in the console:
  ```bash
  ./ThingeeCollection -g 5
  ```
- Example: Generate 10 objects and save them to a file:
  ```bash
  ./ThingeeCollection -g 10 -o collection.json
  ```

#### Load from File
Load a collection from a file and display it in the console:

```bash
./ThingeeCollection -f <file>
```

- Example:
  ```bash
  ./ThingeeCollection -f collection.json
  ```

#### Remove an Object
Remove an object from the collection by its UUID:

```bash
./ThingeeCollection -f <file> -r <uuid>
```

- Example:
  ```bash
  ./ThingeeCollection -f collection.json -r 123e4567-e89b-12d3-a456-426614174000
  ```

#### Save to File
Save the current state of the collection to a file:

```bash
./ThingeeCollection -o <file>
```

- If no output file is specified, the collection is displayed in the console.

---

## Example Workflow

1. Generate 5 random objects and save them to a file:
   ```bash
   ./ThingeeCollection -g 5 -o my_collection.json
   ```

2. Load the collection from the file and display it:
   ```bash
   ./ThingeeCollection -f my_collection.json
   ```

3. Remove an object by UUID and overwrite the file:
   ```bash
   ./ThingeeCollection -f my_collection.json -r 123e4567-e89b-12d3-a456-426614174000
   ```

4. Add 3 new random objects and save to a new file:
   ```bash
   ./ThingeeCollection -f my_collection.json -g 3 -o updated_collection.json
   ```

---

## Key Classes and Methods

### Thingee_T
- **Attributes:**
  - `uuid`: A unique identifier for the object.
  - `dollar_value`: A random monetary value rounded to two decimal places.
- **Methods:**
  - `Thingee_T()`: Default constructor generates random values.
  - `Thingee_T(const nlohmann::json &j)`: Constructs a `Thingee_T` object from JSON.
  - `dump_json()`: Serializes the object to JSON.

### Collection
- **Attributes:**
  - `thingees`: A `std::vector` of `Thingee_T` objects.
- **Methods:**
  - `add_thingee()`: Adds a randomly generated object.
  - `add_thingee(const nlohmann::json &j)`: Adds an object from JSON.
  - `remove_thingee(const std::string &uuid)`: Removes an object by its UUID.
  - `calculate_value()`: Computes the total dollar value of the collection.
  - `dump_json()`: Serializes the collection to JSON.
  - `pretty_print()`: Returns a human-readable string representation of the collection.

---

## Conclusion
This project highlights the power of serialization in managing and persisting the state of an application. By leveraging modern libraries like CLI11 and nlohmann/json, the application demonstrates:

- Efficient state management through serialization and deserialization.
- Clean and modular object-oriented design.
- Practical use of command-line interfaces for real-world applications.

Whether saving a document in a word processor or managing a collection of data objects, serialization ensures that the application's state can be preserved and resumed seamlessly.


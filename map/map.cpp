#include <iostream>
#include <map>       // Required for using the std::map container
#include <stdexcept> // Required for catching exceptions from map::at()

// This program demonstrates the usage of various std::map functions.
// All explanations are provided directly within the comments of the code.

int main() {
    std::cout << "--- Part 1: Modifiers (insert, operator[]) ---\n";

    // 1. Creating a map with string keys and integer values
    std::map<std::string, int> myMap;

    // 2. insert(pair) - Inserts a key-value pair
    // The key must be unique. The insertion will fail if the key already exists.
    myMap.insert(std::pair<std::string, int>("apple", 1));
    myMap.insert(std::make_pair("banana", 2));
    myMap.insert({"cherry", 3});
    std::cout << "Initial map size after inserts: " << myMap.size() << "\n";

    // 3. operator[](key) - Inserts or updates a value
    // If the key exists, it updates the value. If not, it inserts a new pair.
    myMap["durian"] = 4; // Inserts a new element
    myMap["apple"] = 5;  // Updates the value for the key "apple"
    std::cout << "Map after using operator[]: ";
    for (const auto& pair : myMap) {
        std::cout << "{" << pair.first << ": " << pair.second << "} ";
    }
    std::cout << "\n\n";

    // --- Part 2: Element Access and Capacity ---\n
    
    // 4. at(key) - Accesses an element with bounds checking
    // This is the safer way to access elements, as it throws an exception if the key is not found.
    try {
        std::cout << "Value for 'apple' (using at()): " << myMap.at("apple") << "\n";
        // The line below will throw an exception since "grape" is not in the map.
        // std::cout << "Value for 'grape': " << myMap.at("grape") << "\n";
    } catch (const std::out_of_range& e) {
        std::cerr << "Caught exception: " << e.what() << "\n";
    }

    // 5. empty() - Checks if the map is empty
    // Returns true if size is 0, false otherwise.
    if (!myMap.empty()) {
        std::cout << "The map is not empty.\n";
    }

    // 6. size() - Returns the number of key-value pairs
    std::cout << "The current number of elements in the map is: " << myMap.size() << "\n\n";

    // --- Part 3: Operations and Searching ---\n

    // 7. find(key) - Searches for a key
    // Returns an iterator to the element if found, otherwise returns myMap.end().
    auto it = myMap.find("banana");
    if (it != myMap.end()) {
        std::cout << "Found 'banana' with value: " << it->second << "\n";
    } else {
        std::cout << "'banana' was not found.\n";
    }

    // 8. count(key) - Returns 1 if the key exists, 0 otherwise
    // For std::map, this is a simple check for existence.
    if (myMap.count("cherry")) {
        std::cout << "'cherry' is present in the map.\n";
    } else {
        std::cout << "'cherry' is not present in the map.\n";
    }

    // 9. erase(key) - Removes an element
    // Removes the element with the specified key. Returns the number of elements erased (1 or 0).
    myMap.erase("banana");
    std::cout << "Map size after erasing 'banana': " << myMap.size() << "\n\n";
    
    // --- Part 4: Iterators and Other Modifiers ---\n

    // 10. Iterating through the map using iterators
    // begin() and end() are used to get iterators for looping.
    std::cout << "Iterating through the map with begin() and end():\n";
    for (auto it_loop = myMap.begin(); it_loop != myMap.end(); ++it_loop) {
        std::cout << "{" << it_loop->first << ": " << it_loop->second << "} ";
    }
    std::cout << "\n";

    // 11. swap(other) - Swaps the contents of two maps efficiently
    std::map<std::string, int> otherMap;
    otherMap["grape"] = 10;
    otherMap["kiwi"] = 20;

    std::cout << "Before swap, myMap size: " << myMap.size() << ", otherMap size: " << otherMap.size() << "\n";
    myMap.swap(otherMap);
    std::cout << "After swap, myMap size: " << myMap.size() << ", otherMap size: " << otherMap.size() << "\n";
    std::cout << "myMap now contains: ";
    for (const auto& pair : myMap) {
        std::cout << "{" << pair.first << ": " << pair.second << "} ";
    }
    std::cout << "\n\n";

    // 12. clear() - Removes all key-value pairs
    myMap.clear();
    std::cout << "Map size after clear(): " << myMap.size() << "\n";

    return 0;
}

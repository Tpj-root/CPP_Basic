### source

```
https://cplusplus.com/reference/map/map/
```



### Constructors and Assignment
* **`map()`**
    Creates an empty map. You can also specify a custom comparison object for ordering keys.
* **`map(first, last)`**
    Creates a map with a copy of a range of elements. The new map will contain elements from the range `[first, last)`.

***

### Capacity and Size
* **`empty()`**
    Checks if the map is empty. It returns `true` if there are no key-value pairs and `false` otherwise.
* **`size()`**
    Returns the number of key-value pairs in the map. This gives you the current logical size of the container.
* **`max_size()`**
    Returns the maximum number of elements the map can hold. This value is typically limited by the system's memory.

***

### Iterators
* **`begin()` and `end()`**
    `begin()` returns an iterator to the first element (the one with the smallest key). `end()` returns a "past-the-end" iterator, which marks the position after the last element.
* **`rbegin()` and `rend()`**
    `rbegin()` returns a reverse iterator pointing to the last element (the one with the largest key). `rend()` returns a reverse iterator pointing before the first element.
* **`cbegin()` and `cend()`**
    `cbegin()` and `cend()` return `const` iterators. They are used for iterating through the map when you don't intend to modify its contents.

***

### Element Access
* **`at(key)`**
    Returns a reference to the value associated with the `key`. If the key is not found, it throws an `out_of_range` exception.
* **`operator[](key)`**
    Returns a reference to the value associated with the `key`. If the key is not found, a new element with that key is inserted with a default-constructed value.
* **`find(key)`**
    Searches the container for an element with a key equivalent to `key`. It returns an iterator to the element if found, or `end()` if not.

***

### Modifiers
* **`insert(val)`**
    Inserts a new key-value pair `val` into the map. If an element with the same key already exists, the insertion is ignored.
* **`erase(key)`**
    Removes the element with the specified `key` from the map. It returns the number of elements erased (either 0 or 1).
* **`clear()`**
    Removes all key-value pairs from the map. The map becomes empty.
* **`swap(other)`**
    Exchanges the contents of the map with another map `other`. This is a very efficient operation that does not involve copying or moving elements.
* **`emplace(args...)`**
    Constructs a new key-value pair in-place. This can be more efficient than `insert()` for complex objects.

***

### Operations
* **`count(key)`**
    Searches the container for an element with a key equivalent to `key`. For `std::map`, this will return either 1 (if the key exists) or 0 (if it doesn't).
* **`lower_bound(key)`**
    Returns an iterator to the first element that is not less than `key`. This is useful for finding the potential insertion point for a new element.
* **`upper_bound(key)`**
    Returns an iterator to the first element that is greater than `key`. This helps define a range of elements.


```
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


```
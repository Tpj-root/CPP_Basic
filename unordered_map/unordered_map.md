### source

```
https://cplusplus.com/reference/unordered_map/unordered_map/
```


### Constructors and Assignment
* **`unordered_map()`**
    Creates an empty unordered map. You can also specify the initial bucket count, a hash function, or an equality predicate.
* **`unordered_map(first, last)`**
    Creates an unordered map with a copy of a range of elements. The new map will contain elements from the range `[first, last)`.

***

### Capacity and Size
* **`empty()`**
    Checks if the unordered map is empty. It returns `true` if there are no key-value pairs and `false` otherwise.
* **`size()`**
    Returns the number of key-value pairs in the map. This gives you the current logical size of the container.
* **`max_size()`**
    Returns the maximum number of elements the unordered map can hold. This value is typically limited by the system's memory.

***

### Iterators
* **`begin()` and `end()`**
    `begin()` returns an iterator to the first element in the unordered map. `end()` returns a "past-the-end" iterator, which marks the position after the last element.
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
    Searches the container for an element with a key equivalent to `key`. For `std::unordered_map`, this will return either 1 (if the key exists) or 0 (if it doesn't).

***

### Bucket Interface
* **`bucket_count()`**
    Returns the number of buckets in the container.
* **`load_factor()`**
    Returns the average number of elements per bucket. This value gives an indication of how "full" the hash table is.
* **`max_load_factor()`**
    Gets or sets the maximum load factor for the container. The container will rehash to maintain a load factor at or below this value.
* **`rehash(n)`**
    Sets the number of buckets to `n` and rehashes all elements. This can be used to manually optimize the hash table performance.
* **`reserve(n)`**
    Requests that the container be able to hold at least `n` elements without reallocating. This can improve performance by pre-allocating buckets.


```
#include <iostream>
#include <unordered_map> // Required for using the std::unordered_map container
#include <stdexcept>     // Required for catching exceptions from at()

// This program demonstrates the usage of various std::unordered_map functions.
// All explanations are provided directly within the comments of the code.

int main() {
    std::cout << "--- Part 1: Constructors and Modifiers (insert, operator[]) ---\n";

    // 1. Creating an empty unordered_map with string keys and integer values
    std::unordered_map<std::string, int> myMap;

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

    // 4. emplace(args...) - Constructs a new element in-place
    // This can be more efficient than insert() for complex objects.
    myMap.emplace("elderberry", 6);
    std::cout << "Map after emplace: ";
    for (const auto& pair : myMap) {
        std::cout << "{" << pair.first << ": " << pair.second << "} ";
    }
    std::cout << "\n\n";


    std::cout << "--- Part 2: Element Access and Capacity ---\n";
    
    // 5. at(key) - Accesses an element with bounds checking
    // This is the safer way to access elements, as it throws an exception if the key is not found.
    try {
        std::cout << "Value for 'apple' (using at()): " << myMap.at("apple") << "\n";
        // The line below will throw an exception since "grape" is not in the map.
        // std::cout << "Value for 'grape': " << myMap.at("grape") << "\n";
    } catch (const std::out_of_range& e) {
        std::cerr << "Caught exception: " << e.what() << "\n";
    }

    // 6. empty() - Checks if the map is empty
    // Returns true if size is 0, false otherwise.
    if (!myMap.empty()) {
        std::cout << "The map is not empty.\n";
    }

    // 7. size() - Returns the number of key-value pairs
    std::cout << "The current number of elements in the map is: " << myMap.size() << "\n\n";

    // --- Part 3: Operations and Searching ---\n

    // 8. find(key) - Searches for a key
    // Returns an iterator to the element if found, otherwise returns myMap.end().
    auto it = myMap.find("banana");
    if (it != myMap.end()) {
        std::cout << "Found 'banana' with value: " << it->second << "\n";
    } else {
        std::cout << "'banana' was not found.\n";
    }

    // 9. count(key) - Returns 1 if the key exists, 0 otherwise
    // For std::unordered_map, this is a simple check for existence.
    if (myMap.count("cherry")) {
        std::cout << "'cherry' is present in the map.\n";
    } else {
        std::cout << "'cherry' is not present in the map.\n";
    }

    // 10. erase(key) - Removes an element
    // Removes the element with the specified key. Returns the number of elements erased (1 or 0).
    myMap.erase("banana");
    std::cout << "Map size after erasing 'banana': " << myMap.size() << "\n\n";
    
    // --- Part 4: Iterators and Other Modifiers ---\n

    // 11. Iterating through the map using iterators
    // The order of iteration is not guaranteed and can change after modifications.
    std::cout << "Iterating through the map with begin() and end():\n";
    for (auto it_loop = myMap.begin(); it_loop != myMap.end(); ++it_loop) {
        std::cout << "{" << it_loop->first << ": " << it_loop->second << "} ";
    }
    std::cout << "\n";

    // 12. swap(other) - Swaps the contents of two maps efficiently
    std::unordered_map<std::string, int> otherMap;
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

    // 13. clear() - Removes all key-value pairs
    myMap.clear();
    std::cout << "Map size after clear(): " << myMap.size() << "\n";

    return 0;
}


```
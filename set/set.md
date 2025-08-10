### source

```
https://cplusplus.com/reference/set/set/
```


### Constructors and Assignment
* **`set()`**
    Creates an empty set. You can also specify a custom comparison object for ordering elements.
* **`set(first, last)`**
    Creates a set with a copy of a range of elements. The new set will contain unique elements from the range `[first, last)`.

***

### Capacity and Size
* **`empty()`**
    Checks if the set is empty. It returns `true` if there are no elements and `false` otherwise.
* **`size()`**
    Returns the number of elements in the set. This gives you the current logical size of the container.
* **`max_size()`**
    Returns the maximum number of elements the set can hold. This value is typically limited by the system's memory.

***

### Iterators
* **`begin()` and `end()`**
    `begin()` returns an iterator to the first element (the smallest element). `end()` returns a "past-the-end" iterator, which marks the position after the last element.
* **`rbegin()` and `rend()`**
    `rbegin()` returns a reverse iterator pointing to the last element (the largest element). `rend()` returns a reverse iterator pointing before the first element.
* **`cbegin()` and `cend()`**
    `cbegin()` and `cend()` return `const` iterators. They are used for iterating through the set when you don't intend to modify its contents.

***

### Modifiers
* **`insert(val)`**
    Inserts a new element `val` into the set. If an element with the same value already exists, the insertion is ignored.
* **`erase(val)`**
    Removes the element with the specified value `val` from the set. It returns the number of elements erased (either 0 or 1).
* **`clear()`**
    Removes all elements from the set. The set becomes empty.
* **`swap(other)`**
    Exchanges the contents of the set with another set `other`. This is a very efficient operation that does not involve copying or moving elements.
* **`emplace(args...)`**
    Constructs a new element in-place. This can be more efficient than `insert()` for complex objects.

***

### Operations
* **`count(val)`**
    Searches the container for an element with a value equivalent to `val`. For `std::set`, this will return either 1 (if the value exists) or 0 (if it doesn't).
* **`find(val)`**
    Searches the container for an element with a value equivalent to `val`. It returns an iterator to the element if found, or `end()` if not.
* **`lower_bound(val)`**
    Returns an iterator to the first element that is not less than `val`. This is useful for finding the potential insertion point for a new element.
* **`upper_bound(val)`**
    Returns an iterator to the first element that is greater than `val`. This helps define a range of elements.
* **`equal_range(val)`**
    Returns a pair of iterators that define the range of elements with a value equivalent to `val`. For `std::set`, this range will contain at most one element.


```
#include <iostream>
#include <set>       // Required for using the std::set container
#include <stdexcept> // Good practice for robust code

// This program demonstrates the usage of various std::set functions.
// All explanations are provided directly within the comments of the code.

int main() {
    std::cout << "--- Part 1: Constructors and Modifiers (insert, emplace) ---\n";

    // 1. Creating an empty set of integers
    std::set<int> mySet;

    // 2. insert(value) - Inserts a new element
    // std::set automatically keeps elements sorted and stores only unique values.
    // The insert function returns a pair: an iterator to the element and a bool
    // indicating if the insertion took place.
    std::cout << "Inserting elements 30, 10, 20, 10 into the set.\n";
    auto result1 = mySet.insert(30);
    auto result2 = mySet.insert(10);
    mySet.insert(20);
    auto result3 = mySet.insert(10); // This will be ignored because 10 already exists.

    // Check the result of the insertion to see if a new element was added.
    if (!result3.second) {
        std::cout << "Element 10 was not inserted because it already exists.\n";
    }

    // After insertions, the set will be sorted internally: {10, 20, 30}
    std::cout << "Current set contents: ";
    for (int val : mySet) {
        std::cout << val << " ";
    }
    std::cout << "\n\n";

    // 3. emplace(args...) - Constructs an element in-place
    // This can be more efficient than insert() for complex objects.
    std::cout << "Emplacing element 40 to the set.\n";
    mySet.emplace(40);
    std::cout << "Set after emplace(40): ";
    for (int val : mySet) {
        std::cout << val << " ";
    }
    std::cout << "\n\n";

    // --- Part 2: Capacity and Element Access ---\n
    
    // 4. size() - Returns the number of elements
    std::cout << "The current number of elements in the set is: " << mySet.size() << "\n";

    // 5. empty() - Checks if the set is empty
    // Returns true if size is 0, false otherwise.
    if (!mySet.empty()) {
        std::cout << "The set is not empty.\n";
    }

    // 6. count(value) - Returns 1 if the value exists, 0 otherwise
    // This is a simple and efficient way to check for element existence.
    if (mySet.count(20)) {
        std::cout << "Element 20 is present in the set.\n";
    }

    // 7. find(value) - Searches for a value
    // Returns an iterator to the element if found, otherwise returns mySet.end().
    auto it_find = mySet.find(30);
    if (it_find != mySet.end()) {
        std::cout << "Found element " << *it_find << " using find().\n\n";
    }

    // --- Part 3: Operations, Iterators, and Removal ---\n

    // 8. begin() and end() - Used for iteration
    // The elements are automatically iterated in sorted order.
    std::cout << "Iterating through the set with begin() and end():\n";
    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n\n";

    // 9. lower_bound(value) - Finds the first element not less than value
    // This is useful for finding a starting point in a sorted range.
    auto it_lower = mySet.lower_bound(25);
    if (it_lower != mySet.end()) {
        std::cout << "lower_bound(25) points to element: " << *it_lower << "\n";
    }

    // 10. upper_bound(value) - Finds the first element greater than value
    // This helps define the end of a range.
    auto it_upper = mySet.upper_bound(25);
    if (it_upper != mySet.end()) {
        std::cout << "upper_bound(25) points to element: " << *it_upper << "\n\n";
    }

    // 11. erase(value) - Removes an element with a specific value
    // The erase function returns the number of elements erased (which will be 0 or 1 for std::set).
    int elements_erased = mySet.erase(30);
    std::cout << "After erasing element 30, " << elements_erased << " element(s) were removed.\n";
    std::cout << "Set after erase: ";
    for (int val : mySet) {
        std::cout << val << " ";
    }
    std::cout << "\n\n";

    // 12. swap(other) - Swaps the contents of two sets efficiently
    std::set<int> otherSet = {50, 60};
    std::cout << "Before swap, mySet size: " << mySet.size() << ", otherSet size: " << otherSet.size() << "\n";
    mySet.swap(otherSet);
    std::cout << "After swap, mySet size: " << mySet.size() << ", otherSet size: " << otherSet.size() << "\n";
    std::cout << "mySet now contains: ";
    for (int val : mySet) {
        std::cout << val << " ";
    }
    std::cout << "\n\n";

    // 13. clear() - Removes all elements
    mySet.clear();
    std::cout << "Set size after clear(): " << mySet.size() << "\n";

    return 0;
}


```
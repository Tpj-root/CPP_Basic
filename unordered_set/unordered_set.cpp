#include <iostream>
#include <unordered_set> // Required for using the std::unordered_set container

// This program demonstrates the usage of various std::unordered_set functions.
// All explanations are provided directly within the comments of the code.

int main() {
    std::cout << "--- Part 1: Constructors and Modifiers (insert, emplace) ---\n";

    // 1. Creating an empty unordered_set of integers
    // The order of elements is not guaranteed with an unordered_set.
    std::unordered_set<int> mySet;

    // 2. insert(value) - Inserts a new element
    // std::unordered_set automatically stores only unique values.
    // The insert function returns a pair: an iterator to the element and a bool
    // indicating if the insertion took place.
    std::cout << "Inserting elements 30, 10, 20, 10 into the set.\n";
    mySet.insert(30);
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(10); // This will be ignored because 10 already exists.

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


    std::cout << "--- Part 2: Capacity and Element Access ---\n";
    
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
    // The order of iteration is not guaranteed and can change after modifications.
    std::cout << "Iterating through the set with begin() and end():\n";
    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n\n";

    // 9. erase(value) - Removes an element with a specific value
    // The erase function returns the number of elements erased (which will be 0 or 1).
    int elements_erased = mySet.erase(30);
    std::cout << "After erasing element 30, " << elements_erased << " element(s) were removed.\n";
    std::cout << "Set after erase: ";
    for (int val : mySet) {
        std::cout << val << " ";
    }
    std::cout << "\n\n";

    // 10. swap(other) - Swaps the contents of two sets efficiently
    std::unordered_set<int> otherSet = {50, 60};
    std::cout << "Before swap, mySet size: " << mySet.size() << ", otherSet size: " << otherSet.size() << "\n";
    mySet.swap(otherSet);
    std::cout << "After swap, mySet size: " << mySet.size() << ", otherSet size: " << otherSet.size() << "\n";
    std::cout << "mySet now contains: ";
    for (int val : mySet) {
        std::cout << val << " ";
    }
    std::cout << "\n\n";

    // 11. clear() - Removes all elements
    mySet.clear();
    std::cout << "Set size after clear(): " << mySet.size() << "\n";

    // --- Part 4: Bucket Interface Functions ---\n
    std::cout << "--- Part 4: Bucket Interface ---\n";
    std::unordered_set<int> bucketSet;
    bucketSet.insert({1, 2, 3, 4, 5, 6, 7});

    // 12. bucket_count() - Returns the number of buckets
    std::cout << "Number of buckets: " << bucketSet.bucket_count() << "\n";

    // 13. load_factor() - Returns the average number of elements per bucket
    std::cout << "Load factor: " << bucketSet.load_factor() << "\n";

    // 14. rehash(n) - Sets the number of buckets to at least n
    // This forces a rehash of all elements into the new bucket structure.
    bucketSet.rehash(20);
    std::cout << "After rehash to 20 buckets, bucket count is now: " << bucketSet.bucket_count() << "\n";

    // 15. reserve(n) - Reserves buckets for at least n elements
    // This is similar to rehash, but it calculates the number of buckets needed automatically.
    bucketSet.reserve(10);
    std::cout << "After reserving space for 10 elements, bucket count is: " << bucketSet.bucket_count() << "\n";

    return 0;
}

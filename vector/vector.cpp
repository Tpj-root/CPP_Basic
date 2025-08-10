#include <iostream>
#include <vector>
#include <stdexcept> // Required for catching exceptions from vector::at()

// This program demonstrates the usage of various std::vector functions.
// All explanations are provided directly within the comments of the code.

int main() {
    // --- PART 1: Capacity and Size Functions ---

    std::cout << "--- Part 1: Capacity and Size ---\n";

    // 1. Creating a vector
    std::vector<int> myVector;
    std::cout << "Initially, myVector is empty. Size: " << myVector.size() << ", Capacity: " << myVector.capacity() << "\n";

    // 2. push_back(value) - Adds elements to the vector
    // The vector will automatically resize (increase capacity) as needed.
    for (int i = 0; i < 5; ++i) {
        myVector.push_back(i * 10);
        std::cout << "After adding " << i * 10 << ": Size = " << myVector.size() << ", Capacity = " << myVector.capacity() << "\n";
    }
    std::cout << "\n";

    // 3. size() - Returns the number of elements in the vector
    // This is the current number of elements you can access.
    std::cout << "The current number of elements in myVector is: " << myVector.size() << "\n";

    // 4. capacity() - Returns the size of the allocated storage
    // This is the total number of elements the vector can hold without reallocating memory.
    std::cout << "The current allocated memory can hold up to " << myVector.capacity() << " elements.\n";

    // 5. empty() - Checks if the vector is empty
    // Returns true if size is 0, false otherwise.
    if (!myVector.empty()) {
        std::cout << "myVector is not empty.\n";
    }

    // 6. reserve(n) - Increases the capacity to at least n
    // This can improve performance by pre-allocating memory.
    myVector.reserve(20);
    std::cout << "After reserving space for 20 elements, Capacity is now: " << myVector.capacity() << "\n";
    std::cout << "\n";

    // 7. shrink_to_fit() - Reduces capacity to match size
    // This can be used to free up unused memory if you no longer need the extra capacity.
    myVector.shrink_to_fit();
    std::cout << "After shrinking to fit, Capacity is now: " << myVector.capacity() << "\n";
    std::cout << "\n";

    // 8. max_size() - Returns the maximum possible size
    // This value is system-dependent.
    std::cout << "The maximum size myVector could ever have is: " << myVector.max_size() << "\n";
    std::cout << "--------------------------------\n\n";


    // --- PART 2: Element Access Functions ---

    std::cout << "--- Part 2: Element Access ---\n";

    // The current vector contains: [0, 10, 20, 30, 40]

    // 1. at(index) - Accesses an element with bounds checking
    // This is a safer way to access elements as it throws an exception on invalid access.
    try {
        std::cout << "Element at index 2 (using at()): " << myVector.at(2) << "\n";
        // This will throw an exception.
        // std::cout << "Element at index 10: " << myVector.at(10) << "\n";
    } catch (const std::out_of_range& e) {
        std::cerr << "Caught exception: " << e.what() << "\n";
    }

    // 2. operator[] - Accesses an element without bounds checking
    // This is faster but less safe than at(). Be careful not to go out of bounds.
    std::cout << "Element at index 2 (using []): " << myVector[2] << "\n";

    // 3. front() - Accesses the first element
    // Equivalent to myVector[0].
    std::cout << "First element (using front()): " << myVector.front() << "\n";

    // 4. back() - Accesses the last element
    // Equivalent to myVector[myVector.size() - 1].
    std::cout << "Last element (using back()): " << myVector.back() << "\n";

    // 5. data() - Get a pointer to the underlying array
    // This returns a pointer to the first element.
    int* dataPtr = myVector.data();
    std::cout << "Element at index 2 using pointer: " << *(dataPtr + 2) << "\n";
    std::cout << "--------------------------------\n\n";


    // --- PART 3: Modifiers and Iterators ---

    std::cout << "--- Part 3: Modifiers and Iterators ---\n";

    // Current vector contents: [0, 10, 20, 30, 40]

    // 1. pop_back() - Removes the last element
    myVector.pop_back();
    std::cout << "After pop_back(), the vector has " << myVector.size() << " elements.\n";

    // 2. clear() - Removes all elements
    // The vector size becomes 0, but capacity usually remains the same.
    myVector.clear();
    std::cout << "After clear(), the vector has " << myVector.size() << " elements.\n";

    // Re-populating for further examples
    myVector.push_back(100);
    myVector.push_back(200);
    myVector.push_back(300);

    // 3. insert(position, value) - Inserts a new element
    // This is an expensive operation as elements must be shifted.
    std::cout << "Vector before insert: ";
    for (int val : myVector) { std::cout << val << " "; }
    myVector.insert(myVector.begin() + 1, 150);
    std::cout << "\nVector after insert at index 1: ";
    for (int val : myVector) { std::cout << val << " "; }
    std::cout << "\n";

    // 4. erase(position) - Removes an element at a specific position
    std::cout << "Vector before erase: ";
    for (int val : myVector) { std::cout << val << " "; }
    myVector.erase(myVector.begin() + 2); // Erase the element at index 2 (was 200)
    std::cout << "\nVector after erase at index 2: ";
    for (int val : myVector) { std::cout << val << " "; }
    std::cout << "\n";

    // 5. swap(other) - Swaps contents of two vectors efficiently
    std::vector<int> otherVector = {900, 800, 700};
    myVector.swap(otherVector);
    std::cout << "After swapping, myVector now contains: ";
    for (int val : myVector) { std::cout << val << " "; }
    std::cout << "\nAnd otherVector now contains: ";
    for (int val : otherVector) { std::cout << val << " "; }
    std::cout << "\n";

    // 6. begin(), end(), cbegin(), cend() - Iterators
    // These are used for loops and algorithms.
    std::cout << "Printing myVector using iterators: ";
    for (auto it = myVector.begin(); it != myVector.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    std::cout << "--------------------------------\n";

    return 0;
}

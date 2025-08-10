#include <iostream>
#include <array>     // Required for using the std::array container
#include <stdexcept> // Required for catching exceptions from array::at()

// This program demonstrates the usage of various std::array functions.
// All explanations are provided directly within the comments of the code.

int main() {
    std::cout << "--- Part 1: Constructors and Capacity ---\n";

    // 1. Creating a std::array
    // Unlike vector, the size of std::array is fixed at compile-time.
    std::array<int, 5> myArray = {10, 20, 30, 40, 50};
    
    // 2. size() - Returns the fixed number of elements
    // This value is a compile-time constant.
    std::cout << "The size of myArray is: " << myArray.size() << "\n";

    // 3. max_size() - Returns the maximum number of elements
    // For std::array, this is always the same as its size.
    std::cout << "The maximum size of myArray is: " << myArray.max_size() << "\n";

    // 4. empty() - Checks if the array is empty
    // It returns true only if the size is 0.
    if (!myArray.empty()) {
        std::cout << "myArray is not empty.\n\n";
    }

    // --- Part 2: Element Access Functions ---\n
    
    // 5. at(index) - Accesses an element with bounds checking
    // This is the safest way to access elements as it throws an exception on an invalid index.
    try {
        std::cout << "Element at index 2 (using at()): " << myArray.at(2) << "\n";
        // The line below will throw an exception because index 10 is out of bounds.
        // std::cout << "Element at index 10: " << myArray.at(10) << "\n";
    } catch (const std::out_of_range& e) {
        std::cerr << "Caught exception: " << e.what() << "\n";
    }

    // 6. operator[] - Accesses an element without bounds checking
    // This is faster but less safe than at(). Be careful not to go out of bounds.
    std::cout << "Element at index 2 (using []): " << myArray[2] << "\n";

    // 7. front() - Accesses the first element
    // Equivalent to myArray[0].
    std::cout << "First element (using front()): " << myArray.front() << "\n";

    // 8. back() - Accesses the last element
    // Equivalent to myArray[myArray.size() - 1].
    std::cout << "Last element (using back()): " << myArray.back() << "\n";

    // 9. data() - Get a pointer to the underlying C-style array
    // This is useful for passing the array to C functions.
    int* dataPtr = myArray.data();
    std::cout << "Element at index 2 using data() pointer: " << *(dataPtr + 2) << "\n\n";

    // --- Part 3: Modifiers and Iterators ---\n
    
    // 10. fill(value) - Assigns a value to all elements
    // This is an efficient way to reset all elements to a specific value.
    myArray.fill(0);
    std::cout << "After fill(0), myArray contains: ";
    for (int val : myArray) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    // Let's re-populate the array for the next example
    myArray = {1, 2, 3, 4, 5};

    // 11. swap(other) - Swaps the contents of two arrays
    // Both arrays must have the same type and size.
    std::array<int, 5> otherArray = {100, 200, 300, 400, 500};
    myArray.swap(otherArray);
    std::cout << "After swapping, myArray now contains: ";
    for (int val : myArray) {
        std::cout << val << " ";
    }
    std::cout << "\nAnd otherArray now contains: ";
    for (int val : otherArray) {
        std::cout << val << " ";
    }
    std::cout << "\n\n";

    // 12. begin(), end(), cbegin(), cend() - Iterators
    // These are used for loops and algorithms. 'cbegin' and 'cend' return const iterators.
    std::cout << "Printing myArray using const iterators: ";
    for (auto it = myArray.cbegin(); it != myArray.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    return 0;
}

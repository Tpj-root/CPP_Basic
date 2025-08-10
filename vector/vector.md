

### source

```
https://cplusplus.com/reference/vector/
```



List of common `std::vector` member functions, each with a brief two-line explanation.

### Capacity and Size

* **`size()`**
    Returns the number of elements in the vector. It indicates the current logical size of the vector.
* **`max_size()`**
    Returns the maximum number of elements the vector can hold. This value depends on the system and compiler.
* **`capacity()`**
    Returns the size of the storage space currently allocated for the vector. It may be larger than the actual number of elements.
* **`empty()`**
    Returns `true` if the vector contains no elements; otherwise, it returns `false`. This is a more efficient way to check if `size()` is zero.
* **`reserve(n)`**
    Requests that the vector's capacity be at least enough to hold `n` elements. This can prevent multiple reallocations when you know the final size.
* **`shrink_to_fit()`**
    Reduces the vector's capacity to fit its actual size. This frees up unused memory.

### Element Access

* **`at(n)`**
    Returns a reference to the element at position `n`. It performs bounds checking and throws an `out_of_range` exception if the index is invalid.
* **`operator[]`**
    Returns a reference to the element at position `n`. It does not perform bounds checking and is faster than `at()`.
* **`front()`**
    Returns a reference to the first element in the vector. This is equivalent to `vector[0]`.
* **`back()`**
    Returns a reference to the last element in the vector. This is equivalent to `vector[size() - 1]`.
* **`data()`**
    Returns a pointer to the first element in the array used internally by the vector. This allows for direct access to the underlying C-style array.

### Modifiers

* **`push_back(val)`**
    Adds a new element with the value `val` to the end of the vector. This increases the vector's size by one.
* **`pop_back()`**
    Removes the last element from the vector. This reduces the vector's size by one.
* **`insert(position, val)`**
    Inserts a new element with the value `val` at the specified position. All elements after the insertion point are shifted back.
* **`erase(position)`**
    Removes the element at the specified position from the vector. All elements after the erased element are shifted forward.
* **`clear()`**
    Removes all elements from the vector. The vector's size becomes zero, but its capacity remains the same.
* **`swap(other)`**
    Exchanges the contents of the vector with the contents of another vector `other`. This operation is highly efficient and doesn't involve copying elements.
* **`emplace_back(args...)`**
    Constructs a new element in-place at the end of the vector. This can be more efficient than `push_back()` for complex objects.
* **`emplace(position, args...)`**
    Constructs a new element in-place at a specified position. This avoids the overhead of a copy or move constructor.

### Iterators

* **`begin()` and `end()`**
    `begin()` returns an iterator to the first element. `end()` returns a past-the-end iterator, not pointing to a valid element. They are used for iterating through the vector.
* **`rbegin()` and `rend()`**
    `rbegin()` returns a reverse iterator to the last element. `rend()` returns a reverse iterator to the element before the first. They are used for iterating backward.
* **`cbegin()` and `cend()`**
    `cbegin()` returns a `const` iterator to the first element. `cend()` returns a `const` past-the-end iterator. These are used when you want to ensure the vector is not modified during iteration.


```
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

```
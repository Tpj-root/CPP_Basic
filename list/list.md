


### source

```
https://cplusplus.com/reference/list/list/
```




### Capacity and Size Functions

* **`size()`**
    Returns the number of elements in the vector. It reflects the current logical size of the vector, not the allocated memory.
* **`max_size()`**
    Returns the maximum number of elements the vector can theoretically hold. This is typically limited by system resources or memory allocation policies.
* **`capacity()`**
    Returns the size of the storage space currently allocated for the vector. It's the total number of elements the vector can hold before a reallocation is necessary.
* **`empty()`**
    Checks if the vector contains any elements. It returns `true` if the size is 0 and `false` otherwise.
* **`reserve(n)`**
    Requests that the vector's capacity be at least enough to hold `n` elements. This can be used to prevent repeated reallocations when you know the final size.
* **`shrink_to_fit()`**
    Reduces the vector's capacity to fit its current size. This is useful for freeing up unused memory.

---

### Element Access Functions

* **`at(n)`**
    Returns a reference to the element at a specified position `n`. This function performs bounds checking and will throw an `out_of_range` exception if the index is invalid.
* **`operator[]`**
    Returns a reference to the element at a specified position `n`. This is a faster alternative to `at()` because it does not perform bounds checking.
* **`front()`**
    Returns a reference to the first element in the vector. This is equivalent to accessing the element at index 0.
* **`back()`**
    Returns a reference to the last element in the vector. This is equivalent to accessing the element at index `size() - 1`.
* **`data()`**
    Returns a direct pointer to the memory array used by the vector. This allows for compatibility with C-style functions and APIs that require pointers.

---

### Modifiers

* **`push_back(val)`**
    Adds a new element with the value `val` to the end of the vector. The vector's size increases by one.
* **`pop_back()`**
    Removes the last element from the vector. This reduces the vector's size by one.
* **`insert(position, val)`**
    Inserts a new element at a specific position. Elements after the insertion point are shifted back.
* **`erase(position)`**
    Removes the element at a specific position. Elements after the erased element are shifted forward.
* **`clear()`**
    Removes all elements from the vector. The vector's size becomes zero, but its capacity may remain the same.
* **`swap(other)`**
    Exchanges the contents of the vector with another vector `other`. This is a very efficient operation that does not involve copying elements.
* **`emplace_back(args...)`**
    Constructs a new element in-place at the end of the vector. This can be more efficient than `push_back()` for complex objects.
* **`emplace(position, args...)`**
    Constructs a new element in-place at a specified position. This avoids the overhead of a copy or move constructor.

---

### Iterators

* **`begin()` and `end()`**
    `begin()` returns an iterator to the first element. `end()` returns a "past-the-end" iterator that marks the position after the last element.
* **`rbegin()` and `rend()`**
    `rbegin()` returns a reverse iterator pointing to the last element. `rend()` returns a reverse iterator pointing before the first element.
* **`cbegin()` and `cend()`**
    `cbegin()` and `cend()` return `const` iterators. They are used for iterating through the vector when you don't intend to modify its contents.



```
#include <iostream>
#include <vector>
#include <stdexcept> // Required for catching exceptions from vector::at()

// This program demonstrates the usage of various std::vector functions.
// All explanations are provided directly within the comments of the code.

int main() {
    std::cout << "--- Part 1: Capacity and Size Functions ---\n";

    // 1. Creating an empty vector
    std::vector<int> myVector;
    std::cout << "Initially, the vector is empty. Size: " << myVector.size() << ", Capacity: " << myVector.capacity() << "\n";

    // 2. push_back(value) - Adds elements to the vector
    // The vector will automatically resize (increase its capacity) as needed.
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
    // This can improve performance by pre-allocating memory, preventing multiple reallocations.
    myVector.reserve(20);
    std::cout << "After reserving space for 20 elements, Capacity is now: " << myVector.capacity() << "\n";
    std::cout << "\n";

    // 7. shrink_to_fit() - Reduces capacity to match size
    // This can be used to free up unused memory if you no longer need the extra capacity.
    myVector.shrink_to_fit();
    std::cout << "After shrinking to fit, Capacity is now: " << myVector.capacity() << "\n";
    std::cout << "\n";

    // 8. max_size() - Returns the maximum possible size
    // This value is system-dependent and reflects theoretical limits.
    std::cout << "The maximum size myVector could ever have is: " << myVector.max_size() << "\n";
    std::cout << "--------------------------------\n\n";


    std::cout << "--- Part 2: Element Access Functions ---\n";

    // The current vector contains: [0, 10, 20, 30, 40]

    // 1. at(index) - Accesses an element with bounds checking
    // This is a safer way to access elements as it throws an exception on invalid access.
    try {
        std::cout << "Element at index 2 (using at()): " << myVector.at(2) << "\n";
        // Uncomment the line below to see the exception handling in action:
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
    myVector.erase(myVector.begin() + 2); // Erase the element at index 2 (which is now 200)
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
    // These are used for loops and algorithms. 'cbegin' and 'cend' return const iterators.
    std::cout << "Printing myVector using iterators: ";
    for (auto it = myVector.cbegin(); it != myVector.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    return 0;
}


```
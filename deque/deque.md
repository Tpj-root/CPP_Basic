


### source

```
https://cplusplus.com/reference/deque/deque/
```



### Capacity and Size Functions

* **`size()`**
    Returns the number of elements currently in the deque. It gives you the current logical size of the container.
* **`max_size()`**
    Returns the maximum number of elements the deque can hold. This value is typically limited by the system's memory.
* **`empty()`**
    Checks if the deque is empty. It returns `true` if the size is 0 and `false` otherwise.

***

### Element Access Functions

* **`at(n)`**
    Returns a reference to the element at a specified position `n`. This method performs bounds checking and throws an `out_of_range` exception if the index is invalid.
* **`operator[]`**
    Returns a reference to the element at a specified position `n`. This is a faster alternative to `at()` but does not perform bounds checking.
* **`front()`**
    Returns a reference to the first element in the deque. This provides direct access to the element at the front.
* **`back()`**
    Returns a reference to the last element in the deque. This provides direct access to the element at the back.

***

### Modifiers

* **`push_back(val)`**
    Adds a new element with the value `val` to the end of the deque. This operation is highly efficient and increases the deque's size by one.
* **`pop_back()`**
    Removes the last element from the deque. This efficiently reduces the deque's size by one.
* **`push_front(val)`**
    Adds a new element with the value `val` to the beginning of the deque. This is a key advantage of deques, as this operation is also highly efficient.
* **`pop_front()`**
    Removes the first element from the deque. Like `push_front()`, this operation is highly efficient.
* **`insert(position, val)`**
    Inserts a new element at a specific position. This can be less efficient than `push_back()` or `push_front()` as it may require shifting other elements.
* **`erase(position)`**
    Removes the element at a specific position. Elements after the erased element are shifted forward.
* **`clear()`**
    Removes all elements from the deque. The deque's size becomes zero, but it may not free up all the memory.
* **`swap(other)`**
    Exchanges the contents of the deque with another deque `other`. This is a very efficient operation that does not involve copying or moving elements.
* **`emplace(position, args...)`**
    Constructs a new element in-place at a specified position. This can be more efficient than `insert()` for complex objects.
* **`emplace_back(args...)`**
    Constructs a new element in-place at the end of the deque. This avoids the overhead of a copy or move constructor.
* **`emplace_front(args...)`**
    Constructs a new element in-place at the beginning of the deque. This is an efficient way to add an element to the front.

***

### Iterators

* **`begin()` and `end()`**
    `begin()` returns an iterator to the first element. `end()` returns a "past-the-end" iterator that marks the position after the last element.
* **`rbegin()` and `rend()`**
    `rbegin()` returns a reverse iterator pointing to the last element. `rend()` returns a reverse iterator pointing before the first element.
* **`cbegin()` and `cend()`**
    `cbegin()` and `cend()` return `const` iterators. They are used for iterating through the deque when you don't intend to modify its contents.



```
#include <iostream>
#include <deque>
#include <stdexcept> // Required for catching exceptions from deque::at()

// This program demonstrates the usage of various std::deque functions.
// All explanations are provided directly within the comments of the code.

int main() {
    std::cout << "--- Part 1: Capacity and Size Functions ---\n";

    // 1. Creating an empty deque
    std::deque<int> myDeque;
    std::cout << "Initially, the deque is empty. Size: " << myDeque.size() << "\n";

    // 2. empty() - Checks if the deque is empty
    // Returns true if size is 0, false otherwise.
    if (myDeque.empty()) {
        std::cout << "myDeque is currently empty.\n";
    }

    // 3. max_size() - Returns the maximum possible size
    // This value is system-dependent.
    std::cout << "The maximum size myDeque could ever have is: " << myDeque.max_size() << "\n\n";

    // --- Part 2: Modifiers - Adding and Removing Elements ---
    std::cout << "--- Part 2: Modifiers - push_back, push_front, pop_back, pop_front ---\n";

    // 4. push_back(value) - Adds an element to the end
    // This operation is highly efficient.
    myDeque.push_back(10);
    myDeque.push_back(20);
    myDeque.push_back(30);
    std::cout << "After push_back(10), push_back(20), push_back(30): ";
    for (int val : myDeque) { std::cout << val << " "; }
    std::cout << "\n";

    // 5. push_front(value) - Adds an element to the beginning
    // This is a key advantage of deque over vector; it's also highly efficient.
    myDeque.push_front(5);
    myDeque.push_front(0);
    std::cout << "After push_front(5), push_front(0): ";
    for (int val : myDeque) { std::cout << val << " "; }
    std::cout << "\n";

    // 6. pop_back() - Removes the last element
    // This efficiently reduces the deque's size by one.
    myDeque.pop_back();
    std::cout << "After pop_back(): ";
    for (int val : myDeque) { std::cout << val << " "; }
    std::cout << "\n";

    // 7. pop_front() - Removes the first element
    // This is also highly efficient.
    myDeque.pop_front();
    std::cout << "After pop_front(): ";
    for (int val : myDeque) { std::cout << val << " "; }
    std::cout << "\n\n";

    // --- Part 3: Element Access Functions ---
    std::cout << "--- Part 3: Element Access ---\n";

    // Current deque contents: [5, 10, 20]

    // 8. at(index) - Accesses an element with bounds checking
    // This is a safer way to access elements as it throws an exception on invalid access.
    try {
        std::cout << "Element at index 1 (using at()): " << myDeque.at(1) << "\n";
        // Uncomment the line below to see the exception handling in action:
        // std::cout << "Element at index 10: " << myDeque.at(10) << "\n";
    } catch (const std::out_of_range& e) {
        std::cerr << "Caught exception: " << e.what() << "\n";
    }

    // 9. operator[] - Accesses an element without bounds checking
    // This is faster but less safe than at().
    std::cout << "Element at index 1 (using []): " << myDeque[1] << "\n";

    // 10. front() - Accesses the first element
    // This is equivalent to myDeque.at(0).
    std::cout << "First element (using front()): " << myDeque.front() << "\n";

    // 11. back() - Accesses the last element
    // This is equivalent to myDeque.at(myDeque.size() - 1).
    std::cout << "Last element (using back()): " << myDeque.back() << "\n\n";

    // --- Part 4: Modifiers - Insert, Erase, Clear, Swap ---
    std::cout << "--- Part 4: More Modifiers and Iterators ---\n";

    // 12. insert(position, value) - Inserts a new element
    // This can be less efficient than push_back/push_front.
    std::cout << "Deque before insert: ";
    for (int val : myDeque) { std::cout << val << " "; }
    myDeque.insert(myDeque.begin() + 1, 15);
    std::cout << "\nDeque after insert(begin() + 1, 15): ";
    for (int val : myDeque) { std::cout << val << " "; }
    std::cout << "\n";

    // 13. erase(position) - Removes an element at a specific position
    std::cout << "Deque before erase: ";
    for (int val : myDeque) { std::cout << val << " "; }
    myDeque.erase(myDeque.begin() + 2); // Erase the element at index 2 (which is now 10)
    std::cout << "\nDeque after erase(begin() + 2): ";
    for (int val : myDeque) { std::cout << val << " "; }
    std::cout << "\n\n";

    // 14. swap(other) - Swaps contents of two deques efficiently
    std::deque<int> otherDeque = {90, 80, 70};
    std::cout << "Deque before swap: ";
    for (int val : myDeque) { std::cout << val << " "; }
    std::cout << "\nOther Deque before swap: ";
    for (int val : otherDeque) { std::cout << val << " "; }
    myDeque.swap(otherDeque);
    std::cout << "\nAfter swapping:\nMy Deque: ";
    for (int val : myDeque) { std::cout << val << " "; }
    std::cout << "\nOther Deque: ";
    for (int val : otherDeque) { std::cout << val << " "; }
    std::cout << "\n\n";

    // 15. begin(), end(), cbegin(), cend() - Iterators
    // These are used for loops and algorithms. 'cbegin' and 'cend' return const iterators.
    std::cout << "Printing myDeque using iterators: ";
    for (auto it = myDeque.cbegin(); it != myDeque.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // 16. clear() - Removes all elements
    // The deque size becomes 0.
    myDeque.clear();
    std::cout << "After clear(), myDeque has " << myDeque.size() << " elements.\n";

    return 0;
}


```
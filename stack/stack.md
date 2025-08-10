### source

```
https://cplusplus.com/reference/stack/stack/
```



### Element Access

* **`top()`**
    Returns a reference to the element at the top of the stack. This is the most recently added element and the one that will be removed next.

***

### Capacity

* **`empty()`**
    Checks if the stack is empty. It returns `true` if there are no elements and `false` otherwise.

* **`size()`**
    Returns the number of elements in the stack. This gives you the current logical size of the container.

***

### Modifiers

* **`push(val)`**
    Adds a new element with the value `val` to the top of the stack. This increases the stack's size by one.

* **`pop()`**
    Removes the element from the top of the stack. This reduces the stack's size by one.

* **`emplace(args...)`**
    Constructs a new element in-place at the top of the stack. This is often more efficient than `push()` for complex objects.

* **`swap(other)`**
    Exchanges the contents of the stack with another stack `other`. This is a very efficient operation that doesn't involve copying or moving elements.


```
#include <iostream>
#include <stack> // Required for using the std::stack container

// This program demonstrates the usage of various std::stack functions.
// All explanations are provided directly within the comments of the code.

int main() {
    std::cout << "--- Part 1: Modifiers (push, emplace) ---\n";

    // 1. Creating a stack of integers
    std::stack<int> myStack;

    // 2. push(value) - Adds an element to the top of the stack
    // This is the standard way to add an element.
    std::cout << "Pushing elements 10, 20, 30 to the stack.\n";
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // 3. emplace(args...) - Constructs an element in-place at the top
    // For simple types like int, it's similar to push, but can be more efficient for complex objects.
    std::cout << "Emplacing element 40 to the stack.\n";
    myStack.emplace(40);
    std::cout << "Current size of the stack: " << myStack.size() << "\n\n";

    // --- Part 2: Element Access and Capacity Functions ---\n
    
    // 4. top() - Accesses the top element of the stack
    // This is the element that will be removed next.
    std::cout << "The element at the top of the stack is: " << myStack.top() << "\n";

    // 5. size() - Returns the number of elements
    std::cout << "The current number of elements in the stack is: " << myStack.size() << "\n";

    // 6. empty() - Checks if the stack is empty
    // Returns true if size is 0, false otherwise.
    if (!myStack.empty()) {
        std::cout << "The stack is not empty.\n\n";
    }

    // --- Part 3: Modifiers (pop, swap) and Iteration Simulation ---\n
    
    // 7. pop() - Removes the element from the top
    // This is a "void" function, meaning it doesn't return the value.
    std::cout << "Removing elements one by one using pop()...\n";
    while (!myStack.empty()) {
        std::cout << "Popping element: " << myStack.top() << "\n";
        myStack.pop();
    }
    std::cout << "Stack is now empty.\n\n";

    // Re-add some elements for the next example
    myStack.push(111);
    myStack.push(222);

    // 8. swap(other) - Swaps the contents of two stacks efficiently
    std::stack<int> otherStack;
    otherStack.push(333);
    otherStack.push(444);

    std::cout << "Before swap:\n";
    std::cout << "myStack top: " << myStack.top() << ", size: " << myStack.size() << "\n";
    std::cout << "otherStack top: " << otherStack.top() << ", size: " << otherStack.size() << "\n\n";

    myStack.swap(otherStack);

    std::cout << "After swap:\n";
    std::cout << "myStack top: " << myStack.top() << ", size: " << myStack.size() << "\n";
    std::cout << "otherStack top: " << otherStack.top() << ", size: " << otherStack.size() << "\n";

    return 0;
}


```
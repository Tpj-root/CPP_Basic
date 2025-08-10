

### source

```
https://cplusplus.com/reference/queue/queue/
```




### Element Access Functions

* **`front()`**
    Returns a reference to the element at the front of the queue. This is the next element to be removed.

* **`back()`**
    Returns a reference to the element at the back of the queue. This is the most recently added element.

***

### Capacity Functions

* **`empty()`**
    Checks if the queue is empty. It returns `true` if there are no elements and `false` otherwise.

* **`size()`**
    Returns the number of elements in the queue. This gives you the current logical size of the container.

***

### Modifiers

* **`push(val)`**
    Adds a new element with the value `val` to the back of the queue. This increases the queue's size by one.

* **`pop()`**
    Removes the element from the front of the queue. This reduces the queue's size by one.

* **`emplace(args...)`**
    Constructs a new element in-place at the back of the queue. This is often more efficient than `push()` for complex objects as it avoids a copy or move operation.

* **`swap(other)`**
    Exchanges the contents of the queue with another queue `other`. This is a very efficient operation that does not involve copying or moving elements.


```

#include <iostream>
#include <queue> // Required for using the std::queue container

// This program demonstrates the usage of various std::queue functions.
// All explanations are provided directly within the comments of the code.

int main() {
    std::cout << "--- Part 1: Modifiers (push, emplace) ---\n";

    // 1. Creating a queue of integers
    std::queue<int> myQueue;

    // 2. push(value) - Adds an element to the back of the queue
    // This is the standard way to add an element.
    std::cout << "Pushing elements 10, 20, 30 to the queue.\n";
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    // 3. emplace(args...) - Constructs an element in-place at the back
    // For simple types like int, it's similar to push, but can be more efficient for complex objects.
    std::cout << "Emplacing element 40 to the queue.\n";
    myQueue.emplace(40);
    std::cout << "Current size of the queue: " << myQueue.size() << "\n\n";

    // --- Part 2: Element Access and Capacity Functions ---\n
    
    // 4. front() - Accesses the first element in the queue
    // This is the element that will be removed next.
    std::cout << "The element at the front of the queue is: " << myQueue.front() << "\n";

    // 5. back() - Accesses the last element in the queue
    // This is the element that was added most recently.
    std::cout << "The element at the back of the queue is: " << myQueue.back() << "\n";

    // 6. size() - Returns the number of elements
    std::cout << "The current number of elements in the queue is: " << myQueue.size() << "\n";

    // 7. empty() - Checks if the queue is empty
    // Returns true if size is 0, false otherwise.
    if (!myQueue.empty()) {
        std::cout << "The queue is not empty.\n\n";
    }

    // --- Part 3: Modifiers (pop, swap) and Iteration Simulation ---\n
    
    // 8. pop() - Removes the element from the front
    // This is a "void" function, meaning it doesn't return the value.
    std::cout << "Removing elements one by one using pop()...\n";
    while (!myQueue.empty()) {
        std::cout << "Popping element: " << myQueue.front() << "\n";
        myQueue.pop();
    }
    std::cout << "Queue is now empty.\n\n";

    // Re-add some elements for the next example
    myQueue.push(111);
    myQueue.push(222);

    // 9. swap(other) - Swaps the contents of two queues efficiently
    std::queue<int> otherQueue;
    otherQueue.push(333);
    otherQueue.push(444);

    std::cout << "Before swap:\n";
    std::cout << "myQueue front: " << myQueue.front() << ", size: " << myQueue.size() << "\n";
    std::cout << "otherQueue front: " << otherQueue.front() << ", size: " << otherQueue.size() << "\n\n";

    myQueue.swap(otherQueue);

    std::cout << "After swap:\n";
    std::cout << "myQueue front: " << myQueue.front() << ", size: " << myQueue.size() << "\n";
    std::cout << "otherQueue front: " << otherQueue.front() << ", size: " << otherQueue.size() << "\n";

    return 0;
}

```
# CPP_Basic
List of common functions and a one-line explanation for each





List of commonly used C++ Standard Library headers, organized by category, with a brief explanation for each.

***

## Input/Output (I/O) ⌨️

* `iostream` [iostream](iostream/iostream.md)

    Provides definitions for formatted and unformatted **input/output operations**. It includes objects like `cin` for input and `cout` for output.
* `fstream` [fstream](fstream/fstream.md)

    Defines classes for **file-based I/O**. It's used for reading from and writing to files on your disk.
* `sstream` [sstream](sstream/sstream.md)

    Defines classes for **string-based stream I/O**. This allows you to treat a string like an input or output stream.
* `iomanip` [iomanip](iomanip/iomanip.md)

    Provides definitions for **I/O manipulators**. These are used to format output, such as setting precision or width.

***

## Containers 📦

* `vector`
    Defines the `std::vector` class, a **dynamic array** that can grow and shrink in size. Elements are stored contiguously in memory.
* `list`
    Defines the `std::list` class, a **doubly-linked list**. It allows for constant time insertion and deletion anywhere in the sequence.
* `deque`
    Defines the `std::deque` (double-ended queue) class. It's similar to a vector but allows for efficient **insertion and deletion at both ends**.
* `queue`
    Defines the `std::queue` container adapter. It provides a **First-In, First-Out (FIFO)** data structure.
* `stack`
    Defines the `std::stack` container adapter. It provides a **Last-In, First-Out (LIFO)** data structure.
* `map`
    Defines the `std::map` class, an associative container that stores elements as **key-value pairs**. The keys are sorted.
* `set`
    Defines the `std::set` class, an associative container that stores a **sorted set of unique elements**.
* `unordered_map`
    Defines the `std::unordered_map`, which stores **key-value pairs in a hash table**. It provides faster access than a map but the elements are not ordered.
* `unordered_set`
    Defines the `std::unordered_set`, which stores a set of **unique elements in a hash table**. It offers faster access than a set, with no ordering.
* `array`
    Defines the `std::array` class, a **fixed-size array** container. It combines the performance of a C-style array with the benefits of a standard container.

***

## Algorithms & Numerics 🧮

* `algorithm`
    Provides a collection of functions for a variety of purposes (e.g., **sorting, searching, modifying**) that operate on ranges of elements.
* `numeric`
    Contains a collection of **common mathematical operations** on sequences, like `accumulate` (sum) and `iota` (fill with a sequence).
* `cmath`
    Declares a set of functions to perform **common mathematical operations**, such as `sqrt` (square root) and `sin` (sine).
* `random`
    Provides facilities for generating **random and pseudo-random numbers**. This is more advanced and flexible than the older `cstdlib` functions.

***

## Strings 📝

* `string`
    Defines the `std::string` class. It provides a much safer and more powerful way to **handle sequences of characters** than C-style strings.
* `string_view`
    Defines `std::string_view` (since C++17), a **non-owning, read-only view** of a string. It's useful for avoiding expensive string copies when you only need to read the string.

***

## Utilities & Memory 🛠️

* `utility`
    Provides several general-purpose utilities. Its most famous component is `std::pair`, used to store a **pair of objects**.
* `memory`
    Provides facilities for **memory management**, including smart pointers like `std::unique_ptr` and `std::shared_ptr` to help prevent memory leaks.
* `functional`
    Provides a set of **function objects (functors)** and tools to work with them, like `std::function`, which can store any callable target.
* `chrono`
    Provides classes for working with **time durations, clocks, and time points**. Essential for measuring performance or handling time-related tasks.
* `optional`
    Defines `std::optional` (since C++17), a type that can represent a value that **may or may not be present**. It's a safer alternative to using null pointers or special flag values.

***

## Concurrency ⛓️

* `thread`
    Provides the `std::thread` class and related functions for **creating and managing threads** to execute code concurrently.
* `mutex`
    Provides synchronization primitives like `std::mutex` and `std::lock_guard`. These are used to **protect shared data from race conditions** in multi-threaded applications.
* `future`
    Provides mechanisms to **retrieve results from asynchronous tasks** (tasks running in the background). It allows one thread to wait for a result from another.



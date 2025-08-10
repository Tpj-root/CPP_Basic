# CPP_Basic
List of common functions and a one-line explanation for each



Simple **C++ include order best practice** diagram you can follow:

```
+---------------------------------------------------+
| 1. Your own header for this .cpp file             |
|    (e.g., "my_class.h")                           |
+---------------------------------------------------+
| 2. C library headers (if any)                     |
|    e.g., <cstdio>, <cstdlib>, <cstring>           |
+---------------------------------------------------+
| 3. C++ standard library headers                   |
|    Grouped logically:                             |
|      - <iostream>, <fstream>, <sstream>           |
|      - <string>, <vector>, <map>, <tuple>         |
|      - <utility>, <algorithm>, <functional>       |
+---------------------------------------------------+
| 4. Third-party library headers                    |
|    e.g., <boost/...>, <fmt/core.h>                |
+---------------------------------------------------+
| 5. Other project headers                          |
|    (headers from other parts of your codebase)    |
+---------------------------------------------------+
```

**Example:**

```cpp
#include "person.h"      // Own header

#include <iostream>      // Standard IO
#include <string>        // std::string
#include <tuple>         // std::tuple, std::tie
#include <utility>       // std::pair, std::move

#include <boost/algorithm/string.hpp>  // 3rd party
#include "helpers/log.h"               // Other project headers
```

💡 **Tips:**

* Always include exactly what you use — don’t depend on indirect includes.
* Group and space for readability.
* Order from *most local* (own header) → *most general* (standard lib).




List of commonly used C++ Standard Library headers, organized by category, with a brief explanation for each.

***

## Input/Output (I/O) ⌨️

* `iostream` [iostream](iostream/iostream.md) [example](iostream/iostream.cpp)

    Provides definitions for formatted and unformatted **input/output operations**. It includes objects like `cin` for input and `cout` for output.
* `fstream` [fstream](fstream/fstream.md)

    Defines classes for **file-based I/O**. It's used for reading from and writing to files on your disk.
* `sstream` [sstream](sstream/sstream.md)

    Defines classes for **string-based stream I/O**. This allows you to treat a string like an input or output stream.
* `iomanip` [iomanip](iomanip/iomanip.md)

    Provides definitions for **I/O manipulators**. These are used to format output, such as setting precision or width.

***

## Containers 📦

* `vector` [vector](vector/vector.md)

    Defines the `std::vector` class, a **dynamic array** that can grow and shrink in size. Elements are stored contiguously in memory.

* `list` [list](list/list.md)

    Defines the `std::list` class, a **doubly-linked list**. It allows for constant time insertion and deletion anywhere in the sequence.

* `deque` [deque](deque/deque.md)

    Defines the `std::deque` (double-ended queue) class. It's similar to a vector but allows for efficient **insertion and deletion at both ends**.

* `queue` [queue](queue/queue.md)

    Defines the `std::queue` container adapter. It provides a **First-In, First-Out (FIFO)** data structure.

* `stack` [stack](stack/stack.md)

    Defines the `std::stack` container adapter. It provides a **Last-In, First-Out (LIFO)** data structure.

* `map` [map](map/map.md)

    Defines the `std::map` class, an associative container that stores elements as **key-value pairs**. The keys are sorted.

* `set` [set](set/set.md)

    Defines the `std::set` class, an associative container that stores a **sorted set of unique elements**.

* `unordered_map` [unordered_map](unordered_map/unordered_map.md)

    Defines the `std::unordered_map`, which stores **key-value pairs in a hash table**. It provides faster access than a map but the elements are not ordered.

* `unordered_set` [unordered_set](unordered_set/unordered_set.md)

    Defines the `std::unordered_set`, which stores a set of **unique elements in a hash table**. It offers faster access than a set, with no ordering.

* `array` [array](array/array.md)

    Defines the `std::array` class, a **fixed-size array** container. It combines the performance of a C-style array with the benefits of a standard container.

***

## Algorithms & Numerics 🧮

* `algorithm` [algorithm](algorithm/algorithm.md)

    Provides a collection of functions for a variety of purposes (e.g., **sorting, searching, modifying**) that operate on ranges of elements.

* `numeric` [numeric](numeric/numeric.md)

    Contains a collection of **common mathematical operations** on sequences, like `accumulate` (sum) and `iota` (fill with a sequence).

* `cmath` [cmath](cmath/cmath.md)

    Declares a set of functions to perform **common mathematical operations**, such as `sqrt` (square root) and `sin` (sine).

* `random` [random](random/random.md)

    Provides facilities for generating **random and pseudo-random numbers**. This is more advanced and flexible than the older `cstdlib` functions.

***

## Strings 📝

* `string` [string](string/string.md)

    Defines the `std::string` class. It provides a much safer and more powerful way to **handle sequences of characters** than C-style strings.

* `string_view` [string_view](string_view/string_view.md)

    Defines `std::string_view` (since C++17), a **non-owning, read-only view** of a string. It's useful for avoiding expensive string copies when you only need to read the string.

***

## Utilities & Memory 🛠️

* `utility` [utility](utility/utility.md)

    Provides several general-purpose utilities. Its most famous component is `std::pair`, used to store a **pair of objects**.

* `memory` [memory](memory/memory.md)

    Provides facilities for **memory management**, including smart pointers like `std::unique_ptr` and `std::shared_ptr` to help prevent memory leaks.

* `functional` [functional](functional/functional.md)

    Provides a set of **function objects (functors)** and tools to work with them, like `std::function`, which can store any callable target.

* `chrono` [chrono](chrono/chrono.md)

    Provides classes for working with **time durations, clocks, and time points**. Essential for measuring performance or handling time-related tasks.

* `optional` [optional](optional/optional.md)

    Defines `std::optional` (since C++17), a type that can represent a value that **may or may not be present**. It's a safer alternative to using null pointers or special flag values.

***

## Concurrency ⛓️

* `thread` [thread](thread/thread.md)

    Provides the `std::thread` class and related functions for **creating and managing threads** to execute code concurrently.

* `mutex` [mutex](mutex/mutex.md)

    Provides synchronization primitives like `std::mutex` and `std::lock_guard`. These are used to **protect shared data from race conditions** in multi-threaded applications.
    
* `future` [future](future/future.md)
    Provides mechanisms to **retrieve results from asynchronous tasks** (tasks running in the background). It allows one thread to wait for a result from another.




There are C++ libraries that make colored console printing easier so you don’t have to remember ANSI codes.

```
https://github.com/ikalnytskyi/termcolor
https://github.com/agauniyal/rang
```




C++ you have several logging libraries available:

* **spdlog** → Fast, header-only, very popular.
* **glog** (Google Logging) → Good for structured logs and severity levels.
* **Boost.Log** → Feature-rich but heavier.
* **easylogging++** → Simple and easy to integrate.
* **log4cplus** / **log4cpp** → Similar to Java’s log4j style.

```
https://github.com/gabime/spdlog
```


### source

```
https://cplusplus.com/reference/chrono/
```


The `<chrono>` header in C++ provides a comprehensive suite of tools for dealing with time durations, time points, and clocks. It's a fundamental part of the standard library for any time-related task.

---

### Durations
***
* **`std::chrono::duration<Rep, Period>`**
    A class template that represents a time duration. It stores a count of ticks of a specific `Period`, which is a ratio representing seconds.
* **`std::chrono::duration_cast<ToDuration>(d)`**
    Converts one duration type to another. It provides a safe way to convert durations, for example, from milliseconds to seconds, handling potential data loss.
* **`std::chrono::nanoseconds`, `microseconds`, `milliseconds`, `seconds`, `minutes`, `hours`**
    These are predefined type aliases for common durations. They make the code more readable by providing clear names for different time units.

---

### Time Points
***
* **`std::chrono::time_point<Clock, Duration>`**
    A class template that represents a point in time, measured from the epoch of a specific `Clock`. It is essentially a `duration` since the clock's epoch.
* **`std::chrono::time_point_cast<ToDuration>(tp)`**
    Converts a time point to a different duration type. This is useful for changing the precision of a time point, for example, from microseconds to milliseconds.

---

### Clocks
***
* **`std::chrono::system_clock`**
    Represents the system-wide real-time clock. It is not guaranteed to be monotonic and can be adjusted (e.g., by the user or an NTP service).
* **`std::chrono::steady_clock`**
    Represents a monotonic clock that cannot be adjusted. This is the recommended clock for measuring time intervals, as its ticks are guaranteed to be non-decreasing.
* **`std::chrono::high_resolution_clock`**
    Represents the clock with the smallest tick period. It is often an alias for either `system_clock` or `steady_clock`.
* **`std::chrono::is_clock_v<Clock>`** (C++20)
    A type trait that checks if a given type is a valid `Clock` type. This is useful for template metaprogramming and static assertions.

---

### Convenience Functions and Utilities
***
* **`std::chrono::now()`**
    A static member function available on clocks (e.g., `std::chrono::steady_clock::now()`) that returns the current time point of that clock.
* **`std::chrono::from_stream`** (C++20)
    Parses a string representing a time point, duration, or a calendar date/time into a chrono object. This is a powerful tool for parsing time-related data from user input.
* **`std::chrono::to_stream`** (C++20)
    Formats a chrono object into a stream. This is the inverse of `from_stream` and is used to print time points or durations in a human-readable format.
* **`std::chrono::literals::operator""_s`, `operator""_ms`, `operator""_us`, etc.** (C++14)
    User-defined literals for creating durations. For example, `10s` creates a `std::chrono::seconds` duration with a count of 10.
* **`std::chrono::floor<T>(d)`**, **`std::chrono::ceil<T>(d)`**, **`std::chrono::round<T>(d)`** (C++17)
    These functions round a duration to the nearest duration of a specific type. They provide a safe and explicit way to handle duration conversions.


```
#include <iostream>
#include <chrono>    // The core header for time durations, time points, and clocks
#include <thread>    // For std::this_thread::sleep_for
#include <string>    // For using std::string
#include <sstream>   // For std::stringstream (used with from_stream)

// This program demonstrates the usage of various functions and classes from the <chrono> header.
// All explanations are provided directly within the comments of the code.

int main() {
    // --- Part 1: Clocks and Measuring Time Intervals ---
    std::cout << "--- Part 1: Clocks and Measuring Time Intervals ---\n";

    // 1. std::chrono::steady_clock - The recommended clock for measuring intervals.
    // It is monotonic, meaning it will never go backward.
    auto start = std::chrono::steady_clock::now();

    std::cout << "  Sleeping for 200 milliseconds...\n";
    // 2. std::this_thread::sleep_for - Pauses the execution for a given duration.
    // We use a predefined duration alias here.
    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    auto end = std::chrono::steady_clock::now();

    // 3. std::chrono::duration - Represents a time duration.
    // We subtract the start time_point from the end time_point to get a duration.
    auto elapsed = end - start;

    // 4. std::chrono::duration_cast<ToDuration>(d) - Converts a duration to another.
    // We cast the duration to different units for display.
    std::cout << "  Elapsed time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count() << "ms or "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count() << "ns\n\n";


    // --- Part 2: Working with Durations and Literals ---
    std::cout << "--- Part 2: Working with Durations and Literals ---\n";
    
    // 5. Predefined duration aliases (e.g., std::chrono::seconds).
    // These make code more readable.
    std::chrono::seconds s(10);
    std::chrono::milliseconds ms(500);

    // 6. C++14 User-Defined Literals for durations.
    // The `_s`, `_ms`, `_us`, etc. literals make creating durations very clean.
    using namespace std::chrono_literals;
    auto ten_seconds = 10s;
    auto five_hundred_milliseconds = 500ms;
    
    std::cout << "  Duration of 10s has a count of " << ten_seconds.count() << "\n";
    std::cout << "  Duration of 500ms has a count of " << five_hundred_milliseconds.count() << "\n";
    
    // We can perform arithmetic on durations.
    auto total_time = ten_seconds + five_hundred_milliseconds;
    std::cout << "  Total time in milliseconds: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(total_time).count() << "ms\n\n";
              
    
    // --- Part 3: Clocks and Time Points ---
    std::cout << "--- Part 3: Clocks and Time Points ---\n";

    // 7. std::chrono::system_clock - The real-time, wall clock.
    // It can be adjusted, so it's not good for measuring intervals but useful for dates.
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    
    // We can convert a time_point to a duration since the epoch.
    auto duration_since_epoch = now.time_since_epoch();
    
    // We can also perform arithmetic with time points and durations.
    auto future_time = now + 10s;
    std::cout << "  Current time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(duration_since_epoch).count() << "ms since epoch\n";
    std::cout << "  Time in 10 seconds has a different count (not a duration): \n";
    std::cout << "  " << std::chrono::duration_cast<std::chrono::milliseconds>(future_time.time_since_epoch()).count() << "ms since epoch\n\n";
    
    
    // --- Part 4: C++17/C++20 Duration Rounding Functions ---
    std::cout << "--- Part 4: C++17/C++20 Duration Rounding Functions ---\n";
    
    std::chrono::duration<double, std::milli> d_ms(250.678);

    // 8. std::chrono::floor<ToDuration>(d) - Rounds a duration down.
    auto d_floor = std::chrono::floor<std::chrono::seconds>(d_ms);
    std::cout << "  Duration 250.678ms floored to seconds: " << d_floor.count() << "s\n";
    
    // 9. std::chrono::ceil<ToDuration>(d) - Rounds a duration up.
    auto d_ceil = std::chrono::ceil<std::chrono::seconds>(d_ms);
    std::cout << "  Duration 250.678ms ceiled to seconds: " << d_ceil.count() << "s\n";
    
    // 10. std::chrono::round<ToDuration>(d) - Rounds to the nearest duration.
    auto d_round = std::chrono::round<std::chrono::milliseconds>(d_ms);
    std::cout << "  Duration 250.678ms rounded to milliseconds: " << d_round.count() << "ms\n\n";

    return 0;
}


```
### source

```
https://cplusplus.com/reference/optional/
```


The `std::optional` class template, introduced in C++17, is a wrapper that may or may not contain a value. It's an excellent way to represent a nullable type or a function that might fail to return a meaningful result without using exceptions or a special return value.

---

### Constructors
***
* **`optional() noexcept`**
    Creates an empty `optional` object that does not contain a value. This is the default state for a newly constructed `optional`.
* **`optional(std::nullopt_t) noexcept`**
    Creates an empty `optional` object. This is a more explicit way to initialize it to the empty state using `std::nullopt`.
* **`optional(const optional& other)`**
    Copy constructor: creates a new `optional` by copying the value of `other`, if it has one. If `other` is empty, the new `optional` will also be empty.
* **`optional(optional&& other) noexcept`**
    Move constructor: creates a new `optional` by moving the value from `other`. After the move, `other` is in a valid but unspecified state.
* **`template<class U> optional(U&& value)`**
    Creates an `optional` containing the provided `value`. The value is constructed in-place from the arguments passed.

---

### Assignment Operators
***
* **`optional& operator=(const optional& other)`**
    Copy assignment: replaces the current `optional`'s content with that of `other`. If `other` is empty, the current `optional` becomes empty.
* **`optional& operator=(optional&& other) noexcept`**
    Move assignment: replaces the current `optional`'s content by moving the value from `other`. This is more efficient for large objects as it avoids a full copy.
* **`optional& operator=(std::nullopt_t) noexcept`**
    Assigns the empty state to the `optional`. It effectively destroys any contained value and makes the object empty.
* **`template<class U> optional& operator=(U&& value)`**
    Assigns a new value to the `optional`. The existing value is destroyed and the new one is constructed in-place.

---

### Observers
***
* **`constexpr bool has_value() const noexcept`**
    Checks if the `optional` contains a value. Returns `true` if it does, `false` otherwise.
* **`constexpr explicit operator bool() const noexcept`**
    Allows the `optional` to be used in a boolean context (e.g., in an `if` statement). It is equivalent to `has_value()`.
* **`constexpr const T& value() const&`**
    Returns a constant reference to the contained value. Throws `std::bad_optional_access` if the `optional` is empty.
* **`constexpr T& value() &`**
    Returns a reference to the contained value. Throws `std::bad_optional_access` if the `optional` is empty.
* **`constexpr const T& operator*() const& noexcept`**
    Returns a constant reference to the contained value. This is a fast, unchecked access method.
* **`constexpr T& operator*() & noexcept`**
    Returns a reference to the contained value. This is a fast, unchecked access method.
* **`constexpr const T* operator->() const noexcept`**
    Returns a constant pointer to the contained value. Allows access to member functions and data using the arrow operator.
* **`constexpr T* operator->() noexcept`**
    Returns a pointer to the contained value. Allows access to member functions and data using the arrow operator.
* **`template<class U> T value_or(U&& default_value) const&`**
    Returns the contained value if it exists, otherwise returns a provided default value. This is a safe way to get a value without checking for the empty state.

---

### Modifiers
***
* **`template<class... Args> T& emplace(Args&&... args)`**
    Constructs a new value in-place inside the `optional`. It destroys any existing value and then perfectly forwards `args` to the new value's constructor.
* **`void reset() noexcept`**
    Destroys any contained value and makes the `optional` empty. This is the opposite of the `emplace` function.
* **`void swap(optional& other) noexcept`**
    Exchanges the state of the current `optional` with another. This is an efficient operation that avoids memory allocation.

---

### Comparison Operators
***
* **`template<class U> constexpr bool operator==(const optional<U>& other) const`**
    Compares two `optional` objects for equality. They are equal if both are empty or if both have values that are equal.
* **`template<class U> constexpr bool operator!=(const optional<U>& other) const`**
    Compares two `optional` objects for inequality. It's the inverse of the equality operator.
* **`template<class U> constexpr bool operator<(const optional<U>& other) const`**
    Compares two `optional` objects for less-than. An empty `optional` is considered less than one with a value.
* **`template<class U> constexpr bool operator<=(const optional<U>& other) const`**
    Compares two `optional` objects for less-than-or-equal-to.
* **`template<class U> constexpr bool operator>(const optional<U>& other) const`**
    Compares two `optional` objects for greater-than.
* **`template<class U> constexpr bool operator>=(const optional<U>& other) const`**
    Compares two `optional` objects for greater-than-or-equal-to.


```

#include <iostream>
#include <optional>   // Required for using std::optional
#include <stdexcept>  // For catching std::bad_optional_access
#include <string>     // For using std::string
#include <vector>     // For using std::vector in a contained value

// This program demonstrates the usage of various functions from the std::optional class.
// All explanations are provided directly within the comments of the code.

// A function that may or may not return a value.
std::optional<int> find_first_even(const std::vector<int>& numbers) {
    for (int num : numbers) {
        if (num % 2 == 0) {
            return num; // Return an optional with a value.
        }
    }
    return std::nullopt; // Return an empty optional.
}

int main() {
    // --- Part 1: Constructors and Initialization ---
    std::cout << "--- Part 1: Constructors and Initialization ---\n";

    // 1. optional() - Default constructor creates an empty optional.
    std::optional<std::string> opt_str_default;
    std::cout << "  opt_str_default.has_value(): " << std::boolalpha << opt_str_default.has_value() << "\n";

    // 2. optional(std::nullopt_t) - Initializes to an empty state explicitly.
    std::optional<int> opt_int_nullopt = std::nullopt;
    std::cout << "  opt_int_nullopt.has_value(): " << std::boolalpha << opt_int_nullopt.has_value() << "\n";

    // 3. optional(U&& value) - Initializes with a value.
    std::optional<double> opt_double_value = 3.14;
    std::cout << "  opt_double_value.has_value(): " << std::boolalpha << opt_double_value.has_value() << ", value: " << *opt_double_value << "\n";

    // 4. optional(const optional& other) - Copy constructor.
    std::optional<double> opt_double_copy = opt_double_value;
    std::cout << "  opt_double_copy.has_value(): " << std::boolalpha << opt_double_copy.has_value() << ", value: " << *opt_double_copy << "\n\n";


    // --- Part 2: Observers (Accessing the value) ---
    std::cout << "--- Part 2: Observers (Accessing the value) ---\n";

    std::optional<int> found_val = find_first_even({1, 3, 5, 8, 10});

    // 5. has_value() and operator bool() - Check if a value exists.
    if (found_val.has_value()) {
        std::cout << "  has_value() check: Found even number " << *found_val << ".\n";
    }

    if (found_val) { // operator bool() is a convenient shortcut for has_value().
        std::cout << "  operator bool() check: Found even number " << *found_val << ".\n";
    }

    // 6. value() - Returns a reference to the value, throws if empty.
    try {
        std::cout << "  Using value(): " << found_val.value() << "\n";
        
        std::optional<int> empty_opt;
        std::cout << "  Trying to access empty_opt.value()...\n";
        std::cout << empty_opt.value() << "\n"; // This will throw an exception.
    } catch (const std::bad_optional_access& e) {
        std::cerr << "  Caught exception: " << e.what() << "\n";
    }
    
    // 7. operator* and operator-> - Unchecked access to the value.
    // Use these only after you have confirmed the optional is not empty.
    std::optional<std::string> person_name = "Alice";
    std::cout << "  Using operator*(): " << *person_name << "\n";
    std::optional<std::string> full_name = "Alice";
    std::cout << "  Using operator->(): length is " << full_name->length() << "\n";

    // 8. value_or(default_value) - Get value or a provided default.
    std::optional<int> empty_int;
    std::cout << "  Using value_or() on an empty optional: " << empty_int.value_or(99) << "\n";
    std::cout << "  Using value_or() on an optional with a value: " << found_val.value_or(99) << "\n\n";


    // --- Part 3: Modifiers ---
    std::cout << "--- Part 3: Modifiers ---\n";
    
    // 9. emplace() - Constructs a value in-place, destroying any existing one.
    std::optional<std::vector<int>> opt_vec;
    opt_vec.emplace(10, 5); // Constructs a vector of 10 elements, each with value 5.
    std::cout << "  emplace() created a vector of size " << opt_vec->size() << "\n";
    std::cout << "  First element is: " << opt_vec->front() << "\n";

    // 10. reset() - Destroys the contained value and makes the optional empty.
    opt_vec.reset();
    std::cout << "  After reset(), opt_vec.has_value(): " << std::boolalpha << opt_vec.has_value() << "\n";
    
    // 11. swap(other) - Exchanges the states of two optionals efficiently.
    std::optional<int> a = 1;
    std::optional<int> b = 2;
    std::cout << "  Before swap: a=" << a.value() << ", b=" << b.value() << "\n";
    a.swap(b);
    std::cout << "  After swap: a=" << a.value() << ", b=" << b.value() << "\n\n";
    
    
    // --- Part 4: Comparison Operators ---
    std::cout << "--- Part 4: Comparison Operators ---\n";
    std::optional<int> o1 = 10;
    std::optional<int> o2 = 10;
    std::optional<int> o3 = 20;
    std::optional<int> o4 = std::nullopt;

    // 12. operator==, operator!= - Compares two optionals.
    std::cout << "  o1 == o2? " << std::boolalpha << (o1 == o2) << "\n"; // true
    std::cout << "  o1 == o3? " << std::boolalpha << (o1 == o3) << "\n"; // false
    std::cout << "  o1 == o4? " << std::boolalpha << (o1 == o4) << "\n"; // false
    
    // 13. operator<, operator> - Compares two optionals.
    // An empty optional is considered less than one with a value.
    std::cout << "  o1 < o3? " << std::boolalpha << (o1 < o3) << "\n"; // true
    std::cout << "  o4 < o1? " << std::boolalpha << (o4 < o1) << "\n"; // true
    
    return 0;
}

```
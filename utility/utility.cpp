#include <iostream>
#include <utility>    // The core header for utility functions like std::pair, std::move, std::swap
#include <string>     // For using std::string

// A simple class to demonstrate move semantics.
// We'll track its construction, destruction, and movement.
class MyResource {
public:
    std::string data;

    // Constructor
    MyResource(const std::string& d) : data(d) {
        std::cout << "  - MyResource constructed with data: " << data << "\n";
    }

    // Move constructor
    MyResource(MyResource&& other) noexcept : data(std::move(other.data)) {
        std::cout << "  - MyResource move-constructed from: " << other.data << "\n";
    }
};

// A template function to demonstrate perfect forwarding with std::forward.
// This function can accept an lvalue or an rvalue reference.
template <typename T>
void process(T&& arg) {
    std::cout << "  Inside process(): ";
    // std::forward conditionally casts its argument.
    // If 'arg' was passed as an lvalue, it stays an lvalue.
    // If 'arg' was passed as an rvalue, it becomes an rvalue.
    MyResource resource(std::forward<T>(arg));
}


int main() {
    // --- Part 1: Pairs and Tuples ---
    std::cout << "--- Part 1: Pairs and Tuples ---\n";
    
    // 1. std::pair<T1, T2> - A template for storing two heterogeneous values.
    // We create a pair to hold a string and an integer.
    std::pair<std::string, int> person("Alice", 30);
    std::cout << "  Person: {" << person.first << ", " << person.second << "}\n";

    // 2. std::make_pair(T1, T2) - Creates a pair, automatically deducing types.
    // This is often more convenient than explicitly writing the template arguments.
    auto another_person = std::make_pair("Bob", 25);
    std::cout << "  Another person: {" << another_person.first << ", " << another_person.second << "}\n";

    // 3. std::tie(a, b, ...) - Creates a tuple of references.
    // This is useful for unpacking a pair into existing variables.
    std::string name;
    int age;
    std::tie(name, age) = another_person;
    std::cout << "  Unpacked with std::tie: name='" << name << "', age=" << age << "\n";

    // 4. std::get<I>(pair) - Accesses a pair's element by index.
    // The index I is a compile-time constant.
    std::cout << "  Accessing with std::get<0>: " << std::get<0>(person) << "\n";
    std::cout << "  Accessing with std::get<1>: " << std::get<1>(person) << "\n\n";

    // --- Part 2: Swapping and Moving ---
    std::cout << "--- Part 2: Swapping and Moving ---\n";

    // 5. std::swap(a, b) - Exchanges the values of two objects.
    // This is a generic and efficient way to swap any two objects.
    int a = 10, b = 20;
    std::cout << "  Before swap: a=" << a << ", b=" << b << "\n";
    std::swap(a, b);
    std::cout << "  After swap: a=" << a << ", b=" << b << "\n\n";

    // 6. std::move(t) - Casts an object to an rvalue reference.
    // This signals that the object's resources can be "moved from"
    // rather than copied. This can prevent expensive copying of data.
    std::cout << "  Demonstrating std::move:\n";
    std::string source = "expensive-data";
    std::string destination = std::move(source);
    std::cout << "  Source after move: '" << source << "'\n"; // Source is now in an undefined but valid state
    std::cout << "  Destination: '" << destination << "'\n\n";

    // 7. std::forward(t) - Conditionally casts an argument to an rvalue.
    // It is used in template functions to "perfectly forward" arguments
    // while preserving their original value category (lvalue or rvalue).
    std::cout << "  Demonstrating std::forward:\n";
    std::string lvalue_str = "lvalue-data";
    std::cout << "  Calling process() with lvalue:\n";
    process(lvalue_str); // Passes an lvalue
    std::cout << "  Calling process() with rvalue:\n";
    process(std::string("rvalue-data")); // Passes an rvalue
    std::cout << "\n";

    // --- Part 3: Other Utilities ---
    std::cout << "--- Part 3: Other Utilities ---\n";
    std::string non_const_str = "hello";

    // 8. std::as_const(t) - Creates a const lvalue reference to an object.
    // This is useful when you want to call a const-overloaded function on a non-const object.
    std::cout << "  non_const_str before as_const: '" << non_const_str << "'\n";
    const std::string& const_ref = std::as_const(non_const_str);
    std::cout << "  const_ref: '" << const_ref << "'\n\n";

    return 0;
}

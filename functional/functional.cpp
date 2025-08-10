#include <iostream>
#include <functional> // The core header for std::function, std::bind, and function objects
#include <vector>     // For using std::vector
#include <numeric>    // For std::accumulate
#include <algorithm>  // For std::sort, std::transform
#include <string>     // For std::string

// A simple free function to be used with std::function and std::bind.
int add(int x, int y) {
    return x + y;
}

// A simple function object (functor) to be used with std::function.
struct MultiplyFunctor {
    int operator()(int x, int y) const {
        return x * y;
    }
};

// A simple class with a member function.
class MyClass {
public:
    void greet(const std::string& name) const {
        std::cout << "  MyClass says: Hello, " << name << "!\n";
    }
    int get_value() const { return 42; }
};

// A predicate function for use with algorithms.
bool is_even(int n) {
    return n % 2 == 0;
}

int main() {
    // --- Part 1: Function Wrappers ---
    std::cout << "--- Part 1: Function Wrappers ---\n";

    // 1. std::function<R(Args...)> - A polymorphic function wrapper.
    // It can store any callable object that matches its signature.
    std::function<int(int, int)> func;

    // We can assign a regular function to it.
    func = add;
    std::cout << "  std::function with a free function: " << func(5, 3) << "\n";

    // We can assign a lambda expression to it.
    func = [](int a, int b) { return a - b; };
    std::cout << "  std::function with a lambda: " << func(5, 3) << "\n";

    // We can assign a function object (functor) to it.
    func = MultiplyFunctor();
    std::cout << "  std::function with a function object: " << func(5, 3) << "\n\n";

    // --- Part 2: Binders and Placeholders ---
    std::cout << "--- Part 2: Binders and Placeholders ---\n";
    
    // 2. std::bind() - Binds arguments to a callable.
    // We use std::placeholders::_1 and _2 to represent the arguments
    // that will be passed to the new callable.
    auto add_5 = std::bind(add, 5, std::placeholders::_1);
    std::cout << "  std::bind: add(5, 10) = " << add_5(10) << "\n";
    
    // We can also reorder arguments.
    auto reverse_subtract = std::bind(std::minus<int>(), std::placeholders::_2, std::placeholders::_1);
    std::cout << "  std::bind with reordered arguments: 10 - 5 = " << reverse_subtract(5, 10) << "\n";

    // 3. std::bind_front() (C++20) - Binds arguments to the front of a callable.
    // This is a simpler and often safer alternative to std::bind.
    auto multiply_by_10 = std::bind_front(std::multiplies<int>(), 10);
    std::cout << "  std::bind_front: 10 * 5 = " << multiply_by_10(5) << "\n\n";


    // --- Part 3: Arithmetic Operations ---
    std::cout << "--- Part 3: Arithmetic Operations ---\n";
    int val1 = 10, val2 = 5;

    // 4. std::plus<T> - Function object for addition.
    std::cout << "  std::plus<int>()(10, 5) = " << std::plus<int>()(val1, val2) << "\n";

    // 5. std::multiplies<T> - Function object for multiplication.
    std::cout << "  std::multiplies<int>()(10, 5) = " << std::multiplies<int>()(val1, val2) << "\n";
    
    // We can use these with algorithms.
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int sum_of_squares = std::accumulate(nums.begin(), nums.end(), 0, [](int total, int n) {
        return total + std::multiplies<int>()(n, n);
    });
    std::cout << "  Sum of squares of {1,2,3,4,5}: " << sum_of_squares << "\n\n";

    
    // --- Part 4: Comparisons and Relational Operations ---
    std::cout << "--- Part 4: Comparisons and Relational Operations ---\n";
    val1 = 10;
    val2 = 20;

    // 6. std::greater<T> - Function object for greater-than comparison.
    std::cout << "  Is 10 > 20? " << std::boolalpha << std::greater<int>()(val1, val2) << "\n";

    // 7. std::equal_to<T> - Function object for equality comparison.
    std::cout << "  Is 10 == 10? " << std::boolalpha << std::equal_to<int>()(10, 10) << "\n";
    
    // We can use std::greater with algorithms like std::sort.
    std::vector<int> sort_nums = {3, 1, 4, 1, 5, 9, 2, 6};
    std::sort(sort_nums.begin(), sort_nums.end(), std::greater<int>());
    std::cout << "  Sorted vector in descending order: ";
    for (int n : sort_nums) std::cout << n << " ";
    std::cout << "\n\n";


    // --- Part 5: Logical and Bitwise Operations ---
    std::cout << "--- Part 5: Logical and Bitwise Operations ---\n";

    // 8. std::logical_not<T> - Function object for logical NOT.
    std::cout << "  !true = " << std::boolalpha << std::logical_not<bool>()(true) << "\n";

    // 9. std::bit_and<T> - Function object for bitwise AND.
    // 5 in binary is 0101, 3 in binary is 0011. Result is 0001 (1).
    std::cout << "  5 & 3 = " << std::bit_and<int>()(5, 3) << "\n";

    // 10. std::bit_xor<T> - Function object for bitwise XOR.
    // 5 ^ 3 = 0101 ^ 0011 = 0110 (6).
    std::cout << "  5 ^ 3 = " << std::bit_xor<int>()(5, 3) << "\n\n";

    
    // --- Part 6: Function Pointers and Utilities ---
    std::cout << "--- Part 6: Function Pointers and Utilities ---\n";
    MyClass obj;

    // 11. std::mem_fn() - Creates a callable from a member function pointer.
    auto greeter = std::mem_fn(&MyClass::greet);
    std::cout << "  std::mem_fn used with an object:\n";
    greeter(obj, "Alice");

    // 12. std::invoke() (C++17) - A general-purpose invocation utility.
    // It can call a variety of callable types, including member functions.
    std::cout << "  std::invoke used with a member function pointer:\n";
    std::invoke(&MyClass::greet, obj, "Bob");
    
    // 13. std::not_fn() (C++17) - Returns a function object that negates a predicate.
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
    auto is_odd = std::not_fn(is_even);
    std::cout << "  Using std::not_fn with a vector:\n";
    for(int n : numbers) {
        if (is_odd(n)) {
            std::cout << "  Number " << n << " is odd.\n";
        }
    }
    
    return 0;
}

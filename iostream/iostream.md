

### source

```
https://cplusplus.com/reference/iostream/
```


### header

<iostream>

### Standard Input / Output Streams Library

Header that defines the standard input/output stream objects:




Most commonly used functions available in the `<iostream>` header in C++:

1. **std::cout**  
   Used to output data to the standard output stream (typically the console).

2. **std::cin**  
   Used to read input from the standard input stream (typically the keyboard).

3. **std::cerr**  
   Used to output error messages to the standard error stream.

4. **std::clog**  
   Used to output log messages to the standard logging stream.

**Explanation:**  
The `<iostream>` header provides the standard input/output stream objects for C++. These functions and objects allow your program to communicate with the user via text input and output.




```

#include <iostream>

/*
std::cout
----------
std::cout is used to output data to the standard output stream, usually the console.
It supports chaining using <<, allowing you to print multiple items in one statement.
Example:
*/
void example_cout() {
    std::cout << "Hello, World!" << std::endl; // Prints "Hello, World!" followed by a newline
    int x = 42;
    std::cout << "The value of x is: " << x << std::endl; // Prints variable values
}

/*
std::cin
---------
std::cin is used to receive input from the user via the standard input stream (keyboard).
It uses >> to extract input into variables.
Example:
*/
void example_cin() {
    int age;
    std::cout << "Enter your age: ";
    std::cin >> age; // Reads an integer from the user and stores it in 'age'
    std::cout << "You entered: " << age << std::endl;
}

/*
std::cerr
----------
std::cerr is used to output error messages to the standard error stream.
Unlike std::cout, output sent to std::cerr is not buffered, so it's displayed immediately.
Example:
*/
void example_cerr() {
    std::cerr << "Error: Something went wrong!" << std::endl; // Prints error messages
}

/*
std::clog
----------
std::clog is used to output log or diagnostic messages to the standard error stream.
Its output is buffered, so it may not appear immediately.
Example:
*/
void example_clog() {
    std::clog << "Log: Program started." << std::endl; // Prints log messages
}

/*
std::endl
----------
std::endl is used with output streams to insert a newline character and flush the stream.
Example:
*/
void example_endl() {
    std::cout << "First line." << std::endl; // Newline and flush
    std::cout << "Second line." << std::endl;
}

/*
Chaining Multiple Outputs
--------------------------
You can chain multiple outputs in a single statement using <<.
Example:
*/
void example_chaining() {
    int a = 5, b = 10;
    std::cout << "a = " << a << ", b = " << b << std::endl;
}

/*
Reading Multiple Inputs
--------------------------
You can read multiple inputs in a single statement using >>.
Example:
*/
void example_multi_cin() {
    int x, y;
    std::cout << "Enter two numbers: ";
    std::cin >> x >> y;
    std::cout << "You entered: " << x << " and " << y << std::endl;
}

/*
Formatted Output
-----------------
You can use <iomanip> with std::cout for formatted output.
Example:
*/
#include <iomanip>
void example_formatted_output() {
    double pi = 3.14159;
    std::cout << std::fixed << std::setprecision(2) << "Pi rounded to two decimals: " << pi << std::endl;
}

/*
Main Function to Demonstrate All
---------------------------------
*/
int main() {
    example_cout();
    // Uncomment below to interactively test cin examples:
    //example_cin();
    //example_multi_cin();
    example_cerr();
    example_clog();
    example_endl();
    example_chaining();
    example_formatted_output();
    return 0;
}

```

### header

<sstream>


### String streams

Header providing string stream classes:

### source

```
https://cplusplus.com/reference/sstream/
```



Class templates

basic_istringstream
    Input string stream (class template)

basic_ostringstream
    Output string stream (class template)

basic_stringstream
    String stream (class template)

basic_stringbuf
    String stream buffer (class template)


Classes
Narrow characters (char)

istringstream
    Input string stream (class)

ostringstream
    Output string stream (class)

stringstream
    Input/output string stream (class)

stringbuf
    String stream buffer (class)

Wide characters (wchar_t)

wistringstream
    Input string stream (wide) (class)

wostringstream
    Output string stream (wide) (class)

wstringstream
    Input/output string stream (wide) (class)

wstringbuf
    String stream buffer (wide) (class)






Main functions and objects provided by the `<sstream>` header in C++:

### Commonly Used Types and Their Functions

#### 1. `std::stringstream`
- Combines both input and output string streams.
- Allows you to read from and write to an internal string buffer.

#### 2. `std::istringstream`
- Input-only string stream.
- Used for reading data from a string as if it were an input stream.

#### 3. `std::ostringstream`
- Output-only string stream.
- Used for writing data to a string as if it were an output stream.

### Common Member Functions (for all above types)
- `.str()` – Get/set the internal string buffer.
- `.clear()` – Reset stream state.
- `.eof()` – Checks if end of stream is reached.
- `.fail()`, `.good()`, `.bad()` – Stream status checks.
- `.seekg()`, `.seekp()` – Set/get stream position for input/output.
- `.tellg()`, `.tellp()` – Get current position in input/output stream.

### Stream Operations (just like with `std::cin`/`std::cout`)
- `<<` – Output (inserts data into the stream).
- `>>` – Input (extracts data from the stream).

---

**Explanation:**  
- The `<sstream>` header provides classes for manipulating strings using streams, allowing easy parsing and formatting of string data.
- These classes use the same interface and operations as standard input/output streams, but work with strings instead of files or the console.



```
#include <iostream>
#include <sstream>
#include <string>

/*
std::stringstream
-----------------
std::stringstream is a stream class to operate on strings. It allows both input and output operations on strings.
You can use << to insert data or >> to extract data, just like with cout/cin.
*/
void example_stringstream() {
    std::stringstream ss;
    ss << "123 45.6 hello"; // Insert string into the stream

    int a;
    double b;
    std::string c;
    ss >> a >> b >> c; // Extract values from the stream

    std::cout << "Extracted values: a=" << a << ", b=" << b << ", c=" << c << std::endl;
}

/*
std::istringstream
-------------------
std::istringstream is used for input-only string streams. It can be initialized with a string, then you can extract values from it using >>.
*/
void example_istringstream() {
    std::string data = "42 3.14 apple";
    std::istringstream iss(data);

    int x;
    float y;
    std::string z;
    iss >> x >> y >> z;

    std::cout << "istringstream extracted: x=" << x << ", y=" << y << ", z=" << z << std::endl;
}

/*
std::ostringstream
-------------------
std::ostringstream is used for output-only string streams. You insert data using <<, and then get the result as a string using .str().
*/
void example_ostringstream() {
    std::ostringstream oss;
    int n = 99;
    double d = 2.718;
    oss << "Number: " << n << ", Double: " << d;

    std::string result = oss.str();
    std::cout << "ostringstream string: " << result << std::endl;
}

/*
.str()
-------
The .str() member function gets or sets the string contents of a string stream.
*/
void example_str_function() {
    std::stringstream ss;
    ss << "initial data";
    std::cout << "Current buffer: " << ss.str() << std::endl; // Gets the buffer

    ss.str("new data"); // Sets the buffer
    std::cout << "After setting buffer: " << ss.str() << std::endl;
}

/*
.clear()
---------
The .clear() member function resets the stream's error state flags.
Useful after a failed extraction to allow further operations.
*/
void example_clear_function() {
    std::stringstream ss("abc");
    int value;
    ss >> value; // Fails, sets failbit

    if (ss.fail()) {
        std::cout << "Extraction failed, clearing stream..." << std::endl;
        ss.clear(); // Reset error flags
    }
    ss.str("123");
    ss >> value;
    std::cout << "After clear, extracted: " << value << std::endl;
}

/*
.eof(), .fail(), .good(), .bad()
-------------------------------
These functions check the state of the stream:
- .eof() returns true if end of input reached
- .fail() returns true if an input/output operation failed
- .good() returns true if no error
- .bad() returns true if a serious error occurred
*/
void example_state_functions() {
    std::istringstream iss("10 20x");
    int a, b;
    iss >> a >> b;
    std::cout << "After extraction, eof=" << iss.eof()
              << ", fail=" << iss.fail()
              << ", good=" << iss.good()
              << ", bad=" << iss.bad()
              << std::endl;
}

/*
.seekg(), .seekp(), .tellg(), .tellp()
---------------------------------------
These functions set or get the position in the stream.
- .seekg(pos) sets input (get) position
- .tellg() gets current input position
- .seekp(pos) sets output (put) position
- .tellp() gets current output position
*/
void example_seek_and_tell() {
    std::stringstream ss;
    ss << "abcdefg";
    ss.seekg(2); // Move get pointer to position 2
    char ch;
    ss >> ch;
    std::cout << "Character at position 2: " << ch << std::endl;
    std::cout << "Current get position: " << ss.tellg() << std::endl;

    ss.seekp(4); // Move put pointer to position 4
    ss << "Z";
    std::cout << "Buffer after seekp and put: " << ss.str() << std::endl;
    std::cout << "Current put position: " << ss.tellp() << std::endl;
}

/*
Chaining << and >>
------------------
You can chain << to insert several values, and >> to extract several values at once.
*/
void example_chaining() {
    std::stringstream ss;
    ss << 1 << " " << 2 << " " << 3;
    int x, y, z;
    ss >> x >> y >> z;
    std::cout << "Chained extraction: x=" << x << ", y=" << y << ", z=" << z << std::endl;
}

/*
Main function to demonstrate all examples
*/
int main() {
    example_stringstream();
    example_istringstream();
    example_ostringstream();
    example_str_function();
    example_clear_function();
    example_state_functions();
    example_seek_and_tell();
    example_chaining();
    return 0;
}

```

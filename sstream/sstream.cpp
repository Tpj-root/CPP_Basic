#include <iostream>
#include <sstream>
#include <string>


void welcome_message(){

    std::cout << "****************" << std::endl;
    std::cout << "* #include <sstream> *" << std::endl;
    std::cout << "*** sstream  ***" << std::endl;
    std::cout << "****************" << std::endl;
};



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
    welcome_message();
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
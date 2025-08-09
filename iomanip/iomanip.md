
The `<iomanip>` library in C++ provides a set of **manipulators** to format output streams. 


### source

```
https://cplusplus.com/reference/iomanip/
```


List of common functions and a one-line explanation for each:



  * **`std::setw(int n)`:** Sets the minimum field width for the next output operation to `n` characters.

  * **`std::setprecision(int n)`:** Sets the number of significant digits for floating-point numbers.


  * **`std::setfill(char c)`:** Sets the character used to pad a field when its width is greater than the data.


  * **`std::left`:** Aligns output to the left within the specified field width.


  * **`std::right`:** Aligns output to the right within the specified field width (this is the default alignment).


  * **`std::fixed`:** Forces floating-point numbers to be displayed in a fixed decimal format.


  * **`std::scientific`:** Forces floating-point numbers to be displayed in scientific (exponential) notation.


  * **`std::boolalpha`:** Displays boolean values as `true` or `false` instead of `1` or `0`.


  * **`std::noboolalpha`:** Reverts to displaying boolean values as `1` or `0`.


  * **`std::setbase(int base)`:** Sets the numeric base for integer output (e.g., 8 for octal, 10 for decimal, 16 for hexadecimal).


  * **`std::get_money` / `std::put_money` (C++11):** Used to read and write monetary values formatted according to the stream's locale.


  * **`std::get_time` / `std::put_time` (C++11):** Used to read and write date and time values using a specified format.





```
#include <iostream>
#include <iomanip>
#include <string>
#include <locale>
#include <ctime>


void welcome_message(){

    std::cout << "****************" << std::endl;
    std::cout << "* #include <iomanip> *" << std::endl;
    std::cout << "*** iomanip  ***" << std::endl;
    std::cout << "****************" << std::endl;
};



// Demonstrates setw and setfill
void demonstrate_setw_and_setfill() {
    std::cout << "--- setw & setfill ---" << std::endl;
    std::cout << std::setfill('*') << std::setw(20) << "Hello" << std::endl;
    std::cout << std::setw(20) << std::left << "Left Aligned" << std::endl;
    std::cout << std::setw(20) << std::right << "Right Aligned" << std::endl;
    std::cout << std::endl;
}


/**
 * @brief Centers a given string within a specified width.
 * * This function calculates the necessary padding to center a string
 * and prints it to the console. It handles cases where the string
 * is longer than or equal to the specified width.
 * * @param text The string to be centered.
 * @param width The total width of the field in which the string will be centered.
 */
void centerText(const std::string& text, int width) {
    // Check if the string is already too long to be centered.
    // If the text's length is greater than or equal to the desired width,
    // we simply print the text without any padding to avoid truncation.
    if (text.length() >= width) {
        std::cout << text;
    } else {
        // Calculate the total number of spaces needed for padding.
        // For example, if width is 20 and text.length() is 8, padding will be 12.
        int padding = width - text.length();

        // Calculate the padding for the left side.
        // We integer-divide the total padding by 2.
        // For our example, 12 / 2 = 6.
        int left_padding = padding / 2;

        // Print the left-side padding and the string.
        // We use setw to set the field width to (left_padding + text.length()).
        // The `right` manipulator aligns the text to the end of this sub-field,
        // which effectively creates the left padding.
        // In our example, `setw(6 + 8)` will print 6 spaces followed by "Hello".
        std::cout << std::setw(left_padding + text.length()) << std::right << text;

        // Print the remaining padding on the right.
        // We calculate this by subtracting the left padding from the total padding.
        // In our example, 12 - 6 = 6.
        // We use setw to print an empty string with a width of 6, which results in 6 spaces.
        std::cout << std::setw(padding - left_padding) << "";
    }
}


// Demonstrates setprecision, fixed, and scientific
void demonstrate_precision_and_notation() {
    double pi = 3.141592653589793;
    std::cout << "--- setprecision, fixed & scientific ---" << std::endl;
    std::cout << "Default: " << pi << std::endl;
    std::cout << "setprecision(5): " << std::setprecision(5) << pi << std::endl;
    std::cout << "fixed & setprecision(5): " << std::fixed << std::setprecision(5) << pi << std::endl;
    std::cout << "scientific: " << std::scientific << pi << std::endl;
    std::cout << std::endl;
}

// Demonstrates boolalpha
void demonstrate_boolalpha() {
    bool is_true = true;
    bool is_false = false;
    std::cout << "--- boolalpha ---" << std::endl;
    std::cout << "Default (noboolalpha): " << is_true << " " << is_false << std::endl;
    std::cout << "With boolalpha: " << std::boolalpha << is_true << " " << is_false << std::endl;
    std::cout << std::noboolalpha << std::endl; // Reset for other functions
}

// Demonstrates setbase
void demonstrate_setbase() {
    int num = 255;
    std::cout << "--- setbase ---" << std::endl;
    std::cout << "Decimal (base 10): " << std::setbase(10) << num << std::endl;
    std::cout << "Octal (base 8): " << std::setbase(8) << num << std::endl;
    std::cout << "Hexadecimal (base 16): " << std::setbase(16) << num << std::endl;
    std::cout << std::endl;
}

// Demonstrates put_money (requires C++11 and locale setup)
void demonstrate_put_money() {
    std::cout << "--- put_money (C++11+) ---" << std::endl;
    std::locale loc("en_US.UTF-8"); // Example locale, might need to be installed
    std::cout.imbue(loc);
    long double money = 12345.67;
    // put_money expects cents, so we multiply by 100
    std::cout << "Amount: " << std::put_money(money * 100) << std::endl;
    std::cout << std::endl;
}

// Demonstrates put_time (requires C++11)
void demonstrate_put_time() {
    std::cout << "--- put_time (C++11+) ---" << std::endl;
    std::time_t t = std::time(nullptr);
    std::tm* time_info = std::localtime(&t);
    std::cout << "Current time: " << std::put_time(time_info, "%c") << std::endl;
    std::cout << "Custom format: " << std::put_time(time_info, "%Y-%m-%d %H:%M:%S") << std::endl;
    std::cout << std::endl;
}

int main() {
    welcome_message();
    demonstrate_setw_and_setfill();
    demonstrate_precision_and_notation();
    demonstrate_boolalpha();
    demonstrate_setbase();
    // These C++11 functions might require a C++11-compliant compiler
    // and correctly configured system locales to work properly.
    demonstrate_put_money(); 
    demonstrate_put_time(); 


    centerText("hhhhhhhhhh", 20);
    std::cout << std::endl;
    centerText("Centered Text Example", 20); // Example where text is longer than width
    std::cout << std::endl;

    return 0;
}
```
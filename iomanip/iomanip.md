
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



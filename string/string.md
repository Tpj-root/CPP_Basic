### source

```
https://cplusplus.com/reference/string/
```

### Constructors and Assignment
***
* **`std::string()`**
    Creates an empty string with a length of zero. This is the default constructor.
* **`std::string(const std::string& str)`**
    Creates a new string that is a copy of an existing string `str`. This is the copy constructor.
* **`std::string(const char* s)`**
    Creates a string from a null-terminated C-style character array `s`. The string's length is determined by the first null character.
* **`std::string(size_t n, CharT c)`**
    Creates a string consisting of `n` copies of the character `c`. This is useful for initializing a string with a repeated character.
* **`std::string(InputIt first, InputIt last)`**
    Creates a string by copying characters from the range `[first, last)`. The iterators can be from other containers or a C-style array.
* **`operator=(const std::string& str)`**
    Assigns a new value to the string, replacing its current contents. The assignment operator can also take a C-style string, a character, or a string view.

***
### Iterators
***
* **`begin()` and `end()`**
    `begin()` returns an iterator to the first character of the string. `end()` returns an iterator to the position *after* the last character.
* **`rbegin()` and `rend()`**
    `rbegin()` returns a reverse iterator pointing to the last character. `rend()` returns a reverse iterator pointing to the position *before* the first character.
* **`cbegin()` and `cend()`**
    These return `const` iterators to the beginning and end of the string. They are used for read-only access.

***
### Capacity
***
* **`size()` and `length()`**
    Returns the number of characters in the string. Both functions are synonyms and return the same value.
* **`max_size()`**
    Returns the maximum number of characters the string can hold. This is typically limited by available memory.
* **`resize(size_t n)`**
    Resizes the string to contain `n` characters. If the new size is smaller, characters are removed; if larger, new characters are appended.
* **`capacity()`**
    Returns the size of the storage space currently allocated for the string. This may be greater than the actual size of the string.
* **`reserve(size_t n)`**
    Requests that the string's capacity be at least `n` characters. This can prevent multiple reallocations when a string is frequently appended to.
* **`empty()`**
    Checks if the string has no characters (i.e., its size is 0). It's a quick and efficient way to check if a string is blank.
* **`shrink_to_fit()`**
    Reduces the string's capacity to fit its current size. This can be used to reclaim unused memory.

***
### Element Access
***
* **`operator[](size_t pos)`**
    Returns a reference to the character at the specified `pos`. This access is fast but does not perform bounds checking.
* **`at(size_t pos)`**
    Returns a reference to the character at the specified `pos`. This access is safer as it performs bounds checking and throws an `out_of_range` exception if the position is invalid.
* **`front()`**
    Returns a reference to the first character of the string. This is equivalent to using `at(0)`.
* **`back()`**
    Returns a reference to the last character of the string. This is equivalent to using `at(size() - 1)`.

***
### Modifiers
***
* **`append(const std::string& str)`**
    Appends a copy of a string, a C-style string, or a character to the end of the current string. There are multiple overloads for different input types.
* **`push_back(CharT c)`**
    Appends a single character `c` to the end of the string. This is an efficient way to add one character at a time.
* **`assign(const std::string& str)`**
    Assigns a new value to the string, replacing its current contents. This is an alternative to the assignment operator.
* **`insert(size_t pos, const std::string& str)`**
    Inserts a string `str` at the specified position `pos`. There are also overloads for inserting C-style strings or single characters.
* **`erase(size_t pos, size_t len)`**
    Removes a range of characters from the string, starting at `pos` for a length of `len`. You can also erase single characters or ranges using iterators.
* **`replace(size_t pos, size_t len, const std::string& str)`**
    Replaces a part of the string with a new string. The section from `pos` with length `len` is replaced by the contents of `str`.
* **`swap(std::string& other)`**
    Exchanges the contents of the string with another string `other`. This is a very fast operation, as it only swaps internal pointers.
* **`clear()`**
    Erases all characters from the string. The string becomes empty, but its allocated capacity may not be affected.

***
### String Operations
***
* **`substr(size_t pos = 0, size_t len = npos)`**
    Returns a new string that is a substring of the current string. The substring starts at `pos` and has a length of `len`.
* **`find(const std::string& str, size_t pos = 0)`**
    Searches for the first occurrence of a substring `str` starting from `pos`. It returns the starting position if found, or `std::string::npos` if not.
* **`rfind(const std::string& str, size_t pos = npos)`**
    Searches for the last occurrence of a substring `str`, searching backward from `pos`. It returns the starting position if found, or `std::string::npos` if not.
* **`find_first_of(const std::string& str, size_t pos = 0)`**
    Searches for the first occurrence of any character from `str` in the current string. It returns the position of the character, or `npos` if none are found.
* **`compare(const std::string& str)`**
    Compares the string with another string `str`. It returns a negative value if the string is less, zero if they are equal, or a positive value if it's greater.

***
### Data Access
***
* **`c_str()`**
    Returns a pointer to a null-terminated, read-only C-style character array. This is useful for interoperating with functions from the C standard library.
* **`data()`**
    Returns a pointer to the first character of the string's internal storage. Unlike `c_str()`, this pointer is not guaranteed to be null-terminated in C++11, but is in C++14 and later.



```
#include <iostream>
#include <string>    // Required for using the std::string class
#include <stdexcept> // For catching exceptions from string::at()

// This program demonstrates the usage of various functions from the std::string class.
// All explanations are provided directly within the comments of the code.

int main() {
    std::cout << "--- Part 1: Constructors and Initialization ---\n";

    // 1. std::string() - Default constructor, creates an empty string.
    std::string s1;
    std::cout << "s1 (empty string): '" << s1 << "'\n";

    // 2. std::string(const std::string& str) - Copy constructor.
    std::string s2("Hello, world!");
    std::string s3 = s2; // Copy of s2
    std::cout << "s3 (copy of s2): '" << s3 << "'\n";

    // 3. std::string(const char* s) - From a C-style string.
    std::string s4 = "C++ strings are great.";
    std::cout << "s4 (from C-style string): '" << s4 << "'\n";

    // 4. std::string(size_t n, CharT c) - Initializes with 'n' copies of character 'c'.
    std::string s5(5, '*');
    std::cout << "s5 (5 asterisks): '" << s5 << "'\n";
    std::cout << "-----------------------------------------\n";

    std::cout << "--- Part 2: Capacity Functions ---\n";
    std::string capacityString = "Testing capacity";

    // 5. size() and length() - Returns the number of characters in the string. Both are synonyms.
    std::cout << "capacityString: '" << capacityString << "'\n";
    std::cout << "Size of capacityString: " << capacityString.size() << "\n";
    std::cout << "Length of capacityString: " << capacityString.length() << "\n";

    // 6. empty() - Checks if the string is empty.
    std::cout << "Is capacityString empty? " << (capacityString.empty() ? "Yes" : "No") << "\n";
    std::string emptyString;
    std::cout << "Is emptyString empty? " << (emptyString.empty() ? "Yes" : "No") << "\n";

    // 7. capacity() - Returns the size of the allocated storage space.
    std::cout << "Initial capacity of capacityString: " << capacityString.capacity() << "\n";
    
    // 8. reserve(size_t n) - Requests a change in capacity.
    capacityString.reserve(100);
    std::cout << "Capacity after reserve(100): " << capacityString.capacity() << "\n";

    // 9. resize(size_t n) - Resizes the string, adding or removing characters.
    capacityString.resize(5);
    std::cout << "After resize(5), string is: '" << capacityString << "'\n";
    std::cout << "New size: " << capacityString.size() << "\n";
    std::cout << "-----------------------------------------\n";

    std::cout << "--- Part 3: Element Access ---\n";
    std::string accessString = "access";

    // 10. at(pos) - Accesses a character with bounds checking. Throws an exception if out of range.
    std::cout << "Character at index 2 (using at()): " << accessString.at(2) << "\n";
    try {
        std::cout << accessString.at(10) << "\n"; // This will throw an exception
    } catch (const std::out_of_range& e) {
        std::cerr << "Caught exception from at(): " << e.what() << "\n";
    }

    // 11. operator[] - Accesses a character without bounds checking.
    std::cout << "Character at index 2 (using []): " << accessString[2] << "\n";

    // 12. front() - Returns a reference to the first character.
    std::cout << "First character: " << accessString.front() << "\n";

    // 13. back() - Returns a reference to the last character.
    std::cout << "Last character: " << accessString.back() << "\n";
    std::cout << "-----------------------------------------\n";

    std::cout << "--- Part 4: Modifiers ---\n";
    std::string modifyString = "Hello";

    // 14. append(str) - Appends another string.
    modifyString.append(", World!");
    std::cout << "After append: '" << modifyString << "'\n";

    // 15. push_back(c) - Appends a single character.
    modifyString.push_back('!');
    std::cout << "After push_back: '" << modifyString << "'\n";

    // 16. insert(pos, str) - Inserts a string at a specific position.
    modifyString.insert(5, " there");
    std::cout << "After insert: '" << modifyString << "'\n";

    // 17. erase(pos, len) - Erases a substring.
    modifyString.erase(5, 6); // Erase " there"
    std::cout << "After erase: '" << modifyString << "'\n";

    // 18. replace(pos, len, str) - Replaces a part of the string.
    modifyString.replace(0, 5, "Hi"); // Replace "Hello" with "Hi"
    std::cout << "After replace: '" << modifyString << "'\n";

    // 19. clear() - Clears the string, making it empty.
    modifyString.clear();
    std::cout << "After clear, string is: '" << modifyString << "' (size: " << modifyString.size() << ")\n";
    std::cout << "-----------------------------------------\n";

    std::cout << "--- Part 5: String Operations & Searching ---\n";
    std::string searchString = "The quick brown fox jumps over the lazy dog.";

    // 20. substr(pos, len) - Returns a substring.
    std::string substring = searchString.substr(16, 3); // Get "fox"
    std::cout << "Substring from index 16 for 3 chars: '" << substring << "'\n";

    // 21. find(str, pos) - Finds the first occurrence of a substring. Returns npos if not found.
    size_t pos_find = searchString.find("fox");
    if (pos_find != std::string::npos) {
        std::cout << "Found 'fox' at position: " << pos_find << "\n";
    }

    // 22. rfind(str, pos) - Finds the last occurrence of a substring.
    size_t pos_rfind = searchString.rfind("the");
    if (pos_rfind != std::string::npos) {
        std::cout << "Last 'the' found at position: " << pos_rfind << "\n";
    }

    // 23. compare(str) - Compares the string with another string.
    std::string otherString = "The quick brown fox";
    int compare_result = searchString.compare(0, 19, otherString); // Compare the first 19 characters
    std::cout << "Comparing '" << searchString.substr(0, 19) << "' with '" << otherString << "': " << compare_result << "\n";
    std::cout << "-----------------------------------------\n";

    std::cout << "--- Part 6: Data Access ---\n";
    std::string dataString = "Data access";

    // 24. c_str() - Returns a const pointer to a null-terminated C-style string.
    const char* c_str_ptr = dataString.c_str();
    std::cout << "Using c_str(): " << c_str_ptr << "\n";

    // 25. data() - Returns a pointer to the internal character array.
    const char* data_ptr = dataString.data();
    std::cout << "Using data(): " << data_ptr << "\n";

    return 0;
}


```
#include <iostream>
#include <string>        // For std::string
#include <string_view>   // Required for using the std::string_view class
#include <stdexcept>     // For catching exceptions from string_view::at()

// This program demonstrates the usage of various functions from the std::string_view class.
// All explanations are provided directly within the comments of the code.

int main() {
    std::cout << "--- Part 1: Constructors and Initialization ---\n";
    std::string my_string = "Hello, C++17!";

    // 1. std::string_view(const char* s) - From a null-terminated C-style string literal.
    // This creates a view of the literal's memory without a copy.
    std::string_view sv1 = "A literal string.";
    std::cout << "sv1 (from literal): '" << sv1 << "'\n";

    // 2. std::string_view(const std::string& str) - From an std::string.
    // This is a very common use case. It creates a view of my_string's data.
    std::string_view sv2(my_string);
    std::cout << "sv2 (from std::string): '" << sv2 << "'\n";

    // 3. std::string_view() - The default constructor creates an empty view.
    std::string_view empty_view;
    std::cout << "empty_view: '" << empty_view << "'\n";
    std::cout << "-----------------------------------------\n";


    std::cout << "--- Part 2: Capacity Functions ---\n";
    std::string_view capacity_view = "capacity test";

    // 4. size() and length() - Returns the number of characters in the view.
    // These are synonyms and return the same value.
    std::cout << "capacity_view: '" << capacity_view << "'\n";
    std::cout << "Size of capacity_view: " << capacity_view.size() << "\n";
    std::cout << "Length of capacity_view: " << capacity_view.length() << "\n";

    // 5. empty() - Checks if the view has a size of 0.
    std::cout << "Is capacity_view empty? " << (capacity_view.empty() ? "Yes" : "No") << "\n";
    std::cout << "-----------------------------------------\n";


    std::cout << "--- Part 3: Element Access ---\n";
    std::string_view access_view = "access";

    // 6. at(pos) - Accesses a character with bounds checking.
    // This is safer as it throws an exception on an invalid index.
    std::cout << "Character at index 2 (using at()): " << access_view.at(2) << "\n";
    try {
        std::cout << access_view.at(10) << "\n"; // This will throw an exception
    } catch (const std::out_of_range& e) {
        std::cerr << "Caught exception from at(): " << e.what() << "\n";
    }

    // 7. operator[] - Accesses a character without bounds checking.
    // This is faster but unsafe if the index is out of bounds.
    std::cout << "Character at index 2 (using []): " << access_view[2] << "\n";

    // 8. front() - Returns a reference to the first character.
    std::cout << "First character: " << access_view.front() << "\n";

    // 9. back() - Returns a reference to the last character.
    std::cout << "Last character: " << access_view.back() << "\n";

    // 10. data() - Returns a const pointer to the start of the character sequence.
    // The sequence is not guaranteed to be null-terminated.
    std::cout << "Using data() pointer: " << access_view.data() << "\n";
    std::cout << "-----------------------------------------\n";


    std::cout << "--- Part 4: Modifiers (non-mutating the underlying data) ---\n";
    std::string_view modify_view = "prefix and suffix";

    // 11. remove_prefix(n) - Removes n characters from the beginning.
    // This only changes the view, not the original string data.
    modify_view.remove_prefix(8); // Now view is "and suffix"
    std::cout << "After remove_prefix(8): '" << modify_view << "'\n";

    // 12. remove_suffix(n) - Removes n characters from the end.
    modify_view.remove_suffix(7); // Now view is "and"
    std::cout << "After remove_suffix(7): '" << modify_view << "'\n";

    // 13. swap(v) - Efficiently swaps the content of two views.
    std::string_view other_view = "swapped";
    std::cout << "Before swap: modify_view='" << modify_view << "', other_view='" << other_view << "'\n";
    modify_view.swap(other_view);
    std::cout << "After swap: modify_view='" << modify_view << "', other_view='" << other_view << "'\n";
    std::cout << "-----------------------------------------\n";


    std::cout << "--- Part 5: Operations and Searching ---\n";
    std::string_view search_view = "The quick brown fox jumps over the lazy dog.";

    // 14. substr(pos, n) - Returns a new string_view of a substring.
    std::string_view sub_view = search_view.substr(16, 3); // View of "fox"
    std::cout << "Substring from index 16 for 3 chars: '" << sub_view << "'\n";

    // 15. find(str, pos) - Finds the first occurrence of a substring.
    // Returns the starting position if found, or npos if not.
    size_t pos_find = search_view.find("fox");
    if (pos_find != std::string_view::npos) {
        std::cout << "Found 'fox' at position: " << pos_find << "\n";
    }

    // 16. starts_with(sv) - Checks if the view starts with another view (C++20).
    std::cout << "Does the view start with 'The'? " << std::boolalpha << search_view.starts_with("The") << "\n";

    // 17. ends_with(sv) - Checks if the view ends with another view (C++20).
    std::cout << "Does the view end with 'dog.'? " << std::boolalpha << search_view.ends_with("dog.") << "\n";

    // 18. compare(sv) - Compares the view with another view.
    std::string_view other_view_compare = "The quick brown fox";
    int compare_result = search_view.substr(0, 19).compare(other_view_compare);
    std::cout << "Comparing '" << search_view.substr(0, 19) << "' with '" << other_view_compare << "': " << compare_result << "\n";
    std::cout << "-----------------------------------------\n";

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm> // Required for most of the functions demonstrated
#include <numeric>   // For std::iota, used to easily fill a vector

// This program demonstrates the usage of various functions from the <algorithm> header.
// Each section is commented to explain the function's purpose and usage.

// Helper function to print a vector's contents.
void printVector(const std::string& label, const std::vector<int>& vec) {
    std::cout << label << ": ";
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

// A simple predicate function to check if a number is even.
bool isEven(int n) {
    return n % 2 == 0;
}

int main() {
    // --- Part 1: Non-Modifying Sequence Operations ---
    std::cout << "--- Part 1: Non-Modifying Sequence Operations ---\n";
    std::vector<int> myVec = {1, 2, 3, 4, 5, 6};
    printVector("Original Vector", myVec);

    // all_of(first, last, pred) - Checks if all elements satisfy a condition.
    // The predicate (lambda function here) checks if the number is greater than 0.
    if (std::all_of(myVec.begin(), myVec.end(), [](int i){ return i > 0; })) {
        std::cout << "all_of: All elements are positive.\n";
    }

    // any_of(first, last, pred) - Checks if at least one element satisfies a condition.
    // The predicate checks if the number is 6.
    if (std::any_of(myVec.begin(), myVec.end(), [](int i){ return i == 6; })) {
        std::cout << "any_of: At least one element is 6.\n";
    }

    // none_of(first, last, pred) - Checks if no elements satisfy a condition.
    // The predicate checks if the number is 100.
    if (std::none_of(myVec.begin(), myVec.end(), [](int i){ return i == 100; })) {
        std::cout << "none_of: No elements are 100.\n";
    }

    // find(first, last, val) - Finds the first occurrence of a value.
    auto find_it = std::find(myVec.begin(), myVec.end(), 4);
    if (find_it != myVec.end()) {
        std::cout << "find: Found element 4 at position " << std::distance(myVec.begin(), find_it) << ".\n";
    }

    // find_if(first, last, pred) - Finds the first element satisfying a condition.
    auto find_if_it = std::find_if(myVec.begin(), myVec.end(), isEven);
    if (find_if_it != myVec.end()) {
        std::cout << "find_if: Found first even number: " << *find_if_it << "\n";
    }

    // count(first, last, val) - Counts occurrences of a value.
    std::vector<int> countVec = {1, 2, 2, 3, 4, 2};
    std::cout << "count: The number 2 appears " << std::count(countVec.begin(), countVec.end(), 2) << " times.\n";
    
    // count_if(first, last, pred) - Counts elements satisfying a condition.
    std::cout << "count_if: There are " << std::count_if(countVec.begin(), countVec.end(), isEven) << " even numbers.\n";

    std::cout << "-----------------------------------------\n";

    // --- Part 2: Modifying Sequence Operations ---
    std::cout << "--- Part 2: Modifying Sequence Operations ---\n";
    std::vector<int> modifyVec = {10, 20, 30, 40, 50};
    printVector("Original", modifyVec);

    // replace(first, last, old_val, new_val) - Replaces all occurrences of a value.
    std::replace(modifyVec.begin(), modifyVec.end(), 30, 99);
    printVector("After replace(30, 99)", modifyVec);

    // transform(first, last, result, op) - Applies a function to each element.
    std::vector<int> transformedVec(modifyVec.size());
    std::transform(modifyVec.begin(), modifyVec.end(), transformedVec.begin(), [](int i){ return i * 2; });
    printVector("After transform (doubling)", transformedVec);

    // reverse(first, last) - Reverses the order of elements.
    std::reverse(modifyVec.begin(), modifyVec.end());
    printVector("After reverse", modifyVec);

    // rotate(first, n_first, last) - Performs a left rotation.
    std::rotate(modifyVec.begin(), modifyVec.begin() + 2, modifyVec.end());
    printVector("After rotate (by 2)", modifyVec);

    // remove(first, last, val) - Removes a specific value (moves them to the end).
    // It returns an iterator to the new end of the logical range.
    std::vector<int> removeVec = {1, 2, 3, 2, 4, 5, 2};
    printVector("Original removeVec", removeVec);
    auto new_end_it = std::remove(removeVec.begin(), removeVec.end(), 2);
    // The actual vector size is unchanged, but we can erase the extra elements.
    removeVec.erase(new_end_it, removeVec.end());
    printVector("After remove(2) and erase", removeVec);

    std::cout << "-----------------------------------------\n";

    // --- Part 3: Partitioning Operations ---
    std::cout << "--- Part 3: Partitioning Operations ---\n";
    std::vector<int> partitionVec = {1, 6, 2, 7, 3, 8, 4, 9, 5};
    printVector("Original", partitionVec);

    // partition(first, last, pred) - Moves elements satisfying a predicate to the front.
    // The relative order of elements within each partition is not guaranteed.
    std::partition(partitionVec.begin(), partitionVec.end(), isEven);
    printVector("After partition (even numbers first)", partitionVec);

    std::cout << "-----------------------------------------\n";

    // --- Part 4: Sorting and Related Operations ---
    std::cout << "--- Part 4: Sorting and Related Operations ---\n";
    std::vector<int> sortVec = {8, 1, 4, 3, 7, 2, 5, 6};
    printVector("Original", sortVec);

    // sort(first, last) - Sorts the elements in ascending order.
    std::sort(sortVec.begin(), sortVec.end());
    printVector("After sort", sortVec);

    // nth_element(first, nth, last) - Places the nth element in its sorted position.
    std::vector<int> nthVec = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    std::nth_element(nthVec.begin(), nthVec.begin() + 4, nthVec.end()); // 4th element (index 4)
    std::cout << "nth_element: The element at index 4 is " << nthVec[4] << ".\n";
    printVector("After nth_element(index 4)", nthVec);

    // merge(first1, last1, first2, last2, result) - Merges two sorted ranges.
    std::vector<int> vec1 = {1, 3, 5};
    std::vector<int> vec2 = {2, 4, 6};
    std::vector<int> mergedVec(vec1.size() + vec2.size());
    std::merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), mergedVec.begin());
    printVector("Merged two sorted vectors", mergedVec);

    std::cout << "-----------------------------------------\n";

    // --- Part 5: Min/Max Operations ---
    std::cout << "--- Part 5: Min/Max Operations ---\n";
    std::vector<int> minMaxVec = {5, 2, 8, 1, 9, 4};
    printVector("Original", minMaxVec);

    // min_element(first, last) - Finds the iterator to the smallest element.
    auto min_it = std::min_element(minMaxVec.begin(), minMaxVec.end());
    std::cout << "min_element: Smallest element is " << *min_it << "\n";

    // max_element(first, last) - Finds the iterator to the largest element.
    auto max_it = std::max_element(minMaxVec.begin(), minMaxVec.end());
    std::cout << "max_element: Largest element is " << *max_it << "\n";

    // min(a, b) and max(a, b) - Compares two values.
    int x = 10, y = 20;
    std::cout << "min(10, 20) is: " << std::min(x, y) << "\n";
    std::cout << "max(10, 20) is: " << std::max(x, y) << "\n";

    return 0;
}

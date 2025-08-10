### source

```
https://cplusplus.com/reference/algorithm/
```

It would be impractical and extremely lengthy to list *every single* function in the `<algorithm>` header, as it contains over a hundred functions, many of which have multiple overloads. A comprehensive list would be overwhelming and difficult to use.

Instead, here is a list of the most common and useful functions, categorized by their purpose, with a brief explanation for each. This provides a practical overview of what the `<algorithm>` header offers.

### Non-Modifying Sequence Operations
***
* **`all_of(first, last, pred)`**
    Tests if a predicate function returns `true` for all elements in a range. It returns `false` on the first element that fails the test.
* **`any_of(first, last, pred)`**
    Tests if a predicate function returns `true` for at least one element in a range. It returns `true` on the first element that passes the test.
* **`none_of(first, last, pred)`**
    Tests if a predicate function returns `true` for no elements in a range. It returns `false` on the first element that passes the test.
* **`for_each(first, last, func)`**
    Applies a function to every element in a range. The return value is the function itself, which can be useful for stateful function objects.
* **`find(first, last, val)`**
    Finds the first occurrence of a specific value in a range. It returns an iterator to the element or `last` if the element is not found.
* **`find_if(first, last, pred)`**
    Finds the first element in a range for which a predicate function returns `true`. It returns an iterator to that element or `last` if no such element is found.
* **`find_if_not(first, last, pred)`**
    Finds the first element in a range for which a predicate function returns `false`. It returns an iterator to that element or `last` if no such element is found.
* **`count(first, last, val)`**
    Counts the number of elements in a range that are equal to a given value. It returns the count as a number.
* **`count_if(first, last, pred)`**
    Counts the number of elements in a range for which a predicate function returns `true`. It returns the count as a number.
* **`mismatch(first1, last1, first2)`**
    Compares two ranges element-by-element and finds the first position where they differ. It returns a pair of iterators pointing to the first mismatching elements.
* **`equal(first1, last1, first2)`**
    Tests if two ranges are equal by comparing elements pairwise. It returns `true` if all elements are equal, and `false` otherwise.
* **`is_permutation(first1, last1, first2)`**
    Tests if one range is a permutation of another. It returns `true` if they contain the same elements, possibly in a different order.
* **`search(first1, last1, first2, last2)`**
    Searches for the first occurrence of a sub-sequence within a range. It returns an iterator to the start of the sub-sequence or `last1` if not found.

---

### Modifying Sequence Operations
***
* **`copy(first, last, result)`**
    Copies all elements from a source range to a destination range. The destination must have enough space to hold all the elements.
* **`copy_if(first, last, result, pred)`**
    Copies elements from a source range to a destination range only if they satisfy a predicate. The destination must have enough space.
* **`transform(first, last, result, op)`**
    Applies a unary function `op` to each element in a range and stores the result in another range. The output is a transformed version of the original.
* **`replace(first, last, old_val, new_val)`**
    Replaces all occurrences of a specific value in a range with a new value.
* **`replace_if(first, last, pred, new_val)`**
    Replaces elements in a range with a new value if they satisfy a given predicate.
* **`fill(first, last, val)`**
    Assigns a specific value to every element in a range.
* **`swap(a, b)`**
    Exchanges the values of two variables or elements. There is also a `std::swap_ranges` for entire ranges.
* **`reverse(first, last)`**
    Reverses the order of the elements in a range.
* **`rotate(first, n_first, last)`**
    Performs a left rotation of the elements in a range. The element at `n_first` becomes the new first element.
* **`remove(first, last, val)`**
    Removes all elements in a range that are equal to a specific value. It returns a new "past-the-end" iterator.
* **`remove_if(first, last, pred)`**
    Removes all elements in a range for which a predicate function returns `true`. It returns a new "past-the-end" iterator.
* **`unique(first, last)`**
    Removes consecutive duplicate elements from a sorted range. It returns a new "past-the-end" iterator.

---

### Partitioning Operations
***
* **`is_partitioned(first, last, pred)`**
    Tests if a range is partitioned based on a predicate. A partitioned range has all elements satisfying the predicate at the beginning.
* **`partition(first, last, pred)`**
    Rearranges elements in a range such that all elements satisfying the predicate come before all elements that don't. It returns an iterator to the first element that doesn't satisfy the predicate.
* **`stable_partition(first, last, pred)`**
    Like `partition`, but it maintains the relative order of elements within each partition.

---

### Sorting and Related Operations
***
* **`sort(first, last)`**
    Sorts the elements in a range in ascending order.
* **`stable_sort(first, last)`**
    Sorts the elements in a range while maintaining the relative order of equal elements.
* **`partial_sort(first, middle, last)`**
    Partially sorts a range so that the first `middle - first` elements are the smallest elements from the entire range, and are sorted.
* **`nth_element(first, nth, last)`**
    Rearranges the elements in a range such that the element at the `nth` position is the element that would be there in a sorted sequence. All elements before `nth` are less than or equal to it.
* **`is_sorted(first, last)`**
    Checks if the elements in a range are sorted.
* **`merge(first1, last1, first2, last2, result)`**
    Merges two sorted ranges into a single sorted range.

---

### Min/Max Operations
***
* **`min_element(first, last)`**
    Finds the smallest element in a range. It returns an iterator to the smallest element.
* **`max_element(first, last)`**
    Finds the largest element in a range. It returns an iterator to the largest element.
* **`min(a, b)` and `max(a, b)`**
    Finds the minimum or maximum of two values. There are also overloads for initializer lists.



```
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


```
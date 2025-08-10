#include <iostream>
#include <vector>
#include <numeric>   // Required for most of the functions demonstrated
#include <string>

// This program demonstrates the usage of various functions from the <numeric> header.
// Each section is commented to explain the function's purpose and usage.

// Helper function to print a vector's contents.
void printVector(const std::string& label, const std::vector<int>& vec) {
    std::cout << label << ": ";
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

int main() {
    // --- Part 1: Accumulation and Reduction ---
    std::cout << "--- Part 1: Accumulation and Reduction ---\n";
    std::vector<int> myVec = {1, 2, 3, 4, 5};
    printVector("Original Vector", myVec);

    // 1. accumulate(first, last, init) - Calculates the sum of all elements.
    // The third argument 'init' is the initial value for the sum.
    int sum = std::accumulate(myVec.begin(), myVec.end(), 0);
    std::cout << "accumulate: The sum of elements is " << sum << ".\n";

    // accumulate can also take a custom binary operation (lambda or function object).
    // Here we use it to calculate the product of all elements.
    int product = std::accumulate(myVec.begin(), myVec.end(), 1, std::multiplies<int>());
    std::cout << "accumulate (with multiplication): The product of elements is " << product << ".\n\n";

    // --- Part 2: Sequence Generation and Transformation ---
    std::cout << "--- Part 2: Sequence Generation and Transformation ---\n";

    // 2. iota(first, last, value) - Fills a range with sequential values.
    // The sequence starts from 'value' and increments by 1 for each element.
    std::vector<int> iotaVec(5); // Create a vector of size 5
    std::iota(iotaVec.begin(), iotaVec.end(), 10);
    printVector("iota: Vector filled with sequence starting at 10", iotaVec);

    // 3. partial_sum(first, last, result) - Computes the partial sums.
    // Each element in the result is the sum of the preceding elements from the input.
    std::vector<int> partialSumVec(myVec.size());
    std::partial_sum(myVec.begin(), myVec.end(), partialSumVec.begin());
    printVector("partial_sum: Running totals", partialSumVec);

    // 4. adjacent_difference(first, last, result) - Computes the difference between adjacent elements.
    // The first element of the result is the same as the first element of the input.
    std::vector<int> diffVec(myVec.size());
    std::adjacent_difference(myVec.begin(), myVec.end(), diffVec.begin());
    printVector("adjacent_difference: Differences between elements", diffVec);
    std::cout << "\n";

    // --- Part 3: Inner Products and Other Operations ---
    std::cout << "--- Part 3: Inner Products and Other Operations ---\n";

    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {4, 5, 6};

    // 5. inner_product(first1, last1, first2, init) - Computes the inner product.
    // The inner product is the sum of the products of corresponding elements.
    int innerProduct = std::inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0);
    std::cout << "inner_product: " << innerProduct << " (which is 1*4 + 2*5 + 3*6)\n";

    // 6. gcd(a, b) - Computes the greatest common divisor (C++17 and later).
    // This is a free function in the <numeric> header.
    std::cout << "gcd: The greatest common divisor of 12 and 18 is " << std::gcd(12, 18) << "\n";

    // 7. lcm(a, b) - Computes the least common multiple (C++17 and later).
    // This is also a free function in the <numeric> header.
    std::cout << "lcm: The least common multiple of 12 and 18 is " << std::lcm(12, 18) << "\n";

    return 0;
}

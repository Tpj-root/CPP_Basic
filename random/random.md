### source

```
https://cplusplus.com/reference/random/
```


The C++ standard library's random number generation facilities are primarily located in the `<random>` header. It's not just a list of functions, but a set of classes for **random number engines** and **random number distributions** that work together. Here's a breakdown of the key components.

***

### Random Number Engines

These classes generate a sequence of pseudo-random numbers. You typically choose one and instantiate it once.

* **`std::default_random_engine`**: A basic, implementation-defined pseudo-random number generator. It's a good starting point for simple use cases.
* **`std::minstd_rand`** and **`std::minstd_rand0`**: A simple linear congruential generator with a small state. It's a small and fast generator, but not suitable for high-quality applications.
* **`std::mt19937`** and **`std::mt19937_64`**: The Mersenne Twister engine, widely used for its high quality and long period. The `_64` version works with 64-bit integers, which is useful for larger ranges.
* **`std::ranlux24`** and **`std::ranlux48`**: A `ranlux` engine, known for generating high-quality pseudo-random numbers with a very long period. It is slower than `mt19937` but provides a higher degree of randomness.
* **`std::knuth_b`**: A Knuth-style subtract-with-carry generator. This provides excellent randomness but is slower than the Mersenne Twister.
* **`std::random_device`**: A non-deterministic engine that produces truly random numbers from the operating system or hardware. It's often used to seed a pseudo-random engine for better security.

***

### Random Number Distributions

These classes take a random number engine as input and transform its output into numbers that fit a specific statistical distribution.

* **`std::uniform_int_distribution`**: Generates random integers in a specified inclusive range `[a, b]`. This is the most common distribution for generating simple integer values.
* **`std::uniform_real_distribution`**: Generates random floating-point numbers in a specified inclusive range `[a, b]`. This is ideal for generating real numbers, such as coordinates or probabilities.
* **`std::bernoulli_distribution`**: Generates boolean values (`true` or `false`) based on a specified probability. It is useful for simulating events with a binary outcome.
* **`std::normal_distribution`**: Generates numbers that follow a Gaussian (bell curve) distribution. You can specify the mean and standard deviation of the curve.
* **`std::poisson_distribution`**: Models the number of events occurring within a fixed interval of time or space. You specify the average number of events (mean).
* **`std::exponential_distribution`**: Models the time between two successive events in a Poisson process. It is useful for simulating waiting times.
* **`std::gamma_distribution`** and **`std::weibull_distribution`**: These generate numbers based on the gamma and Weibull probability distributions, respectively. They are used in statistical analysis and reliability engineering.
* **`std::chi_squared_distribution`** and **`std::fisher_f_distribution`**: These generate numbers based on the chi-squared and Fisher's F-distributions. They are primarily used in hypothesis testing and statistical analysis.
* **`std::student_t_distribution`**: Generates numbers based on the Student's t-distribution. It's commonly used for estimating population parameters when the sample size is small.
* **`std::discrete_distribution`**: Generates random integers from a custom set of probabilities. This is useful when you need to model an outcome where each choice has a specific, non-uniform probability.
* **`std::piecewise_constant_distribution`** and **`std::piecewise_linear_distribution`**: These distributions allow for generating numbers with a probability density that is defined by a series of constant or linear segments. They are used for complex, user-defined distributions.

***

### Utility Functions and Classes

* **`std::seed_seq`**: A class that generates a sequence of seeds from an arbitrary number of inputs. It is the recommended way to seed a random number engine to ensure better entropy.
* **`std::shuffle(first, last, g)`**: Randomly reorders the elements in a range. It takes a random number generator `g` to perform the shuffling.
* **`std::sample(first, last, result, n, g)`**: Randomly selects `n` elements from a range and copies them to a destination. It's a convenient way to get a random subset of data.


```
#include <iostream>
#include <vector>
#include <random>    // The core header for random number generation
#include <algorithm> // For std::shuffle
#include <numeric>   // For std::iota (to easily fill a vector)

// This program demonstrates how to use various components of the <random> header.
// All explanations are provided directly within the comments of the code.

int main() {
    // --- Part 1: Random Number Engines and Seeding ---
    std::cout << "--- Part 1: Random Number Engines and Seeding ---\n";

    // 1. std::random_device - A non-deterministic random number generator.
    // It is typically used as a seed for other, faster pseudo-random engines.
    // The numbers it produces are often from hardware or OS-level sources, making them more "truly" random.
    std::random_device rd;

    // 2. std::mt19937 - The Mersenne Twister engine.
    // This is a high-quality, widely-used pseudo-random number generator.
    // We seed it with the result from std::random_device for better randomness.
    std::mt19937 gen(rd());

    // 3. std::seed_seq - A helper class for generating a sequence of seeds.
    // This is the recommended way to seed an engine from multiple random sources.
    // Here we create a single seed value from rd().
    std::seed_seq ss{rd()};
    std::mt19937 seeded_gen(ss);

    // Using a different engine for demonstration: std::default_random_engine
    // This is a simple, implementation-defined engine.
    std::default_random_engine default_gen(rd());
    
    std::cout << "Random engines seeded and ready to use.\n\n";

    // --- Part 2: Random Number Distributions ---
    std::cout << "--- Part 2: Random Number Distributions ---\n";

    // 4. std::uniform_int_distribution - Generates uniformly distributed integers.
    // This is perfect for simulating a fair die roll.
    // The range is inclusive: [1, 6].
    std::uniform_int_distribution<> die_roll(1, 6);
    std::cout << "Rolling a 6-sided die 5 times: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << die_roll(gen) << " ";
    }
    std::cout << "\n";

    // 5. std::uniform_real_distribution - Generates uniformly distributed floating-point numbers.
    // Here, we generate a random percentage between 0.0 and 100.0.
    std::uniform_real_distribution<> percentage(0.0, 100.0);
    std::cout << "Generating a random percentage: " << percentage(gen) << "%\n";
    
    // 6. std::bernoulli_distribution - Generates a boolean value (true or false).
    // The constructor takes a probability as a floating-point value.
    // A probability of 0.7 means a 70% chance of 'true'.
    std::bernoulli_distribution coin_flip(0.7);
    std::cout << "Simulating 5 coin flips (70% chance of 'true'): ";
    for (int i = 0; i < 5; ++i) {
        std::cout << (coin_flip(gen) ? "Heads" : "Tails") << " ";
    }
    std::cout << "\n";

    // 7. std::normal_distribution - Generates numbers following a bell curve (Gaussian distribution).
    // The arguments are the mean and standard deviation.
    // This is useful for simulating values like test scores or heights.
    std::normal_distribution<> normal_dist(75.0, 10.0); // Mean 75, StdDev 10
    std::cout << "Generating 5 random test scores (mean 75, stddev 10): ";
    for (int i = 0; i < 5; ++i) {
        std::cout << normal_dist(gen) << " ";
    }
    std::cout << "\n\n";
    
    // --- Part 3: Algorithms Using Randomness ---
    std::cout << "--- Part 3: Algorithms Using Randomness ---\n";

    // 8. std::shuffle - Randomly reorders the elements in a range.
    // It takes a range (begin/end iterators) and a random number generator.
    std::vector<int> numbers(10);
    std::iota(numbers.begin(), numbers.end(), 1); // Fill with 1, 2, 3...
    std::cout << "Original vector: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    std::shuffle(numbers.begin(), numbers.end(), seeded_gen);
    std::cout << "Shuffled vector: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}


```
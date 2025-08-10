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

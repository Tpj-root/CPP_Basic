#include <iostream>
#include <future>      // The main header for all future-related components
#include <thread>      // For creating manual threads
#include <chrono>      // For timed waits
#include <stdexcept>   // For demonstrating exceptions
#include <vector>      // For using std::vector

// This program demonstrates the usage of various functions and classes from the <future> header.
// All explanations are provided directly within the comments of the code.

// A simple function to simulate a long-running calculation.
int calculate_sum(int a, int b) {
    std::cout << "  Calculating sum...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return a + b;
}

// A function that might throw an exception.
int calculate_with_error() {
    std::cout << "  Task started, but will throw an exception.\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    throw std::runtime_error("An error occurred during calculation!");
    return 0;
}

int main() {
    std::cout << "--- Part 1: std::async and std::future ---\n";
    
    // 1. std::async() - A global function to launch an asynchronous task.
    // It automatically returns a std::future object that will hold the result.
    std::future<int> async_future = std::async(std::launch::async, calculate_sum, 10, 20);

    std::cout << "  Main thread is not blocked and continues to work.\n";
    std::cout << "  Waiting for the asynchronous task to complete...\n";

    // 2. std::future::wait() - Waits for the result to become available.
    // It's a non-blocking way to check for completion if you don't need the value yet.
    async_future.wait();
    
    // 3. std::future::get() - Retrieves the result. This blocks if the result is not ready.
    // NOTE: std::future::get() can only be called once.
    try {
        int result = async_future.get();
        std::cout << "  Result from async task: " << result << "\n\n";
    } catch (const std::exception& e) {
        std::cout << "  Exception caught: " << e.what() << "\n\n";
    }


    std::cout << "--- Part 2: Timed Waits (std::future::wait_for) ---\n";
    
    std::future<int> timed_future = std::async(calculate_sum, 50, 50);
    std::cout << "  Waiting for 1 second with wait_for()...\n";

    // 4. std::future::wait_for(duration) - Waits for a specified time.
    // It returns a status code (std::future_status).
    if (timed_future.wait_for(std::chrono::seconds(1)) == std::future_status::timeout) {
        std::cout << "  Timeout! The task is not yet ready.\n";
    }

    std::cout << "  Waiting for the final result...\n";
    timed_future.wait();
    int timed_result = timed_future.get();
    std::cout << "  Final result from timed wait: " << timed_result << "\n\n";


    std::cout << "--- Part 3: std::promise (Manual Asynchronous Communication) ---\n";
    
    // 5. std::promise - An object that "promises" to provide a result in the future.
    std::promise<int> promise;
    
    // 6. std::promise::get_future() - Gets a future object from the promise.
    // This future is how other threads will access the result.
    std::future<int> promise_future = promise.get_future();

    // The producer thread will set the value.
    auto producer_task = [](std::promise<int> p) {
        std::cout << "  Producer thread started...\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        // 7. std::promise::set_value() - Stores the result and signals waiting futures.
        p.set_value(42);
        std::cout << "  Producer thread set the value 42.\n";
    };

    std::thread producer_thread(producer_task, std::move(promise));

    std::cout << "  Main thread is waiting for the promise to be fulfilled...\n";
    int promise_result = promise_future.get();
    std::cout << "  Result from promise: " << promise_result << "\n";
    
    producer_thread.join();
    
    // Demonstrating exception handling with std::promise.
    std::promise<int> promise_with_error;
    std::future<int> future_with_error = promise_with_error.get_future();
    auto exception_producer = [](std::promise<int> p) {
        try {
            calculate_with_error();
        } catch (...) {
            // 8. std::promise::set_exception() - Stores an exception in the shared state.
            p.set_exception(std::current_exception());
        }
    };
    std::thread exception_thread(exception_producer, std::move(promise_with_error));
    
    try {
        future_with_error.get();
    } catch (const std::exception& e) {
        std::cout << "  Caught expected exception from promise: " << e.what() << "\n\n";
    }
    exception_thread.join();


    std::cout << "--- Part 4: std::packaged_task ---\n";
    
    // 9. std::packaged_task - Wraps a callable object so its result can be retrieved via a future.
    // It's a high-level way to create a promise/future pair for a function.
    std::packaged_task<int(int, int)> task(calculate_sum);
    
    // 10. std::packaged_task::get_future() - Returns a future to the result.
    std::future<int> task_future = task.get_future();

    // Execute the task on a separate thread.
    std::thread task_thread(std::move(task), 100, 200);

    std::cout << "  Main thread waiting for the packaged task to complete...\n";
    int task_result = task_future.get();
    std::cout << "  Result from packaged task: " << task_result << "\n";
    
    task_thread.join();
    std::cout << "\n";


    std::cout << "--- Part 5: std::shared_future (Multiple Consumers) ---\n";
    
    std::future<int> original_future = std::async(calculate_sum, 1000, 2000);

    // 11. std::future::share() - Converts a unique future into a shared future.
    // std::future is move-only, but std::shared_future is copyable.
    std::shared_future<int> shared_future = original_future.share();

    // Now, multiple threads can wait for and access the same result.
    auto consumer_task = [&](int id) {
        std::cout << "  Consumer " << id << " waiting for the shared result...\n";
        // All consumers can access the same shared_future object.
        int result = shared_future.get();
        std::cout << "  Consumer " << id << " received result: " << result << "\n";
    };
    
    std::thread consumer1(consumer_task, 1);
    std::thread consumer2(consumer_task, 2);
    
    consumer1.join();
    consumer2.join();
    
    // 12. std::future::valid() - Checks if the future object has a shared state.
    // The original future is now invalid because it was shared.
    std::cout << "  Is original_future valid? " << std::boolalpha << original_future.valid() << "\n";
    // The shared_future is still valid and can be used again (e.g., to get the result again).
    std::cout << "  Is shared_future valid? " << std::boolalpha << shared_future.valid() << "\n";
    
    return 0;
}

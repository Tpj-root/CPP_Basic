### source

```
https://cplusplus.com/reference/future/
```

The `<future>` header provides a set of classes and functions for handling asynchronous operations. The core idea is to separate the *promise* of a result from the *actual* result. This allows a thread to launch a task and get a `future` object immediately, which it can use later to retrieve the result when it's ready, without blocking the entire time.

---
### **`std::future`**
***
* **`get()`**
    Waits for the asynchronous operation to complete and then retrieves its result. It can only be called once, and it will throw an exception if the associated task threw one.

* **`wait()`**
    Waits for the asynchronous operation to finish without retrieving the result. This function is useful if you just need to ensure the task is done but don't need its return value.

* **`wait_for(duration)`**
    Waits for a specified duration to see if the result is available. It returns one of three statuses: `future_status::ready`, `future_status::timeout`, or `future_status::deferred`.

* **`wait_until(time_point)`**
    Waits until a specific point in time for the result to be available. It returns the same status values as `wait_for`.

* **`valid()`**
    Checks if the `future` object is associated with a shared state. A `future` is not valid after you call `get()` or after it's moved from.

* **`share()`**
    Transfers the ownership of the future's shared state to a `std::shared_future` object. The original `std::future` object becomes invalid after this call.

---
### **`std::shared_future`**
***
* **`get()`**
    Behaves like `std::future::get()`, but it can be called by multiple `shared_future` objects, and multiple times, to retrieve the same result.

* **`wait()`, `wait_for()`, `wait_until()`, `valid()`**
    These functions have the same behavior as their `std::future` counterparts. The main difference is that a `std::shared_future` is copyable, allowing multiple threads to hold a copy and wait for the same result.

---
### **`std::promise`**
***
* **`set_value(value)`**
    Stores a value into the shared state and makes the shared state ready. This unblocks any threads waiting on an associated `future` or `shared_future`.

* **`set_exception(exception_ptr)`**
    Stores an exception in the shared state and makes it ready. The exception will be rethrown by any waiting `future` when its `get()` method is called.

* **`get_future()`**
    Returns a `std::future` object that is associated with the `promise`'s shared state. This is the mechanism for a producer thread to give a consumer thread a way to retrieve a result.

* **`set_value_at_thread_exit(value)`**, **`set_exception_at_thread_exit(exception_ptr)`**
    These functions store a value or exception in the shared state but only make it ready when the thread that called them exits.

---
### **`std::packaged_task`**
***
* **`get_future()`**
    Returns a `std::future` associated with the packaged task. This `future` will receive the return value or exception from the callable object when it is invoked.

* **`operator()`**
    Invokes the stored callable object. The return value or any thrown exception is stored in the shared state for the associated `future`.

* **`reset()`**
    Resets the packaged task, dissociating it from its old shared state and creating a new one. This allows the task to be run again.

---
### **Global Functions & Enums**
***
* **`std::async()`**
    A function that launches a callable object as an asynchronous task. It automatically returns a `std::future` that will hold the result of the function call.

* **`std::launch`**
    An enum class used with `std::async` to specify how the task should be executed. It can be `std::launch::async` (run on a new thread) or `std::launch::deferred` (run on the first call to `get()` or `wait()`).

* **`std::future_status`**
    An enum class returned by the timed wait functions (`wait_for` and `wait_until`). It indicates whether the result is ready, a timeout occurred, or the task is deferred.

* **`std::promise(allocator)`** (C++11), **`std::packaged_task(allocator)`** (C++11)
    Constructors that take an allocator argument, allowing you to specify the memory allocation strategy for the promise or packaged task.

For a deeper dive into how `std::async` works with different launch policies, you might find this video helpful: [std::async in cpp with background thread loading data example](https://www.youtube.com/watch?v=2eJm6tA4y2U).
http://googleusercontent.com/youtube_content/1



```
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


```
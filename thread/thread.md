### source

```
https://cplusplus.com/reference/thread/
```

The `<thread>` header in C++ provides a set of functions and classes for creating and managing threads, which are essential for concurrent programming. It allows you to execute multiple tasks simultaneously, making your programs more responsive and efficient.

***
### Thread Management
---
* **`std::thread`**
    A class that represents a single thread of execution. You can create a new thread by passing a callable object (function, lambda, or functor) and its arguments to its constructor.
* **`std::thread::join()`**
    Blocks the calling thread until the thread it represents has finished its execution. This is a crucial step to ensure a thread has completed its work before its resources are released.
* **`std::thread::detach()`**
    Separates the thread of execution from the `std::thread` object. The thread will continue to run in the background as a "daemon" and its resources will be released when it eventually finishes.
* **`std::thread::get_id()`**
    Returns a unique identifier for the thread. This can be useful for logging or debugging to distinguish between different threads.
* **`std::thread::hardware_concurrency()`**
    Returns the number of concurrent threads supported by the hardware. This value is a hint and is useful for determining how many threads to create for parallel tasks.

***
### Current Thread Functions
---
* **`std::this_thread::get_id()`**
    Returns the unique identifier of the thread that is currently executing. This is the equivalent of `std::thread::get_id()` but for the current thread.
* **`std::this_thread::yield()`**
    Hints to the scheduler that the current thread can be paused to allow other threads to run. It's a way to be a "good citizen" and prevent one thread from hogging the CPU.
* **`std::this_thread::sleep_for(duration)`**
    Blocks the current thread's execution for a specified time duration. It's often used to create delays or to allow other threads to run.
* **`std::this_thread::sleep_until(time_point)`**
    Blocks the current thread's execution until a specified point in time is reached. This is useful for scheduling tasks to run at a specific time.

***
### Thread State and Execution
---
* **`std::thread::joinable()`**
    Checks if a thread object represents an active thread of execution. It returns `true` if the thread is joinable or detachable, and `false` otherwise.
* **`std::thread::swap()`**
    Exchanges the underlying state (the thread of execution) of two `std::thread` objects. This is an efficient way to reassign thread handles without creating or destroying threads.
* **`std::thread::native_handle()`**
    Returns the platform-specific handle for the thread. This is for advanced use cases where you need to interact with the underlying operating system's thread API.



```
#include <iostream>
#include <thread>      // The core header for std::thread and related functions
#include <vector>      // For using std::vector
#include <chrono>      // For std::chrono::duration, std::chrono::seconds, etc.
#include <numeric>     // For std::accumulate

// This program demonstrates the usage of various functions from the <thread> header.
// All explanations are provided directly within the comments of the code.

// A function to be executed by a new thread.
void worker_function(int id) {
    std::cout << "  Worker thread " << id << " started.\n";
    // std::this_thread::sleep_for(duration) - Blocks the current thread for a specified duration.
    // This simulates a task that takes some time to complete.
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "  Worker thread " << id << " finished.\n";
}

// A function for a detached thread.
void detached_worker() {
    std::cout << "  Detached worker thread started. It will run independently.\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "  Detached worker thread finished its task.\n";
}

int main() {
    std::cout << "--- Part 1: Thread Creation and Management ---\n";
    
    // 1. std::thread - The class to represent a thread of execution.
    // The constructor takes a callable object (function, lambda, etc.) and its arguments.
    // This creates a new thread that will run worker_function with ID 101.
    std::thread t1(worker_function, 101);

    // 2. std::thread::get_id() - Returns a unique identifier for the thread.
    std::cout << "  Main thread ID: " << std::this_thread::get_id() << "\n";
    std::cout << "  Worker thread t1 ID: " << t1.get_id() << "\n";
    
    // 3. std::thread::joinable() - Checks if the thread object represents an active thread.
    std::cout << "  Is t1 joinable? " << std::boolalpha << t1.joinable() << "\n";
    
    // 4. std::thread::join() - Blocks the main thread until t1 has finished.
    // This is crucial to ensure the thread's resources are reclaimed properly.
    std::cout << "  Waiting for worker thread t1 to finish...\n";
    t1.join();
    std::cout << "  Worker thread t1 has been joined. Main thread can continue.\n";
    
    // After joining, the thread object no longer represents a thread of execution.
    std::cout << "  Is t1 joinable after join? " << std::boolalpha << t1.joinable() << "\n\n";


    std::cout << "--- Part 2: Detaching a Thread ---\n";

    // 5. std::thread::detach() - Separates the thread from the thread object.
    // The thread continues to run in the background (as a daemon thread).
    // The main program does not need to wait for it.
    std::thread t2(detached_worker);
    std::cout << "  Detaching thread t2...\n";
    t2.detach();
    
    std::cout << "  Is t2 joinable after detach? " << std::boolalpha << t2.joinable() << "\n";
    std::cout << "  Main thread is not waiting for t2 to finish and will now exit.\n";
    // NOTE: The detached thread t2 may not have time to print its "finished" message
    // before the main function returns and the program terminates.
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Add a small delay to see the detached thread's output.
    std::cout << "  Main thread exiting.\n\n";
    

    std::cout << "--- Part 3: Other Functions ---\n";

    // 6. std::thread::hardware_concurrency() - Returns the number of concurrent threads.
    // This is a hint for how many threads can run in parallel on the system.
    auto num_threads = std::thread::hardware_concurrency();
    std::cout << "  Hardware concurrency is: " << num_threads << "\n";
    
    std::cout << "  Using this to launch a pool of threads for a parallel task...\n";
    std::vector<std::thread> thread_pool;
    for (unsigned i = 0; i < num_threads; ++i) {
        // Here we create a pool of worker threads.
        thread_pool.emplace_back(worker_function, i);
    }
    
    // We must join all threads in the pool before the main thread exits.
    for (auto& t : thread_pool) {
        if (t.joinable()) {
            t.join();
        }
    }
    std::cout << "  All threads in the pool have been joined.\n\n";

    return 0;
}


```
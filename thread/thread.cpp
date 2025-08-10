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

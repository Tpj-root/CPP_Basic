#include <iostream>
#include <thread>        // For creating threads
#include <vector>        // For using vectors
#include <mutex>         // The core header for mutexes and lock wrappers
#include <chrono>        // For durations and timing
#include <string>        // For std::string
#include <shared_mutex>  // For std::shared_mutex (C++14)

// A simple global resource that needs protection.
int shared_counter = 0;
// A mutex to protect the shared_counter.
std::mutex counter_mutex;

// A simple class with data protected by a shared_mutex for readers and writers.
class ProtectedData {
private:
    std::string data = "initial data";
    mutable std::shared_mutex mtx; // shared_mutex protects the data
public:
    // A reader function (acquires a shared lock).
    std::string read_data() const {
        // std::shared_lock is an RAII wrapper for a shared_mutex.
        // It locks on construction and unlocks on destruction.
        std::shared_lock<std::shared_mutex> lock(mtx);
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
        return data;
    }
    // A writer function (acquires an exclusive lock).
    void write_data(const std::string& new_data) {
        // std::unique_lock is used to acquire an exclusive lock for writing.
        std::unique_lock<std::shared_mutex> lock(mtx);
        std::this_thread::sleep_for(std::chrono::milliseconds(200)); // Simulate work
        data = new_data;
    }
};

// A simple function that needs to be initialized only once.
void expensive_initialization() {
    std::cout << "    Expensive initialization started...\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "    Expensive initialization finished.\n";
}

int main() {
    std::cout << "--- Part 1: std::mutex and std::lock_guard ---\n";
    std::cout << "  Demonstrating a data race without a lock...\n";

    auto increment_without_lock = []() {
        for (int i = 0; i < 1000; ++i) {
            ++shared_counter; // This is a race condition!
        }
    };
    shared_counter = 0;
    std::thread t_race1(increment_without_lock);
    std::thread t_race2(increment_without_lock);
    t_race1.join();
    t_race2.join();
    std::cout << "  Final value (expected 2000): " << shared_counter << " (often incorrect)\n\n";

    std::cout << "  Demonstrating with std::mutex and std::lock_guard...\n";
    auto increment_with_lock_guard = []() {
        for (int i = 0; i < 1000; ++i) {
            // 1. std::lock_guard - An RAII wrapper for a mutex.
            // It locks the mutex on construction and unlocks it automatically on destruction.
            // This is the simplest and safest way to manage a mutex.
            std::lock_guard<std::mutex> lock(counter_mutex);
            ++shared_counter;
        }
    };
    shared_counter = 0;
    std::thread t_safe1(increment_with_lock_guard);
    std::thread t_safe2(increment_with_lock_guard);
    t_safe1.join();
    t_safe2.join();
    std::cout << "  Final value (correctly 2000): " << shared_counter << "\n\n";


    std::cout << "--- Part 2: std::unique_lock (Flexible Locking) ---\n";
    // std::unique_lock provides more flexibility than std::lock_guard.
    // We can manually manage its locking state.
    std::unique_lock<std::mutex> u_lock(counter_mutex, std::defer_lock); // 2. std::defer_lock - Do not lock on construction.
    std::cout << "  unique_lock created but not locked.\n";
    
    // We can lock it manually later.
    u_lock.lock();
    std::cout << "  unique_lock is now locked.\n";
    u_lock.unlock(); // We can also unlock it manually.
    std::cout << "  unique_lock is now unlocked.\n\n";
    
    
    std::cout << "--- Part 3: std::scoped_lock (Deadlock Prevention) ---\n";
    // This part demonstrates how to lock multiple mutexes safely.
    std::mutex m1, m2;
    auto deadlock_prone = [&]() {
        // This can cause a deadlock if t3 locks m1 and t4 locks m2,
        // and then each tries to lock the other's mutex.
        std::lock_guard<std::mutex> l1(m1);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::lock_guard<std::mutex> l2(m2);
        // Do something...
    };
    
    auto safe_locking = [&]() {
        // 3. std::scoped_lock (C++17) - Locks multiple mutexes safely.
        // It acquires the locks in an arbitrary but consistent order, preventing deadlocks.
        std::scoped_lock lock(m1, m2);
        std::cout << "  Locks m1 and m2 acquired safely.\n";
    };
    
    // NOTE: It is hard to reliably cause a deadlock, but scoped_lock protects against it.
    std::cout << "  Demonstrating std::scoped_lock for deadlock prevention...\n";
    std::thread t_safe_lock(safe_locking);
    std::thread t_safe_lock2(safe_locking);
    t_safe_lock.join();
    t_safe_lock2.join();
    std::cout << "\n";


    std::cout << "--- Part 4: std::shared_mutex and std::shared_lock ---\n";
    // std::shared_mutex allows multiple readers but only one writer at a time.
    ProtectedData protected_data;
    
    auto reader_task = [&]() {
        std::string data = protected_data.read_data();
        std::cout << "  Reader thread " << std::this_thread::get_id() << " reads: '" << data << "'\n";
    };
    
    auto writer_task = [&]() {
        protected_data.write_data("new updated data");
        std::cout << "  Writer thread " << std::this_thread::get_id() << " finished writing.\n";
    };

    std::cout << "  Demonstrating shared and exclusive locks...\n";
    std::thread readers[5];
    for (int i = 0; i < 5; ++i) {
        readers[i] = std::thread(reader_task);
    }
    std::thread writer(writer_task);

    for (int i = 0; i < 5; ++i) {
        readers[i].join();
    }
    writer.join();
    std::cout << "\n";


    std::cout << "--- Part 5: std::call_once (Single-time Execution) ---\n";
    // std::call_once is used to ensure that a function is executed exactly one time.
    std::once_flag flag;
    auto task_to_call_once = [&]() {
        // 4. std::call_once - Ensures the function is called exactly once.
        // No matter how many threads call this, the function inside will only run once.
        std::call_once(flag, expensive_initialization);
        std::cout << "  Thread " << std::this_thread::get_id() << " has finished its task.\n";
    };

    std::cout << "  Demonstrating std::call_once...\n";
    std::thread t_once1(task_to_call_once);
    std::thread t_once2(task_to_call_once);
    t_once1.join();
    t_once2.join();
    
    return 0;
}

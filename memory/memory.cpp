#include <iostream>
#include <memory>  // The core header for smart pointers and memory utilities
#include <string>  // For using std::string

// A simple class to demonstrate object lifetimes.
// We'll track its construction and destruction with print statements.
class Resource {
public:
    std::string name;
    
    // Constructor
    Resource(const std::string& n) : name(n) {
        std::cout << "  - Resource '" << name << "' created.\n";
    }

    // Destructor
    ~Resource() {
        std::cout << "  - Resource '" << name << "' destroyed.\n";
    }
    
    void do_something() {
        std::cout << "  - Resource '" << name << "' is doing something.\n";
    }
};

// A class with an overloaded address-of operator to show std::addressof.
class OverloadedAddress {
public:
    int value = 42;
    int* operator&() {
        // Return a false address to demonstrate std::addressof's purpose.
        return nullptr;
    }
};

int main() {
    // --- Part 1: Smart Pointers (The most important part of <memory>) ---
    std::cout << "--- Part 1: Smart Pointers ---\n";

    // 1. std::unique_ptr<T> - Exclusive ownership.
    // The object is owned by a single unique_ptr and is destroyed when the pointer goes out of scope.
    std::cout << "1. Demonstrating std::unique_ptr:\n";
    {
        // Use std::make_unique for safe and efficient creation.
        // It prevents memory leaks and exceptions.
        auto unique_res = std::make_unique<Resource>("unique_resource");
        unique_res->do_something();
    } // unique_res goes out of scope here, and the Resource is automatically destroyed.
    std::cout << "  unique_ptr has gone out of scope.\n\n";


    // 2. std::shared_ptr<T> - Shared ownership.
    // Multiple shared_ptrs can point to the same object. The object is deleted
    // only when the last shared_ptr is destroyed.
    std::cout << "2. Demonstrating std::shared_ptr:\n";
    {
        // Use std::make_shared for safety and performance (single allocation).
        auto shared_res1 = std::make_shared<Resource>("shared_resource");
        
        // We can create another shared_ptr pointing to the same object.
        auto shared_res2 = shared_res1;
        
        std::cout << "  shared_res1 use count: " << shared_res1.use_count() << "\n";
        std::cout << "  shared_res2 use count: " << shared_res2.use_count() << "\n";
        
    } // Both shared_res1 and shared_res2 go out of scope here.
      // The use count drops to 0, and the Resource is destroyed.
    std::cout << "  shared_ptrs have gone out of scope.\n\n";


    // 3. std::weak_ptr<T> - Non-owning reference.
    // Used to observe an object without affecting its lifetime.
    // It is primarily used to break circular references between shared_ptrs.
    std::cout << "3. Demonstrating std::weak_ptr:\n";
    std::shared_ptr<Resource> strong_ptr;
    std::weak_ptr<Resource> weak_ptr;
    {
        strong_ptr = std::make_shared<Resource>("weak_resource");
        weak_ptr = strong_ptr; // weak_ptr observes the shared_ptr's object.

        // To access the object from a weak_ptr, you must lock it to get a shared_ptr.
        // This check ensures the object still exists.
        if (auto locked_ptr = weak_ptr.lock()) {
            std::cout << "  weak_ptr is locked, object still alive. ";
            locked_ptr->do_something();
        } else {
            std::cout << "  weak_ptr is expired, object no longer exists.\n";
        }
    } // strong_ptr goes out of scope here, and the Resource is destroyed.
    std::cout << "  strong_ptr has gone out of scope.\n";

    // Now the weak_ptr is expired.
    if (auto locked_ptr = weak_ptr.lock()) {
        std::cout << "  (This should not be printed) weak_ptr is locked, object still alive.\n";
    } else {
        std::cout << "  weak_ptr is expired, object no longer exists.\n\n";
    }


    // --- Part 2: Low-Level Memory Utilities ---
    std::cout << "--- Part 2: Low-Level Memory Utilities ---\n";

    // 4. std::addressof(obj) - Gets the true memory address of an object.
    // This is important for classes that overload the '&' operator.
    std::cout << "4. Demonstrating std::addressof:\n";
    OverloadedAddress my_obj;
    // The compiler would use the overloaded operator&, returning nullptr.
    std::cout << "  Address using regular '&': " << &my_obj << "\n";
    // std::addressof bypasses the overload and returns the true address.
    std::cout << "  Address using std::addressof: " << std::addressof(my_obj) << "\n\n";

    // 5. std::uninitialized_fill(first, last, value) - Fills uninitialized memory.
    // This correctly constructs objects in a raw memory buffer.
    std::cout << "5. Demonstrating std::uninitialized_fill:\n";
    const int count = 5;
    // Allocate raw memory for 5 integers.
    int* raw_memory = static_cast<int*>(::operator new(sizeof(int) * count));

    // Fill the raw memory with the value 10.
    std::uninitialized_fill(raw_memory, raw_memory + count, 10);

    std::cout << "  Filled raw memory with: ";
    for (int i = 0; i < count; ++i) {
        std::cout << raw_memory[i] << " ";
    }
    std::cout << "\n";
    
    // Deallocate the memory.
    ::operator delete(raw_memory);

    return 0;
}

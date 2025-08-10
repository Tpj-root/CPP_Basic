#include <iostream>
using namespace std;

int main() {
    // \033[1;31m  -> Bright Red
    // \033[1;32m  -> Bright Green
    // \033[1;34m  -> Bright Blue
    // \033[0m     -> Reset color
    cout << "\033[1;31mHello\033[0m "
         << "\033[1;32mWorld\033[0m"
         << "\033[1;34m!\033[0m\n";
    return 0;
}

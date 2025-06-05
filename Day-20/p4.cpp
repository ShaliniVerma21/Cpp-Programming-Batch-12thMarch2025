//Example 4: Using lambda with thread

#include <iostream>
#include <thread>
int main() {
    std::thread t([](){ std::cout << "Lambda thread!\n"; });
    t.join();
    return 0;
}

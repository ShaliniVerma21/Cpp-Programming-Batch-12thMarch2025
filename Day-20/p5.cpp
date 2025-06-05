// Example 5: Thread with sleep

#include <iostream>
#include <thread>
#include <chrono>
void countdown() {
    for(int i = 5; i >= 1; --i) {
        std::cout << "Count: " << i << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
int main() {
    std::thread t(countdown);
    t.join();
    return 0;
}

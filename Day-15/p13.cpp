//4. Using std::lock_guard for Automatic Lock Management

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx; // Mutex for synchronizing access to shared resource
int counter = 0;

void incrementCounter() {
    for (int i = 0; i < 1000; ++i) {
        std::lock_guard<std::mutex> lock(mtx); // Automatically locks the mutex
        ++counter; // Increment the shared counter
    }
}

int main() {
    std::thread t1(incrementCounter);
    std::thread t2(incrementCounter);

    t1.join();
    t2.join();

    std::cout << "Final counter value: " << counter << std::endl;
    return 0;
}
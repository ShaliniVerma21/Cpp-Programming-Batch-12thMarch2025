//3. Using Mutex for Synchronization
   
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx; // Mutex for synchronizing access to shared resource
int counter = 0;

void incrementCounter() {
    for (int i = 0; i < 1000; ++i) {
        mtx.lock(); // Lock the mutex
        ++counter; // Increment the shared counter
        mtx.unlock(); // Unlock the mutex
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
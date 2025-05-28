//2. Multiple Threads

#include <iostream>
#include <thread>

void printNumbers(int id) {
    for (int i = 1; i <= 5; ++i) {
        std::cout << "Thread " << id << ": " << i << std::endl;
    }
}

int main() {
    std::thread t1(printNumbers, 1);
    std::thread t2(printNumbers, 2);

    t1.join(); // Wait for thread 1 to finish
    t2.join(); // Wait for thread 2 to finish

    std::cout << "Both threads have finished execution." << std::endl;
    return 0;
}
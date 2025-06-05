// Example 2: Thread with parameters

#include <iostream>
#include <thread>
void printNumber(int n) {
    std::cout << "Number: " << n << std::endl;
}
int main() {
    std::thread t(printNumber, 5);
    t.join();
    return 0;
}

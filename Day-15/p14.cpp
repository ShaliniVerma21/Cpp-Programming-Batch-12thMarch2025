//5. Detaching a Thread

#include <iostream>
#include <thread>
#include <chrono>

void printMessage() {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate work
    std::cout << "Hello from detached thread!" << std::endl;
}

int main() {
    std::thread t(printMessage);
    t.detach(); // Detach the thread to run independently

    std::cout << "Main thread continues running..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Wait for a moment

    std::cout << "Main thread finished execution." << std::endl;
    return 0;
}
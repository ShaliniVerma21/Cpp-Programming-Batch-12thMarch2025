/*
1. Multithreading
2. File Handling
3. streams
*/

/*
1. Multithreading in C++
Theory:
Multithreading is the ability of a program to run multiple threads (small units of a process) simultaneously. 
It helps in performing multiple tasks concurrently, like downloading a file while processing data.

Purpose:

1.To increase the efficiency and performance of applications.
2. To utilize CPU resources better.
3. To execute multiple tasks simultaneously.

Applications:

1.Game development (e.g., sound, graphics, user input in parallel)
2.Real-time simulations
3.Web servers handling multiple clients
4.Background processing (e.g., antivirus scan)
5.Parallel computations (e.g., matrix multiplication)

g++ --version

*/

// Example 1: Basic thread using function
#include <iostream>
#include <thread>

void display() {
    std::cout << "Hello from thread!\n";
}

int main() {
    std::thread t(display);  // Create a thread
    t.join();                // Wait for the thread to finish
    std::cout << "Main thread done!\n";
    return 0;
}


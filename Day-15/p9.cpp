//5. Handling Segmentation Faults

#include <iostream>
#include <csignal>
#include <cstdlib>

void signalHandler(int signum) {
    std::cout << "Segmentation fault (SIGSEGV) received. Exiting...\n";
    exit(signum);
}

int main() {
    // Register signal handler for segmentation fault
    signal(SIGSEGV, signalHandler);

    // Intentionally cause a segmentation fault
    int *p = nullptr;
    std::cout << "Causing segmentation fault...\n";
    *p = 42; // Dereferencing a null pointer

    return 0;
}
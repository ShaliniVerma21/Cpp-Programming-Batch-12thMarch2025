//3. Ignoring a Signal

#include <iostream>
#include <csignal>
#include <cstdlib>

void signalHandler(int signum) {
    std::cout << "SIGINT received but ignored.\n";
}

int main() {
    // Register signal handler
    signal(SIGINT, signalHandler);

    while (true) {
        std::cout << "Running... Press Ctrl+C to see the effect.\n";
        sleep(1);
    }

    return 0;
}
//2. Handling Multiple Signals

#include <iostream>
#include <csignal>
#include <cstdlib>

void signalHandler(int signum) {
    if (signum == SIGINT) {
        std::cout << "SIGINT received. Exiting gracefully...\n";
        exit(0);
    } else if (signum == SIGTERM) {
        std::cout << "SIGTERM received. Exiting gracefully...\n";
        exit(0);
    }
}

int main() {
    // Register signal handlers
    signal(SIGINT, signalHandler);
    signal(SIGTERM, signalHandler);

    while (true) {
        std::cout << "Running... Press Ctrl+C or send SIGTERM to stop.\n";
        sleep(1);
    }

    return 0;
}
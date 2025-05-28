//4. Using sigaction for More Control

#include <iostream>
#include <csignal>
#include <cstring>
#include <unistd.h>

void signalHandler(int signum) {
    std::cout << "Signal " << signum << " received.\n";
}

int main() {
    struct sigaction action;
    action.sa_handler = signalHandler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    // Register signal handler using sigaction
    sigaction(SIGINT, &action, nullptr);

    while (true) {
        std::cout << "Running... Press Ctrl+C to stop.\n";
        sleep(1);
    }

    return 0;
}
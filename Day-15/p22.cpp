//8. Signal Handling

#include <iostream>
#include <csignal>
#include <unistd.h>
using namespace std;

void signalHandler(int signum) {
    cout << "Signal " << signum << " received." << endl;
}

int main() {
    signal(SIGINT, signalHandler); // Register signal handler

    while (true) {
        cout << "Running... Press Ctrl+C to stop.\n";
        sleep(1);
    }
    return 0;
}
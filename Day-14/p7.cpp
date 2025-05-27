//Program 3: Thread with Loop and Delay (Simulating Work)

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void countNumbers() {
    for (int i = 1; i <= 5; i++) {
        cout << "Counting: " << i << endl;
        this_thread::sleep_for(chrono::seconds(1)); // 1-second delay
    }
}

int main() {
    thread t1(countNumbers);

    t1.join();

    cout << "Counting finished." << endl;

    return 0;
}

//2. Class Template for a Simple Pair

#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;

public:
    Pair(T1 a, T2 b) : first(a), second(b) {}

    void display() {
        cout << "First: " << first << ", Second: " << second << endl;
    }
};

int main() {
    Pair<int, double> p1(1, 2.5);
    p1.display();

    Pair<string, int> p2("Age", 30);
    p2.display();

    return 0;
}
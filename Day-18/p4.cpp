//Program 2: Remove and reverse list

#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> numbers = {10, 20, 30, 40};

    // Remove element
    numbers.remove(20);

    // Reverse list
    numbers.reverse();

    // Display list
    cout << "Modified list: ";
    for(int n : numbers)
        cout << n << " ";
    return 0;
}

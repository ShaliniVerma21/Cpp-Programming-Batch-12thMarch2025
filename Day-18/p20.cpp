// Program 2: Iterator with set

#include <iostream>
#include <set>
using namespace std;

int main() {
    set<string> fruits = {"Apple", "Banana", "Cherry"};

    // Iterator for set
    set<string>::iterator it;

    // Traverse using iterator
    for(it = fruits.begin(); it != fruits.end(); ++it)
        cout << *it << " ";
    return 0;
}

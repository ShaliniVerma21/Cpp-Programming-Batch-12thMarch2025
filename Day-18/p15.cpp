/*
H. Map and Multimap
--------------------
➤ Real-World Use:
+ A map is a data structure that stores key-value pairs. It is used to store data
Map: Dictionary (Word → Meaning)
Multimap: Names with multiple phone numbers
*/

//Program 1: Map – Key-value pair

#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> marks;

    marks["John"] = 90;
    marks["Alice"] = 85;

    cout << "Alice's marks: " << marks["Alice"] << endl;
    return 0;
}

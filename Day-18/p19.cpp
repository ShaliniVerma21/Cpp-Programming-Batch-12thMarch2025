/*
3. Iterators
🔹 Definition:
Iterators are pointers-like objects used to access and navigate through container elements.
They are used to traverse the elements of a container, such as a list or a set.

🔹 Purpose:
To traverse STL containers easily and uniformly without knowing their internal structure.


🔹 Real-World Examples:
- A file pointer in C, which points to the current position in a file.
- A cursor in a text editor, which points to the current position in the text.
- Going through books on a shelf
- Scanning emails in your inbox
*/

// Program 1: Using iterator with a vector
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {10, 20, 30};

    // Declare iterator
    vector<int>::iterator it;

    // Traverse vector using iterator
    for(it = nums.begin(); it != nums.end(); ++it)
        cout << *it << " ";
    return 0;
}


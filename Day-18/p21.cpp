/*
4. Functors (Function Objects)
================================
🔹 Definition:
Functors are objects that behave like functions. They overload the () operator.


🔹 Purpose:
To pass logic (like comparison) as an object to STL algorithms like sort, for_each.


🔹 Real-World Examples:
- Comparing two objects using a custom comparison function.
- Sorting a collection of objects using a custom sorting function.
- Custom sorting rule (e.g., descending)
- Conditional filtering (e.g., only even numbers)
*/

//Program 1: Simple functor to multiply numbers
#include <iostream>
using namespace std;

// Define a functor class
class Multiply {
public:
    void operator()(int a, int b) {
        cout << "Product: " << a * b << endl;
    }
};

int main() {
    Multiply m;
    m(4, 5);  // Calls functor
    return 0;
}

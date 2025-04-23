//Real-World Example: A Book class with constructors.

#include <iostream>
using namespace std;

class Book {
public:
    string title;
    Book(string t) : title(t) {} // Constructor
    Book(const Book &b) : title(b.title) { // Copy constructor
        cout << "Copy constructor called!" << endl;
    }
};

int main() {
    Book book1("C++ Programming");
    Book book2 = book1; // Calls copy constructor
    cout << "Book title: " << book2.title << endl;
    return 0;
}
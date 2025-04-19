//5. Book Class

#include <iostream>
using namespace std;

class Book {
private:
    string title;
    string author;
    int pages;

public:
    Book(string t, string a, int p) {
        title = t;
        author = a;
        pages = p;
    }

    void displayInfo() {
        cout << "Title: " << title << ", Author: " << author << ", Pages: " << pages << endl;
    }
};

int main() {
    Book book1("1984", "George Orwell", 328);
    book1.displayInfo();
    return 0;
}
//Problem 8: Library Book Tracker

#include <iostream>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    int year;
};

void displayBooks(Book books[], int count) {
    cout << "Title\t\tAuthor\t\tYear\n";
    for (int i = 0; i < count; i++) {
        cout << books[i].title << "\t\t" << books[i].author << "\t\t" << books[i].year << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of books: ";
    cin >> n;
    Book books[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter book title, author, and year: ";
        cin >> books[i].title >> books[i].author >> books[i].year;
    }
    displayBooks(books, n);
    return 0;
}
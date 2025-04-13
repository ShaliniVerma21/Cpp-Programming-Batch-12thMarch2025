//2. Library Management System

#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    string title;
    string author;
    bool isAvailable;

    Book(string t, string a) : title(t), author(a), isAvailable(true) {}
};

class Library {
private:
    Book* books;
    int capacity;
    int size;

public:
    Library(int c) : capacity(c), size(0) {
        books = new Book[capacity];
    }

    ~Library() {
        delete[] books;
    }

    void addBook(const string& title, const string& author) {
        if (size < capacity) {
            books[size++] = Book(title, author);
            cout << "Book added successfully!" << endl;
        } else {
            cout << "Library is full." << endl;
        }
    }

    void displayBooks() {
        for (int i = 0; i < size; i++) {
            cout << "Title: " << books[i].title << ", Author: " << books[i].author << ", Available: " << (books[i].isAvailable ? "Yes" : "No") << endl;
        }
    }
};

int main() {
    Library library(10);
    library.addBook("1984", "George Orwell");
    library.addBook("To Kill a Mockingbird", "Harper Lee");
    library.displayBooks();
    return 0;
}
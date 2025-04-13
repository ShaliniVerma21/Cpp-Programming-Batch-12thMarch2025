//9. string array to manage a library's book collection

#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    string title;
    string author;
    bool isAvailable;

    Book(string t, string a) : title(t), author(a), isAvailable(true) {}

    void displayBookInfo() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Availability: " << (isAvailable ? "Available" : "Not Available") << endl;
    }
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
            books[size] = Book(title, author);
            size++;
            cout << "Book added successfully!" << endl;
        } else {
            cout << "Library is full. Cannot add more books." << endl;
        }
    }

    void removeBook(const string& title) {
        for (int i = 0; i < size; i++) {
            if (books[i].title == title) {
                for (int j = i; j < size - 1; j++) {
                    books[j] = books[j + 1];
                }
                size--;
                cout << "Book removed successfully!" << endl;
                return;
            }
        }
        cout << "Book not found in the library." << endl;
    }

    void displayAllBooks() {
        for (int i = 0; i < size; i++) {
            books[i].displayBookInfo();
            cout << endl;
        }
    }

    void searchBook(const string& title) {
        for (int i = 0; i < size; i++) {
            if (books[i].title == title) {
                books[i].displayBookInfo();
                return;
            }
        }
        cout << "Book not found in the library." << endl;
    }

    void borrowBook(const string& title) {
        for (int i = 0; i < size; i++) {
            if (books[i].title == title) {
                if (books[i].isAvailable) {
                    books[i].isAvailable = false;
                    cout << "Book borrowed successfully!" << endl;
                } else {
                    cout << "Book is not available. It's already borrowed." << endl;
                }
                return;
            }
        }
        cout << "Book not found in the library." << endl;
    }

    void returnBook(const string& title) {
        for (int i = 0; i < size; i++) {
            if (books[i].title == title) {
                if (!books[i].isAvailable) {
                    books[i].isAvailable = true;
                    cout << "Book returned successfully!" << endl;
                } else {
                    cout << "Book is already available in the library." << endl;
                }
                return;
            }
        }
        cout << "Book not found in the library." << endl;
    }
};

int main() {
    Library library(10);

    while (true) {
        cout << "1. Add Book" << endl;
        cout << "2. Remove Book" << endl;
        cout << "3. Display All Books" << endl;
        cout << "4. Search Book" << endl;
        cout << "5. Borrow Book" << endl;
        cout << "6. Return Book" << endl;
        cout << "7. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string title, author;
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                library.addBook(title, author);
                break;
            }
            case 2: {
                string title;
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                library.removeBook(title);
                break;
            }
            case 3:
                library.displayAllBooks();
                break;
            case 4: {
                string title;
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                library.searchBook(title);
                break;
            }
            case 5: {
                string title;
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                library.borrowBook(title);
                break;
            }
            case 6: {
                string title;
                cout << " Enter book title: ";
                cin.ignore();
                getline(cin, title);
                library.returnBook(title);
                break;
            }
            case 7:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
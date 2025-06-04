//20.Library Book Record

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stdexcept>
using namespace std;

// ================= ABSTRACT BASE CLASS =================
class LibraryInterface {
public:
    virtual void addBook() = 0;
    virtual void viewBooks() = 0;
    virtual void updateBook() = 0;
    virtual void deleteBook() = 0;
    virtual ~LibraryInterface() {}
};

// ================= BOOK CLASS (ENCAPSULATION) =================
class Book {
private:
    int bookID;
    string title;
    string author;
    string genre;

public:
    Book() {}
    Book(int id, string t, string a, string g) : bookID(id), title(t), author(a), genre(g) {}

    int getBookID() const { return bookID; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getGenre() const { return genre; }

    void setTitle(string t) { title = t; }
    void setAuthor(string a) { author = a; }
    void setGenre(string g) { genre = g; }

    void display() const {
        cout << "\n📘 Book ID: " << bookID
             << "\n📖 Title: " << title
             << "\n✍ Author: " << author
             << "\n🎯 Genre: " << genre << "\n";
    }
};

// ================= LIBRARY CLASS (INHERITANCE, POLYMORPHISM) =================
class Library : public LibraryInterface {
private:
    map<int, Book> bookRecords; // bookID => Book

public:
    // Constructor
    Library() {
        cout << "\n📚 Welcome to the Indian Library Record System 📚\n";
    }

    // Function to add a new book
    void addBook() override {
        int id;
        string title, author, genre;

        cout << "\nEnter Book ID: ";
        cin >> id;
        cin.ignore();

        if (bookRecords.find(id) != bookRecords.end()) {
            cout << "❌ Book ID already exists.\n";
            return;
        }

        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Author Name: ";
        getline(cin, author);
        cout << "Enter Genre: ";
        getline(cin, genre);

        Book b(id, title, author, genre);
        bookRecords[id] = b;
        cout << "✅ Book added successfully!\n";
    }

    // Function to view all books
    void viewBooks() override {
        if (bookRecords.empty()) {
            cout << "\n⚠ No books found in the library.\n";
            return;
        }

        cout << "\n======📚 List of Books in Library ======\n";
        for (auto& entry : bookRecords) {
            entry.second.display();
        }
    }

    // Function to update a book
    void updateBook() override {
        int id;
        cout << "\nEnter Book ID to update: ";
        cin >> id;
        cin.ignore();

        auto it = bookRecords.find(id);
        if (it == bookRecords.end()) {
            cout << "❌ Book not found.\n";
            return;
        }

        string title, author, genre;
        cout << "Enter New Title: ";
        getline(cin, title);
        cout << "Enter New Author: ";
        getline(cin, author);
        cout << "Enter New Genre: ";
        getline(cin, genre);

        it->second.setTitle(title);
        it->second.setAuthor(author);
        it->second.setGenre(genre);

        cout << "✅ Book updated successfully.\n";
    }

    // Function to delete a book
    void deleteBook() override {
        int id;
        cout << "\nEnter Book ID to delete: ";
        cin >> id;
        cin.ignore();

        if (bookRecords.erase(id)) {
            cout << "✅ Book deleted successfully.\n";
        } else {
            cout << "❌ Book ID not found.\n";
        }
    }
};

// ================= MENU FUNCTION =================
void showMenu() {
    cout << "\n\n========== Indian Library Menu ==========\n";
    cout << "1. Add Book Record\n";
    cout << "2. View All Books\n";
    cout << "3. Update Book\n";
    cout << "4. Delete Book\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

// ================= MAIN FUNCTION =================
int main() {
    Library myLibrary;
    int choice;

    do {
        try {
            showMenu();
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1: myLibrary.addBook(); break;
                case 2: myLibrary.viewBooks(); break;
                case 3: myLibrary.updateBook(); break;
                case 4: myLibrary.deleteBook(); break;
                case 5: cout << "\n👋 Thank you for using the Indian Library System.\n"; break;
                default: throw invalid_argument("❌ Invalid choice. Please enter 1-5.");
            }
        } catch (const exception& e) {
            cout << "\n[Error] " << e.what() << "\n";
        }

    } while (choice != 5);

    return 0;
}

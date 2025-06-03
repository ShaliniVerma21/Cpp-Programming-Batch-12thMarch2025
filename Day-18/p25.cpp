//Online Library System

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

// Functor to check if a book title starts with a given prefix
class StartsWith {
    string prefix;
public:
    StartsWith(string p) : prefix(p) {}
    bool operator()(const string &book) {
        return book.find(prefix) == 0;
    }
};

// Library class implementing CRUD and logic
class Library {
private:
    set<string> books; // Container to store unique book titles

public:
    // Add a book (Create)
    void addBook(const string& book) {
        auto result = books.insert(book);
        if (result.second)
            cout << "✅ Book added successfully.\n";
        else
            cout << "⚠️ Book already exists.\n";
    }

    // Display all books (Read)
    void displayBooks() {
        if (books.empty()) {
            cout << "📚 No books in the library.\n";
            return;
        }
        cout << "\n📖 Books in Library:\n";
        for (const auto& b : books)
            cout << " - " << b << "\n";
    }

    // Update a book title (Update)
    void updateBook(const string& oldTitle, const string& newTitle) {
        auto it = books.find(oldTitle);
        if (it != books.end()) {
            books.erase(it);
            books.insert(newTitle);
            cout << "✅ Book updated successfully.\n";
        } else {
            cout << "❌ Book not found.\n";
        }
    }

    // Delete a book (Delete)
    void deleteBook(const string& title) {
        if (books.erase(title))
            cout << "🗑️ Book deleted successfully.\n";
        else
            cout << "❌ Book not found.\n";
    }

    // Search books by prefix
    void searchByPrefix(const string& prefix) {
        cout << "\n🔍 Books starting with '" << prefix << "':\n";
        bool found = false;
        for_each(books.begin(), books.end(), [&](string b) {
            if (StartsWith(prefix)(b)) {
                cout << " - " << b << "\n";
                found = true;
            }
        });
        if (!found)
            cout << "No matching books found.\n";
    }
};

// Main function with control logic and loops
int main() {
    Library lib;
    int choice;
    string book, newBook;

    do {
        cout << "\n==============================\n";
        cout << "📚 ONLINE LIBRARY SYSTEM MENU\n";
        cout << "==============================\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Update Book\n";
        cout << "4. Delete Book\n";
        cout << "5. Search Books by Prefix\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;
        cin.ignore(); // Clear newline

        switch (choice) {
            case 1:
                cout << "Enter book name to add: ";
                getline(cin, book);
                lib.addBook(book);
                break;

            case 2:
                lib.displayBooks();
                break;

            case 3:
                cout << "Enter existing book name: ";
                getline(cin, book);
                cout << "Enter new book name: ";
                getline(cin, newBook);
                lib.updateBook(book, newBook);
                break;

            case 4:
                cout << "Enter book name to delete: ";
                getline(cin, book);
                lib.deleteBook(book);
                break;

            case 5:
                cout << "Enter prefix to search: ";
                getline(cin, book);
                lib.searchByPrefix(book);
                break;

            case 6:
                cout << "👋 Exiting Library System. Goodbye!\n";
                break;

            default:
                cout << "⚠️ Invalid choice! Please select 1-6.\n";
        }

    } while (choice != 6);

    return 0;
}

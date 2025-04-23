//Library Fine Calculator

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Enumeration for book types
enum class BookType {
    REGULAR,
    REFERENCE,
    TEXTBOOK
};

// Structure for a book
struct Book {
    string title; // Title of the book
    BookType type; // Type of the book
    int daysOverdue; // Number of days the book is overdue

    // Constructor for Book
    Book(string t, BookType bt, int overdueDays) 
        : title(t), type(bt), daysOverdue(overdueDays) {}

    // Function to calculate fine based on book type and overdue days
    double calculateFine() const {
        double finePerDay = 0.0;
        switch (type) {
            case BookType::REGULAR: finePerDay = 0.50; break; // $0.50 per day for regular books
            case BookType::REFERENCE: finePerDay = 1.00; break; // $1.00 per day for reference books
            case BookType::TEXTBOOK: finePerDay = 0.75; break; // $0.75 per day for textbooks
        }
        return finePerDay * daysOverdue; // Total fine
    }
};

// Base class for Library
class Library {
protected:
    vector<Book> books; // List of books in the library

public:
    // Function to add a book to the library
    void addBook(const Book& book) {
        books.push_back(book);
    }

    // Function to display all books and their fines
    void displayFines() const {
        cout << "Library Fine Calculator:\n";
        for (const auto& book : books) {
            cout << "Title: " << book.title 
                 << ", Type: " << getBookTypeString(book.type) 
                 << ", Days Overdue: " << book.daysOverdue 
                 << ", Fine: $" << fixed << setprecision(2) 
                 << book.calculateFine() << endl;
        }
    }

    // Function to get string representation of book type
    string getBookTypeString(BookType type) const {
        switch (type) {
            case BookType::REGULAR: return "Regular";
            case BookType::REFERENCE: return "Reference";
            case BookType::TEXTBOOK: return "Textbook";
            default: return "Unknown";
        }
    }

    // Virtual destructor
    virtual ~Library() {}
};

// Derived class for ExtendedLibrary
class ExtendedLibrary : public Library {
public:
    // Function to display total fines for all books
    void displayTotalFines() const {
        double totalFines = 0.0;
        for (const auto& book : books) {
            totalFines += book.calculateFine();
        }
        cout << "Total Fines for All Books: $" << fixed << setprecision(2) << totalFines << endl;
    }
};

int main() {
    // Create an instance of ExtendedLibrary
    ExtendedLibrary myLibrary;

    // Add books to the library
    myLibrary.addBook(Book("The Great Gatsby", BookType::REGULAR, 5)); // 5 days overdue
    myLibrary.addBook(Book("C++ Programming", BookType::TEXTBOOK, 3)); // 3 days overdue
    myLibrary.addBook(Book("Encyclopedia", BookType::REFERENCE, 7)); // 7 days overdue

    // Display fines for all books
    myLibrary.displayFines();
    cout << endl;

    // Display total fines for all books
    myLibrary.displayTotalFines();

    return 0;
}
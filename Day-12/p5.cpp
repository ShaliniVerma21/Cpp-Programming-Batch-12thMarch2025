//Library Membership System

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm> // For std::sort

using namespace std;

// Enumeration for membership types
enum class MembershipType {
    REGULAR,
    PREMIUM,
    STUDENT
};

// Structure for a book
struct Book {
    string title; // Title of the book
    string author; // Author of the book
    bool isAvailable; // Availability status of the book

    // Constructor for Book
    Book(string t, string a) : title(t), author(a), isAvailable(true) {}
};

// Structure for a library member
struct Member {
    string name; // Name of the member
    MembershipType membershipType; // Type of membership
    vector<Book> borrowedBooks; // List of borrowed books

    // Constructor for Member
    Member(string n, MembershipType mt) : name(n), membershipType(mt) {}

    // Function to borrow a book
    bool borrowBook(Book& book) {
        if (book.isAvailable) {
            borrowedBooks.push_back(book);
            book.isAvailable = false; // Mark the book as borrowed
            return true;
        }
        return false; // Book is not available
    }

    // Function to return a book
    bool returnBook(Book& book) {
        auto it = find_if(borrowedBooks.begin(), borrowedBooks.end(), [&](const Book& b) {
            return b.title == book.title;
        });
        if (it != borrowedBooks.end()) {
            borrowedBooks.erase(it); // Remove the book from borrowed list
            book.isAvailable = true; // Mark the book as available
            return true;
        }
        return false; // Book was not borrowed by this member
    }
};

// Base class for Library
class Library {
protected:
    vector<Book> books; // List of books in the library
    vector<Member> members; // List of members in the library

public:
    // Function to add a book to the library
    void addBook(const Book& book) {
        books.push_back(book);
    }

    // Function to add a member to the library
    void addMember(const Member& member) {
        members.push_back(member);
    }

    // Function to display all books
    void displayBooks() const {
        cout << "Books in Library:\n";
        for (const auto& book : books) {
            cout << "- " << book.title << " by " << book.author
                 << (book.isAvailable ? " (Available)" : " (Borrowed)") << endl;
        }
    }

    // Function to display all members
    void displayMembers() const {
        cout << "Library Members:\n";
        for (const auto& member : members) {
            cout << "- " << member.name << " (Membership Type: "
                 << getMembershipTypeString(member.membershipType) << ")\n";
        }
    }

    // Function to get string representation of membership type
    string getMembershipTypeString(MembershipType type) const {
        switch (type) {
            case MembershipType::REGULAR: return "Regular";
            case MembershipType::PREMIUM: return "Premium";
            case MembershipType::STUDENT: return "Student";
            default: return "Unknown";
        }
    }

    // Virtual destructor
    virtual ~Library() {}
};

// Derived class for ExtendedLibrary
class ExtendedLibrary : public Library {
public:
    // Function to display borrowed books for each member
    void displayBorrowedBooks() const {
        cout << "Borrowed Books:\n";
        for (const auto& member : members) {
            cout << member.name << " has borrowed:\n";
            for (const auto& book : member.borrowedBooks) {
                cout << "- " << book.title << endl;
            }
        }
    }
};

int main() {
    // Create an instance of ExtendedLibrary
    ExtendedLibrary myLibrary;

    // Add books to the library
    myLibrary.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald"));
    myLibrary.addBook(Book("1984", "George Orwell"));
    myLibrary.addBook(Book("To Kill a Mockingbird", "Harper Lee"));

    // Add members to the library
    myLibrary.addMember(Member("Alice", MembershipType::REGULAR));
    myLibrary.addMember(Member("Bob", MembershipType::PREMIUM));
    myLibrary.addMember(Member("Charlie", MembershipType::STUDENT));

    // Display all books and members
    myLibrary.displayBooks();
    cout << endl;
    myLibrary.displayMembers();
    cout << endl;

    // Borrowing books
    myLibrary.members[0].borrowBook (myLibrary.books[0]); // Alice borrows "The Great Gatsby"
    myLibrary.members[1].borrowBook(myLibrary.books[1]); // Bob borrows "1984"

    // Display borrowed books
    myLibrary.displayBorrowedBooks();
    cout << endl;

    // Returning books
    myLibrary.members[0].returnBook(myLibrary.books[0]); // Alice returns "The Great Gatsby"
    myLibrary.members[1].returnBook(myLibrary.books[1]); // Bob returns "1984"

    // Display all books after returning
    myLibrary.displayBooks();

    return 0;
}

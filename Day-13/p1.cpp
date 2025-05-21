/*
Topics : 
1. Polymorphysm, 

--> Polymorphism allows methods to be used in different ways based on the object type.
--> Compile-time polymorphism is achieved through function and operator overloading.
--> Run-time polymorphism is achieved through inheritance and virtual functions.
It enhances code flexibility, reusability, and maintainability.


2. Virtual Functions,

--> Virtual functions allow for dynamic binding and polymorphism in C++.
--> They are declared with the virtual keyword in the base class.
--> Pure virtual functions make a class abstract and require derived classes to implement them.
--> Always use a virtual destructor in base classes to ensure proper cleanup of derived class objects.

3. Abstractions , 

--> Abstraction in C++ allows you to hide complex implementation details and expose only the necessary features.
--> It is achieved through abstract classes and pure virtual functions.
--> Abstraction simplifies code, enhances reusability, and improves maintainability.

4. Encapsulation, 
5. Multithreading , 
6. Shallow copy & Deep copy
7. Templates
8. Signal Handling
9. Exception handling
10. Assignment-3
*/

//Oops (C++ Library Management System)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Base class: Person
class Person {
protected:
    string name;
    int age;

public:
    // Constructor
    Person(string n, int a) : name(n), age(a) {}

    // Method to display person details
    void displayInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Derived class: Member
class Member : public Person {
private:
    int memberId;

public:
    // Constructor
    Member(string n, int a, int id) : Person(n, a), memberId(id) {}

    // Method to display member details
    void displayMemberInfo() {
        displayInfo();
        cout << "Member ID: " << memberId << endl;
    }
};

// Class: Book
class Book {
private:
    string title;
    string author;
    bool isAvailable;

public:
    // Constructor
    Book(string t, string a) : title(t), author(a), isAvailable(true) {}

    // Method to display book details
    void displayBookInfo() {
        cout << "Title: " << title << ", Author: " << author;
        cout << (isAvailable ? " (Available)" : " (Checked Out)") << endl;
    }

    // Method to check out the book
    void checkOut() {
        if (isAvailable) {
            isAvailable = false;
            cout << "You have checked out \"" << title << "\"." << endl;
        } else {
            cout << "Sorry, \"" << title << "\" is currently checked out." << endl;
        }
    }

    // Method to return the book
    void returnBook() {
        isAvailable = true;
        cout << "You have returned \"" << title << "\"." << endl;
    }
};

// Class: Library
class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:
    // Method to add a book to the library
    void addBook(const Book& book) {
        books.push_back(book);
    }

    // Method to add a member to the library
    void addMember(const Member& member) {
        members.push_back(member);
    }

    // Method to display all books
    void displayBooks() {
        cout << "Books in the Library:" << endl;
        for (const auto& book : books) {
            book.displayBookInfo();
        }
    }

    // Method to display all members
    void displayMembers() {
        cout << "Library Members:" << endl;
        for (const auto& member : members) {
            member.displayMemberInfo();
        }
    }
};

int main() {
    // Create a library
    Library library;

    // Add books to the library
    library.addBook(Book("1984", "George Orwell"));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee"));

    // Add members to the library
    library.addMember(Member("Alice", 30, 1));
    library.addMember(Member("Bob", 25, 2));

    // Display books and members
    library.displayBooks();
    library.displayMembers();

    // Check out a book
    library.books[0].checkOut(); // Check out "1984"
    library.books[0].checkOut(); // Try to check out "1984" again

    // Return the book
    library.books[0].returnBook();

    return 0;
}
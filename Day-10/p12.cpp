//1. Library Management System
#include <iostream>
#include <vector>
#include <string>

class Book {
public:
    std::string title;
    std::string author;
    bool isAvailable;

    Book(std::string t, std::string a) : title(t), author(a), isAvailable(true) {}
};

class Member {
public:
    std::string name;
    int memberId;

    Member(std::string n, int id) : name(n), memberId(id) {}
};

class Library {
private:
    std::vector<Book> books;
    std::vector<Member> members;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void addMember(const Member& member) {
        members.push_back(member);
    }

    void searchBook(const std::string& title) {
        for (const auto& book : books) {
            if (book.title == title) {
                std::cout << "Book found: " << book.title << " by " << book.author << "\n";
                return;
            }
        }
        std::cout << "Book not found.\n";
    }
};
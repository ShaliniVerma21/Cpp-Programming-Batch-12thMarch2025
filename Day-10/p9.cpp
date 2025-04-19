//9. Library Class

#include <iostream>
#include <vector>
using namespace std;

class Library {
private:
    vector<string> books;

public:
    void addBook(string book) {
        books.push_back(book);
        cout << "Added: " << book << endl;
    }

    void displayBooks() {
        cout << "Books in Library: " << endl;
        for (const auto& book : books) {
            cout << book << endl;
        }
    }
};

int main() {
    Library myLibrary;
    myLibrary.addBook("The Great Gatsby");
    myLibrary.addBook("To Kill a Mockingbird");
    myLibrary.displayBooks();
    return 0;
}
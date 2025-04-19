//7. Dog Class

#include <iostream>
using namespace std;

class Dog {
private:
    string name;
    string breed;

public:
    Dog(string n, string b) {
        name = n;
        breed = b;
    }

    void bark() {
        cout << name << " says Woof!" << endl;
    }

    void displayInfo() {
        cout << "Dog Name: " << name << ", Breed: " << breed << endl;
    }
};

int main() {
    Dog myDog("Buddy", "Golden Retriever");
    myDog.displayInfo();
    myDog.bark();
    return 0;
}
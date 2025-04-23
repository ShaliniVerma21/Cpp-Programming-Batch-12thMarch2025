/*
 Destructor -->
A destructor is a special member function that is called when an object goes out of scope or is explicitly 
deleted.While constructors are used to initialize objects, destructors are used to clean up when an object 
goes out of scope. A destructor has the same name as the class but is prefixed with a tilde (~).

Syntax:

class ClassName {
public:
    ~ClassName(); // Destructor
};
*/

class MyClass {
    public:
        MyClass() {
            std::cout << "Constructor called!" << std::endl;
        }
    
        ~MyClass() { // Destructor
            std::cout << "Destructor called!" << std::endl;
        }
    };
    
    int main() {
        MyClass obj; // Constructor is called
        // Destructor will be called automatically when obj goes out of scope
        return 0;
    }
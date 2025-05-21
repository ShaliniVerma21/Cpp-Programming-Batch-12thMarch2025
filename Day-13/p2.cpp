/*
Polymorphysm : 

Polymorphism is a core concept in object-oriented programming (OOP) that allows methods to do different 
things based on the object it is acting upon. In C++, polymorphism enables a single interface to represent 
different underlying forms (data types).

Types of Polymorphism -->

1. Compile-time Polymorphism (Static Binding)

   --> Achieved through function overloading and operator overloading.
   --> The method to be invoked is determined at compile time.

2. Run-time Polymorphism (Dynamic Binding)

  --> Achieved through inheritance and virtual functions.
  --> The method to be invoked is determined at runtime.


Purpose of Polymorphism -->

1. Code Reusability: Write code that can work with different data types.
2. Flexibility and Maintainability: Easier to extend and maintain code.
3. Dynamic Method Resolution: Allows for dynamic behavior in programs.

*/

//Function Overloading Example:

#include <iostream>
using namespace std;

class Print {
public:
    void show(int i) {
        cout << "Integer: " << i << endl;
    }
    
    void show(double d) {
        cout << "Double: " << d << endl;
    }
    
    void show(string s) {
        cout << "String: " << s << endl;
    }
};

int main() {
    Print obj;
    obj.show(5);          // Calls show(int)
    obj.show(5.5);        // Calls show(double)
    obj.show("Hello");    // Calls show(string)
    return 0;
}
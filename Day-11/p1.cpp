
/*
Topics :
1. Structures (struct)
2. Enumerations (enum)
3. Scoped Enumerations (enum class)
4. Classes, Object & Functions
5. Constructors,Copy Constructor
6. Destructor
7. This & Static Keywords
8. Math Functions
9. Inheritance
10. Access Specifiers
*/

/*
Structures (struct) :

A struct in C++ is a user-defined data type that allows you to group variables of different types under a 
single name. It is similar to a class, but by default, all members of a struct are public.

Syntax:

struct StructName {
    dataType member1;
    dataType member2;
    // ...
};
*/

#include <iostream>
#include <string>

struct Person {
    std::string name;
    int age;
    float height;
};

int main() {
    Person person1;
    person1.name = "Alice";
    person1.age = 30;
    person1.height = 5.5;

    std::cout << "Name: " << person1.name << ", Age: " << person1.age << ", Height: " 
    << person1.height << std::endl;

    return 0;
}
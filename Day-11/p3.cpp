
/*
Enumerations (enum):

An enum in C++ is a user-defined type that consists of a set of named integral constants. 
It is used to define variables that can hold a set of predefined values, making the code more 
readable and maintainable.

Syntax:

enum EnumName {
    Value1,
    Value2,
    // ...
};
*/

#include <iostream>

enum Color {
    RED,
    GREEN,
    BLUE
};

int main() {
    Color myColor = GREEN;

    if (myColor == GREEN) {
        std::cout << "The color is green." << std::endl;
    }

    return 0;
}

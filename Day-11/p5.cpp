/*
Advanced Usage -->

Scoped Enumerations (enum class):

C++11 introduced scoped enumerations, which provide better type safety and avoid name clashes.

Syntax:

enum class EnumName {
    Value1,
    Value2,
    // ...
};
*/

#include <iostream>

enum class Direction {
    NORTH,
    SOUTH,
    EAST,
    WEST
};

int main() {
    Direction dir = Direction::NORTH;

    if (dir == Direction::NORTH) {
        std::cout << "Heading North!" << std::endl;
    }

    return 0;
}

/*
Structures (struct): Used to group different types of data together.
Enumerations (enum): Used to define a variable that can take one of a limited set of values.
Scoped Enumerations (enum class): Provide better type safety and avoid naming conflicts.
*/
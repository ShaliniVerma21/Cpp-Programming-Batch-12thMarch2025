//Example 1: Basic Scoped Enumeration

#include <iostream>

// Define a scoped enumeration for colors
enum class Color {
    Red,    // Represents the color red
    Green,  // Represents the color green
    Blue    // Represents the color blue
};

int main() {
    // Create a variable of type Color
    Color myColor = Color::Green;

    // Check the value of myColor
    if (myColor == Color::Green) {
        std::cout << "The color is green!" << std::endl;
    }

    return 0;
}

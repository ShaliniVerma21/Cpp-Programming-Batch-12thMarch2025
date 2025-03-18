 //Program Using Escape Sequences
 #include <iostream>

int main() {
    std::cout << "Escape Sequences in C++:\n"; // New line after the title

    std::cout << "1. Backslash: \\    \n"; // Display a backslash
    std::cout << "2. Single Quote: \'   \n"; // Display a single quote
    std::cout << "3. Double Quote: \"    \n"; // Display a double quote
    std::cout << "4. New Line: First Line.\nSecond Line.\n"; // New line
    std::cout << "5. Tab: Column1\tColumn2\n"; // Horizontal tab
    std::cout << "6. Carriage Return: Hello, World!\rGoodbye!\n"; // Carriage return
    std::cout << "7. Backspace: Hello\b World!\n"; // Backspace
    std::cout << "8. Form Feed: Hello\fWorld!\n"; // Form feed (may not be visible in all consoles)
    std::cout << "9. Vertical Tab: Hello\vWorld!\n"; // Vertical tab (may not be visible in all consoles)
    std::cout << "10. Null Character: Hello\0World!\n"; // Null character (terminates the string)

    return 0; // Indicate successful completion
}
/*
Static Local Variables:
1. Static local variables retain their value between function calls. 
2. They are initialized only once and exist for the lifetime of the program.
*/

#include <iostream>

void counterFunction() {
    static int count = 0; // Static local variable
    count++;
    std::cout << "Count: " << count << std::endl;
}

int main() {
    counterFunction(); // Output: Count: 1
    counterFunction(); // Output: Count: 2
    counterFunction(); // Output: Count: 3
    return 0;
}
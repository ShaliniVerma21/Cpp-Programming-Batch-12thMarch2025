#include <iostream>  
#include <string>  // Include string library for std::string  
int main() {  
    // (a) Updating C-Style String  
    char cstr[] = "Hello";  // C-style string (character array)  
    cstr[0] = 'M';          // Modifying the first character  
    std::cout << "Updated C-Style String: " << cstr << std::endl;   
    // (b) Updating std::string  
    std::string str = "Hello"; // Declare a std::string variable  
    // Using index operator []  
    str[0] = 'M';   
    std::cout << "After modifying using []: " << str << std::endl;   
    // Using .at() method (safe version of indexing)  
    str.at(1) = 'a';   
    std::cout << "After modifying using at(): " << str << std::endl;   
    return 0;  
}  
#include <iostream>  
#include <string>  // Include the string library  
int main() {  
    // Initialize a string  
    std::string str = "Hello World";  
    // Using .replace() to replace "World" with "C++"  
    str.replace(6, 5, "C++");   
    std::cout << "After replace(): " << str << std::endl;   
    return 0;  
}  
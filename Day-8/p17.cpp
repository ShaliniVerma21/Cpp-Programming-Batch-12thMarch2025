#include <iostream>  
#include <string>  // Include the string library  
int main() {  
    // Initialize a string  
    std::string str = "Hello";  
    // Using .append() to add a word at the end  
    str.append(" World");   
    std::cout << "After append(): " << str << std::endl;   
    // Using += operator to add more text  
    str += "!!!";    
    std::cout << "After += operator: " << str << std::endl;   
    return 0;  
}  
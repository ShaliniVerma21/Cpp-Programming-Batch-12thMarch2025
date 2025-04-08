#include <iostream>  
#include <string>  
int main() {  
    // Accessing C-Style Strings  
    char cstr[] = "Hello";  
    char *ptr = cstr;  
    std::cout << "C-Style String Access:\n";  
    std::cout << "Using array indexing: " << cstr[0] << "\n"; // Output: H  
    std::cout << "Using pointer: " << *ptr << "\n";          // Output: H  
    std::cout << "Using pointer arithmetic: " << *(cstr + 1) << "\n"; // Output: e  
    std::cout << "Using loop traversal: ";  
    for (int i = 0; cstr[i] != '\0'; i++) {  
        std::cout << cstr[i];  
    }  
    std::cout << "\n";  

    
    // Accessing std::string  
    std::string str = "Hello";  
    std::cout << "\nstd::string Access:\n";  
    std::cout << "Using [] operator: " << str[1] << "\n";    // Output: e  
    std::cout << "Using .at(): " << str.at(2) << "\n";      // Output: l  
    std::cout << "Using .front(): " << str.front() << "\n";  // Output: H  
    std::cout << "Using .back(): " << str.back() << "\n";    // Output: o  
    std::cout << "Using iterators: ";  
    for (std::string::iterator it = str.begin(); it != str.end(); ++it) {  
        std::cout << *it;  
    }  
    std::cout << "\n";  
    std::cout << "Using range-based for loop: ";  
    for (char ch : str) {  
        std::cout << ch;  
    }  
    std::cout << "\n";  
    std::cout << "Using .c_str(): " << str.c_str() << "\n";  
    return 0;  
}  
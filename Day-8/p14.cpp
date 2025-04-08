#include <iostream>  
#include <string>  // Include string library for std::string  
int main() {  
    // (a) Initializing C-Style Strings  
    char str1[] = "Hello";    
    char str2[6] = {'H', 'e', 'l', 'l', 'o', '\0'};    
    char str3[10] = "Hello";    
    std::cout << "C-Style Strings:" << std::endl;  
    std::cout << "str1: " << str1 << std::endl;  
    std::cout << "str2: " << str2 << std::endl;  
    std::cout << "str3: " << str3 << std::endl;  
    // (b) Initializing std::string  
    std::string s1 = "Hello";    
    std::string s2("World");    
    std::string s3(5, 'A');  // Creates "AAAAA"  
    std::string s4 = s1 + " " + s2;  // Concatenation of s1 and s2  
    std::cout << "\nstd::string Initialization:" << std::endl;  
    std::cout << "s1: " << s1 << std::endl;  
    std::cout << "s2: " << s2 << std::endl;  
    std::cout << "s3: " << s3 << std::endl;  
    std::cout << "s4: " << s4 << std::endl;  
    return 0;  
}  
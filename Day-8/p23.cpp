#include <iostream>    
void printString(const std::string &str) {  
    std::cout << str << std::endl;  
}  
int main() {  
    std::string str = "Hello C++";  
    printString(str);  
    return 0;  
}  
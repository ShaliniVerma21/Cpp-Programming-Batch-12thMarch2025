/*
Functions: 

The function in C++ language is also known as a procedure or subroutine in other 
programming languages. A program implements functions as independent blocks of code 
that complete single tasks, which developers can call repeatedly. Programming 
efficiency and organization improve through the use of functions because they make 
code reusable between different modules.

In C++ programming language, we can create functions to perform any task. 
A function can be called many times. It provides modularity and code reusability.


Syntax of C++ Function:

return_type function_name(data_type parameter...)    
{      
//code to be executed      
}   


there are main two types functions :
1.  parameterized Function
2.  non-parameterized Function
*/

//simple example of C++ function.

#include <iostream>  
  
// Function that adds two integers and returns the result  
int add(int x, int y) {  
    return x + y;  
}  
  
int main() {  
    int sum = add(7, 5); // Function call with arguments  
    std::cout << " : " << sum << std::endl;  
    return 0;  
}  
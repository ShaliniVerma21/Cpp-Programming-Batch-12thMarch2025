/*
🔹 What is Exception Handling?

Exception Handling is a mechanism to handle runtime errors in a program so that the normal flow of 
execution is maintained.

🔹 Common Runtime Errors:

Division by zero
File not found
Memory overflow
Invalid input


🔹 Keywords Used:

try	--> Block of code to be tested for errors.
catch --> Block to handle the exception.
throw --> Used to throw an exception manually.


🔹 Syntax:

try {
   // Code that may throw an exception
   throw exception_type;
}
catch(exception_type e) {
   // Code to handle exception
}
*/


//  Program 1: Divide by zero

#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 0;
    try {
        if (b == 0)
            throw "Cannot divide by zero!";
        cout << "Result: " << a / b;
    }
    catch (const char* msg) {
        cout << "Exception: " << msg << endl;
    }
    return 0;
}

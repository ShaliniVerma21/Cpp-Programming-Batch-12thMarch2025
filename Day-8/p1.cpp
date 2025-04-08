/*
In C++, the string is an object of the std::string class that represents a sequence of characters. 
We can perform many operations on strings, such as concatenation, comparison, conversion, etc.

In C++, you can use strings in two ways:

1. C-style strings – Using character arrays
2. C++ string class – From the Standard Template Library (STL)

 Important Points :

1.  Use #include <string> when using string class.

2. getline() is used for full-line input (including spaces).

3. string class handles memory and null-terminators automatically.
*/

#include <iostream>
using namespace std;

int main()
{
    char name[] = "Kunal";
    cout << "Name is: " << name << endl;
    return 0;
}

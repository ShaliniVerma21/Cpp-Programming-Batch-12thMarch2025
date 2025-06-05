/*
3. Streams in C++

Theory:
Streams are sequences of bytes used to perform input and output operations. 
C++ provides different types of streams for file I/O and console I/O.

Purpose:

1.To handle standard input (cin), output (cout), error (cerr).
2.To perform file operations using ifstream, ofstream, and fstream.

Applications:

1.Reading user input and displaying output.
2.Redirecting input/output to/from files.
3.Logging data using error streams.
4.Managing formatted I/O.
*/

//Example 1: Standard input and output

#include <iostream>
int main() {
    int a;
    std::cout << "Enter a number: ";
    std::cin >> a;
    std::cout << "You entered: " << a;
    return 0;
}


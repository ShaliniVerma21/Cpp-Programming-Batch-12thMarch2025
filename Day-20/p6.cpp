/*
2. File Handling in C++

Theory:
File handling in C++ allows reading from and writing to files (text or binary) using file 
streams. There are two types of file streams: input streams and output streams.

Purpose:

1.Store and retrieve data permanently.
2.Handle user data, logs, configurations, etc.
3.Perform input/output operations with files.

Applications:

1.Saving user records in files.
2.Reading configuration settings.
3.Creating log files for error tracking.
4.Writing reports or summaries.
5.Handling data for billing or results.
*/

// Example 1: Write to file

#include <iostream>
#include <fstream>
int main() {
    std::ofstream file("example.txt");
    file << "Hello, file!";
    file.close();
    return 0;
}

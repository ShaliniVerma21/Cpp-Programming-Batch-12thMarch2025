//3. Copying Strings Using Pointers

#include <iostream>
using namespace std;

void stringCopy(char* dest, const char* src) {
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0'; // Null-terminate the destination string
}

int main() {
    const char* source = "Hello, World!";
    char destination[50];
    stringCopy(destination, source);
    cout << "Copied string: " << destination << endl;
    return 0;
}
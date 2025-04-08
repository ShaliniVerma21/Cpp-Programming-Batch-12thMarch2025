//8. Replace Part of a String
#include <iostream>
#include <string>
using namespace std;

int main() {
    string message = "I like Java.";
    message.replace(7, 4, "C++"); // replaces "Java" with "C++"
    cout << "Updated message: " << message << endl;
    return 0;
}

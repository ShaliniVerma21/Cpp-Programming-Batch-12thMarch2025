// Example 9: Reverse a String

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    string str = "OpenAI";
    reverse(str.begin(), str.end());
    cout << "Reversed: " << str;
    return 0;
}

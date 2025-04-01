//3. Using <string> for String Manipulation

#include <iostream>
#include <string> // For string manipulation
using namespace std;

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    getline(cin, str1);
    cout << "Enter second string: ";
    getline(cin, str2);

    cout << "Concatenated string: " << str1 + str2 << endl;
    cout << "Length of first string: " << str1.length() << endl;
    cout << "First string in uppercase: " << str1;
    for (char &c : str1) c = toupper(c);
    char a='b';
    a = toupper(a);
    cout << "First string in uppercase: " << a;
    str1 = toupper(str1);
    cout << "First string in uppercase: " << str1;
    cout << endl;

    return 0;
}
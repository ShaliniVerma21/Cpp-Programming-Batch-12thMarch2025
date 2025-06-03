//Program 2: Taking input in vector

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> names;
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    // Taking names input
    for(int i = 0; i < n; i++) {
        string name;
        cout << "Enter name: ";
        cin >> name;
        names.push_back(name);
    }

    // Displaying names
    cout << "Students are: ";
    for(string s : names)
        cout << s << " ";
    return 0;
}

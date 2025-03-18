// WAP to display information of a student using multiple data types
#include <iostream>
using namespace std;

int main()
{
    // declare varible
    string name;
    int age;
    float marks;
    char grade;
    bool isMarried;

    // initialize values of variables via user input
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your age: ";
    cin >> age;
    cout << "Enter your marks: ";
    cin >> marks;
    cout << "Enter your grade: ";
    cin >> grade;
    cout << "Are you married? (true/false): ";
    cin >> isMarried;


    // escape sequence (\n --- new line)
    // display information of student
    cout << "\n ------------Display Information of a Student------------ \n";
    cout << "\n Name: " << name;
    cout << "\n Age: " << age;
    cout << "\n Marks: " << marks;
    cout << "\n Grade: " << grade;
    cout << "\n Is Married: " << isMarried << "\n"
         << endl;

    return 0;
}
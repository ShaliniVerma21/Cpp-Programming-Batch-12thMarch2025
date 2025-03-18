#include <iostream>
using namespace std;

// Program to Check if a Character is a Vowel or Consonant

int main(){
    
    char ch;
    cout << "Enter a Character : ";
    cin >> ch;
    
    //write logic to filter consonant & Vowel
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||
       ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
    {
        cout << ch << "is a Vowel." << endl;
    }
    else
    {
        cout<< ch << "is a Consonant." <<endl;
    }

    return 0;
}
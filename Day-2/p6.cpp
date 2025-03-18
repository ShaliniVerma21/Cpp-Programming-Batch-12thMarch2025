#include<iostream>
using namespace std;

// program to calculate average of three numbers

int main(){
    int num1,num2,num3,avg;

    cout<< "Enter 3 numbers to get avarage of it : ";
    cin>> num1 >> num2 >> num3;

    avg=(num1+num2+num3)/3;
    
    cout<< "avarage of " << num1 << "," << num2 << "and" << num3 << "is : " << avg << endl;

    return 0;
}
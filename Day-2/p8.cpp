#include<iostream>
using namespace std;

// Program to find Minimum of 2 numbers

int main(){
    int num1,num2;

    cout<< "Enter two numbers";
    cin>> num1 >> num2;

    int min = (num1<num2)?num1:num2;
    cout<< "Minimum Numbers : "<< min << endl;

    return 0; 
}
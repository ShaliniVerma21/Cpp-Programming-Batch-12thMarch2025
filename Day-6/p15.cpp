//Pass by Pointers

#include<iostream>  
using namespace std; 
 
void updateValue(int *ptr) {  
    *ptr = 20; // Modifies the value of the variable  
}  
int main() {  
    int num = 10;  
    cout << "Before: " << num << endl;  
    updateValue(&num); // Passing address of num  
    cout << "After: " << num << endl;  
    return 0;  
}  
/*
Function Parameters:

1. Pass by value: 
In Pass by Value, a copy of the actual parameter is passed to the function. 
It means any modifications made inside the function do not affect the original 
variable.

2. Pass by reference: 
In Pass by Reference, a function receives the actual memory address of the 
argument instead of a copy. It means any changes made inside the function 
directly affect the original variable.

3. Pass by Pointers: 
In Pass by Pointer, we pass the memory address of a variable using a pointer. 
The function modifies the value stored at the given address.

*/

#include<iostream>  
using namespace std;  
void square(int num) {  
    num = num * num;    
}  
int main() {  
    int x = 5;  
    square(x);  
cout << x;  // Output: 5 (unchanged)  
}  
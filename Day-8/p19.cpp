#include <iostream>    
#include <cstring>    
using namespace std;    
int main ()    
{    
  char key[] = "mango";  // Define the correct answer as a C-string  
  char buffer[50];  // // Buffer to store user input  
  do {    
     cout<<"What is my favourite fruit? ";    
     cin>>buffer;    
  } while (strcmp (key, buffer) != 0);  // Compare input with key;  
 cout<<"Answer is correct!!"<<endl;    
  return 0;    
}   
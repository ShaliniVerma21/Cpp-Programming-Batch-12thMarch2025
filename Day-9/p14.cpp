//sizeof() operator

#include <iostream>  
using namespace std;  
int main()  
{  
  // Determining the space in bytes occupied by each data type.  
  std::cout << "Size of integer data type : " <<sizeof(int)<< std::endl;  
  std::cout << "Size of float data type : " <<sizeof(float)<< std::endl;  
  std::cout << "Size of double data type : " <<sizeof(double)<< std::endl;  
  std::cout << "Size of char data type : " <<sizeof(char)<< std::endl;  
  return 0;  
}  
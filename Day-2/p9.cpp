#include <iostream>
using namespace std;

// Program to find the sum of First N Natural Numbers

int main(){
    int n,sum=0;

    cout << "Enter a Positive integer : ";
    cin>> n;

    for(int i=0;i<=n;++i)
    {
        sum+=i;
    }

    cout << "sum of First " << n << "natural numbers : " << sum << endl;

    return 0 ;
}
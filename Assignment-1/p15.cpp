//Problem 14: Travel Booking System

#include <iostream>
#include <string>
using namespace std;

struct TravelPackage {
    string destination;
    float price;
};

void displayPackages(TravelPackage packages[], int count) {
    cout << "Destination\tPrice\n";
    for (int i = 0; i < count; i++) {
        cout << packages[i].destination << "\t\t" << packages[i].price << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of travel packages: ";
    cin >> n;
    TravelPackage packages[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter destination and price: ";
        cin >> packages[i].destination >> packages[i].price;
    }
    displayPackages(packages, n);
    return 0;
}
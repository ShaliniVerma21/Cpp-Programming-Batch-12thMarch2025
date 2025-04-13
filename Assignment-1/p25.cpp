//Problem 24: Travel Package Management

#include <iostream>
#include <string>
using namespace std;

struct TravelPackage {
    string destination;
    float price;
    int duration; // in days
};

void displayPackages(TravelPackage packages[], int count) {
    cout << "Destination\tPrice\tDuration (days)\n";
    for (int i = 0; i < count; i++) {
        cout << packages[i].destination << "\t\t" << packages[i].price << "\t" << packages[i].duration << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of travel packages: ";
    cin >> n;
    TravelPackage packages[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter destination, price, and duration: ";
        cin >> packages[i].destination >> packages[i].price >> packages[i].duration;
    }
    displayPackages(packages, n);
    return 0;
}
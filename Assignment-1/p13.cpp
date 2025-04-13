//Problem 12: Mall Store Management

#include <iostream>
#include <string>
using namespace std;

struct Store {
    string name;
    float revenue;
};

void displayStores(Store stores[], int count) {
    cout << "Store Name\tRevenue\n";
    for (int i = 0; i < count; i++) {
        cout << stores[i].name << "\t\t" << stores[i].revenue << endl;
    }
}

int main()
    {
    int n;
    cout << "Enter number of stores: ";
    cin >> n;
    Store stores[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter store name and revenue: ";
        cin >> stores[i].name >> stores[i].revenue;
    }
    displayStores(stores, n);
    return 0;
}
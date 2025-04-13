//Problem 9: Simple Fitness Tracker

#include <iostream>
#include <string>
using namespace std;

struct FitnessRecord {
    string date;
    float weight;
    float height float bmi;
};

void calculateBMI(FitnessRecord &record) {
    record.bmi = record.weight / (record.height * record.height);
}

void displayRecord(FitnessRecord record) {
    cout << "Date: " << record.date << ", Weight: " << record.weight << ", Height: " << record.height << ", BMI: " << record.bmi << endl;
}

int main() {
    int n;
    cout << "Enter number of fitness records: ";
    cin >> n;
    FitnessRecord records[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter date, weight (kg), and height (m): ";
        cin >> records[i].date >> records[i].weight >> records[i].height;
        calculateBMI(records[i]);
    }
    cout << "Fitness Records:\n";
    for (int i = 0; i < n; i++) {
        displayRecord(records[i]);
    }
    return 0;
}
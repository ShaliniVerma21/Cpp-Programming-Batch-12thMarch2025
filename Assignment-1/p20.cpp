//Problem 19: Diary Entry Management

#include <iostream>
#include <string>
using namespace std;

struct DiaryEntry {
    string date;
    string content;
};

void displayEntries(DiaryEntry entries[], int count) {
    cout << "Date\t\tContent\n";
    for (int i = 0; i < count; i++) {
        cout << entries[i].date << "\t" << entries[i].content << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of diary entries: ";
    cin >> n;
    DiaryEntry entries[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter date and content: ";
        cin >> entries[i].date >> entries[i].content;
    }
    displayEntries(entries, n);
    return 0;
}
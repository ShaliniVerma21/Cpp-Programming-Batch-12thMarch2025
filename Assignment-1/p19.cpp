//Problem 18: Voting System

#include <iostream>
#include <string>
using namespace std;

struct Candidate {
    string name;
    int votes;
};

void displayResults(Candidate candidates[], int count) {
    cout << "Candidate Name\tVotes\n";
    for (int i = 0; i < count; i++) {
        cout << candidates[i].name << "\t\t" << candidates[i].votes << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of candidates: ";
    cin >> n;
    Candidate candidates[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter candidate name: ";
        cin >> candidates[i].name;
        candidates[i].votes = 0; // Initialize votes to 0
    }

    int votes;
    cout << "Enter number of votes: ";
    cin >> votes;
    for (int i = 0; i < votes; i++) {
        int choice;
        cout << "Vote for candidate (1 to " << n << "): ";
        cin >> choice;
        if (choice > 0 && choice <= n) {
            candidates[choice - 1].votes++;
        } else {
            cout << "Invalid choice!" << endl;
        }
    }

    displayResults(candidates, n);
    return 0;
}
//Problem 25: Job Listing Management

#include <iostream>
#include <string>
using namespace std;

struct Job {
    string title;
    string company;
    string location;
};

void displayJobs(Job jobs[], int count) {
    cout << "Job Title\tCompany\t\tLocation\n";
    for (int i = 0; i < count; i++) {
        cout << jobs[i].title << "\t\t" << jobs[i].company << "\t\t" << jobs[i].location << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of job listings: ";
    cin >> n;
    Job jobs[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter job title, company, and location: ";
        cin >> jobs[i].title >> jobs[i].company >> jobs[i].location;
    }
    displayJobs(jobs, n);
    return 0;
}
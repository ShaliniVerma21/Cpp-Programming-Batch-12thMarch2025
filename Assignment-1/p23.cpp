//Problem 22: Survey Management

#include <iostream>
#include <string>
using namespace std;

struct Survey {
    string question;
    string options[4];
    int responses[4] = {0}; // Initialize responses to 0
};

void displaySurveyResults(Survey survey) {
    cout << survey.question << endl;
    for (int i = 0; i < 4; i++) {
        cout << survey.options[i] << ": " << survey.responses[i] << " votes" << endl;
    }
}

int main() {
    Survey survey;
    cout << "Enter survey question: ";
    cin >> survey.question;
    for (int i = 0; i < 4; i++) {
        cout << "Enter option " << i + 1 << ": ";
        cin >> survey.options[i];
    }

    int choice;
    cout << "Vote for an option (1-4): ";
    cin >> choice;
    if (choice >= 1 && choice <= 4) {
        survey.responses[choice - 1]++;
    } else {
        cout << "Invalid choice!" << endl;
    }

    displaySurveyResults(survey);
    return 0;
}
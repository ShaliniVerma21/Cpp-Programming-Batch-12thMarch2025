//Problem 17: Simple Quiz Application

#include <iostream>
#include <string>
using namespace std;

struct Question {
    string question;
    string options[4];
    int answer; // index of the correct option
};

void displayQuiz(Question quiz[], int count) {
    int score = 0;
    for (int i = 0; i < count; i++) {
        cout << quiz[i].question << endl;
        for (int j = 0; j < 4; j++) {
            cout << j + 1 << ". " << quiz[i].options[j] << endl;
        }
        int userAnswer;
        cout << "Your answer: ";
        cin >> userAnswer;
        if (userAnswer - 1 == quiz[i].answer) {
            score++;
        }
    }
    cout << "Your score: " << score << "/" << count << endl;
}

int main() {
    int n;
    cout << "Enter number of questions: ";
    cin >> n;
    Question quiz[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter question and 4 options (correct option index): ";
        cin >> quiz[i].question;
        for (int j = 0; j < 4; j++) {
            cin >> quiz[i].options[j];
        }
        cin >> quiz[i].answer;
    }
    displayQuiz(quiz, n);
    return 0;
}
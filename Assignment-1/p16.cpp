//Problem 15: Simple Chatbot

#include <iostream>
#include <string>
using namespace std;

void respondToUser (string input) {
    if (input == "Hello") {
        cout << "Hi there! How can I help you today?" << endl;
    } else if (input == "What is your name?") {
        cout << "I am a simple chatbot." << endl;
    } else {
        cout << "I'm sorry, I don't understand." << endl;
    }
}

int main() {
    string userInput;
    cout << "You: ";
    getline(cin, userInput);
    respondToUser (userInput);
    return 0;
}
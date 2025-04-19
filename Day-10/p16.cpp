//5. Online Quiz System

#include <iostream>
#include <vector>

class Question {
public:
    std::string questionText;
    std::string answer;

    Question(std::string text, std::string ans) : questionText(text), answer(ans) {}
};

class Quiz {
private:
    std::vector<Question> questions;

public:
    void addQuestion(const Question& question) {
        questions.push_back(question);
    }

    void takeQuiz() {
        int score = 0;
        for (const auto& q : questions) {
            std::string userAnswer;
            std::cout << q.questionText << "\n";
            std::cin >> userAnswer;
            if (userAnswer == q.answer) {
                score++;
            }
        }
        std::cout << "Your score: " << score << "/" << questions.size() << "\n";
    }
};
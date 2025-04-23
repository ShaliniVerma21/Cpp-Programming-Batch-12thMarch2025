//Fitness Class Feedback System

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm> // For std::sort

using namespace std;

// Enumeration for class types
enum class ClassType {
    YOGA,
    ZUMBA,
    SPIN,
    PILATES
};

// Structure for feedback
struct Feedback {
    string participantName; // Name of the participant
    int rating; // Rating from 1 to 5
    string comments; // Comments from the participant

    // Constructor for Feedback
    Feedback(string name, int rate, string comment)
        : participantName(name), rating(rate), comments(comment) {}
};

// Base class for Fitness Class
class FitnessClass {
protected:
    string className; // Name of the fitness class
    ClassType classType; // Type of the fitness class
    vector<Feedback> feedbacks; // Vector to store feedbacks

public:
    // Constructor for FitnessClass
    FitnessClass(string name, ClassType type)
        : className(name), classType(type) {}

    // Function to add feedback
    virtual void addFeedback(const Feedback& feedback) {
        feedbacks.push_back(feedback);
    }

    // Function to display feedback
    virtual void displayFeedback() const {
        cout << "Feedback for " << className << ":\n";
        for (const auto& feedback : feedbacks) {
            cout << "Participant: " << feedback.participantName
                 << ", Rating: " << feedback.rating
                 << ", Comments: " << feedback.comments << endl;
        }
    }

    // Function to calculate average rating
    double calculateAverageRating() const {
        if (feedbacks.empty()) return 0.0;
        double total = 0;
        for (const auto& feedback : feedbacks) {
            total += feedback.rating;
        }
        return total / feedbacks.size();
    }

    // Virtual destructor
    virtual ~FitnessClass() {}
};

// Derived class for Yoga Class
class YogaClass : public FitnessClass {
public:
    // Constructor for YogaClass
    YogaClass() : FitnessClass("Yoga Class", ClassType::YOGA) {}

    // Override displayFeedback to add specific message
    void displayFeedback() const override {
        cout << "=== Yoga Class Feedback ===\n";
        FitnessClass::displayFeedback();
        cout << "Average Rating: " << fixed << setprecision(2) << calculateAverageRating() << endl;
    }
};

// Derived class for Zumba Class
class ZumbaClass : public FitnessClass {
public:
    // Constructor for ZumbaClass
    ZumbaClass() : FitnessClass("Zumba Class", ClassType::ZUMBA) {}

    // Override displayFeedback to add specific message
    void displayFeedback() const override {
        cout << "=== Zumba Class Feedback ===\n";
        FitnessClass::displayFeedback();
        cout << "Average Rating: " << fixed << setprecision(2) << calculateAverageRating() << endl;
    }
};

// Function to display class type
void displayClassType(ClassType type) {
    switch (type) {
        case ClassType::YOGA: cout << "Yoga"; break;
        case ClassType::ZUMBA: cout << "Zumba"; break;
        case ClassType::SPIN: cout << "Spin"; break;
        case ClassType::PILATES: cout << "Pilates"; break;
    }
}

int main() {
    // Create instances of fitness classes
    YogaClass yoga;
    ZumbaClass zumba;

    // Add feedback for Yoga Class
    yoga.addFeedback(Feedback("Alice", 5, "Loved the session!"));
    yoga.addFeedback(Feedback("Bob", 4, "Great instructor!"));
    yoga.addFeedback(Feedback("Charlie", 3, "It was okay."));

    // Add feedback for Zumba Class
    zumba.addFeedback(Feedback("Diana", 5, "So much fun!"));
    zumba.addFeedback(Feedback("Eve", 4, "Energetic and engaging!"));
    zumba.addFeedback(Feedback("Frank", 2, "Too fast-paced for me."));

    // Display feedback for both classes
    yoga.displayFeedback();
    cout << endl;
    zumba.displayFeedback();

    return 0;
}
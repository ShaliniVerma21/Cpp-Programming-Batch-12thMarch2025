//2. Rock, Paper, Scissors Game

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stdexcept>
using namespace std;

// Abstract base class (Abstraction)
class Game {
public:
    virtual void play() = 0;
    virtual void showResult() const = 0;
    virtual ~Game() {}
};

// Utility function to get random choice for computer
string getComputerChoice() {
    string choices[] = {"Rock", "Paper", "Scissors"};
    return choices[rand() % 3];
}

// Derived class implementing the game logic (Inheritance, Encapsulation)
class RPSGame : public Game {
private:
    string playerName;
    string playerChoice;
    string computerChoice;
    string result;

public:
    // Constructor
    RPSGame(string name) : playerName(name), playerChoice(""), computerChoice(""), result("") {}

    // Play one round
    void play() override {
        cout << "\n🎮 Enter your choice (Rock, Paper, Scissors): ";
        cin >> playerChoice;

        // Capitalize first letter
        playerChoice[0] = toupper(playerChoice[0]);
        for (int i = 1; i < playerChoice.length(); i++)
            playerChoice[i] = tolower(playerChoice[i]);

        // Validate input
        if (playerChoice != "Rock" && playerChoice != "Paper" && playerChoice != "Scissors") {
            throw invalid_argument("❌ Invalid choice. Please enter Rock, Paper or Scissors.");
        }

        computerChoice = getComputerChoice();

        // Determine result (Polymorphism via overridden function)
        if (playerChoice == computerChoice) {
            result = "Draw 🤝";
        } else if ((playerChoice == "Rock" && computerChoice == "Scissors") ||
                   (playerChoice == "Paper" && computerChoice == "Rock") ||
                   (playerChoice == "Scissors" && computerChoice == "Paper")) {
            result = "You Win 🏆";
        } else {
            result = "Computer Wins 💻";
        }
    }

    // Show the game result
    void showResult() const override {
        cout << "\n📋 Result Summary for " << playerName << ":\n";
        cout << "➡️ Your Choice: " << playerChoice << endl;
        cout << "➡️ Computer's Choice: " << computerChoice << endl;
        cout << "➡️ Outcome: " << result << endl;
    }

    // Get result string for record
    string getResultRecord() const {
        return playerName + " vs Computer → " + result;
    }
};

// Class to manage game history (CRUD with STL Vector)
class GameManager {
private:
    vector<RPSGame*> gameHistory;

public:
    void addGame(RPSGame* game) {
        gameHistory.push_back(game);
    }

    void showAllResults() const {
        if (gameHistory.empty()) {
            cout << "📭 No game history yet.\n";
            return;
        }

        cout << "\n🕹️ Game History:\n";
        for (size_t i = 0; i < gameHistory.size(); ++i) {
            cout << "[" << i + 1 << "] ";
            gameHistory[i]->showResult();
        }
    }

    void clearAll() {
        for (auto* game : gameHistory) {
            delete game;
        }
        gameHistory.clear();
        cout << "🗑️ All history cleared.\n";
    }

    ~GameManager() {
        clearAll();
    }
};

// Function to display menu
void displayMenu() {
    cout << "\n===== ROCK PAPER SCISSORS GAME MENU =====\n";
    cout << "1. Play Game\n";
    cout << "2. Show Game History\n";
    cout << "3. Clear History\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

// Main function
int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed random generator
    GameManager manager;
    int choice;
    string playerName;

    cout << "🎮 Welcome to Rock, Paper, Scissors Game!\n";
    cout << "👤 Enter your name: ";
    getline(cin, playerName);

    do {
        displayMenu();
        cin >> choice;

        try {
            switch (choice) {
                case 1: {
                    RPSGame* game = new RPSGame(playerName);
                    game->play();
                    game->showResult();
                    manager.addGame(game);
                    break;
                }

                case 2:
                    manager.showAllResults();
                    break;

                case 3:
                    manager.clearAll();
                    break;

                case 4:
                    cout << "👋 Thanks for playing, " << playerName << "! Goodbye!\n";
                    break;

                default:
                    cout << "⚠️ Invalid choice. Please select 1-4.\n";
            }
        } catch (const exception& e) {
            cout << "❗ Error: " << e.what() << endl;
        }

    } while (choice != 4);

    return 0;
}

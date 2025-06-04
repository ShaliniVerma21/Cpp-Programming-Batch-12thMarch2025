/*
25 Real world Problems by implementing STL Library, CRUD Operation Oops Concepts, Arrays, Strings, Pointers,
Loops, Control statements, Logic Creation, escape sequence
*/

//1. Word Occurrence with Case-Insensitive Count and String Compression, Frequency of Words in Paragraph

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <vector>
using namespace std;

// Abstract class for Word Processing (Abstraction)
class ITextProcessor {
public:
    virtual void processText(const string& text) = 0;
    virtual void displayFrequencies() const = 0;
    virtual void deleteWord(const string& word) = 0;
    virtual ~ITextProcessor() {}
};

// Derived class implementing functionality (Inheritance, Encapsulation)
class WordCounter : public ITextProcessor {
private:
    map<string, int> wordFrequency;  // STL Map for word -> frequency
    string paragraph;

    // Helper to convert string to lowercase
    string toLower(const string& str) const {
        string lowerStr = str;
        transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
        return lowerStr;
    }

public:
    // Constructor
    WordCounter(const string& para) {
        paragraph = para;
    }

    // Process paragraph and count words (Polymorphism)
    void processText(const string& text) override {
        wordFrequency.clear();
        paragraph = text;

        string word;
        istringstream stream(text);

        while (stream >> word) {
            // Remove punctuation
            word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
            word = toLower(word);
            wordFrequency[word]++;
        }
    }

    // Display word frequencies
    void displayFrequencies() const override {
        cout << "\n📊 Word Frequency Table (Case-Insensitive):\n";
        for (const auto& entry : wordFrequency) {
            cout << "   ➤ " << entry.first << " : " << entry.second << "\n";
        }
    }

    // Delete a word from the map
    void deleteWord(const string& word) override {
        string lowerWord = toLower(word);
        if (wordFrequency.find(lowerWord) != wordFrequency.end()) {
            wordFrequency.erase(lowerWord);
            cout << "✅ Deleted '" << word << "' successfully.\n";
        } else {
            cout << "❌ Word not found in frequency map.\n";
        }
    }

    // Compress paragraph string
    void compressString() {
        string compressed = "";
        for (size_t i = 0; i < paragraph.length();) {
            char current = paragraph[i];
            int count = 1;
            while (i + 1 < paragraph.length() && paragraph[i + 1] == current) {
                count++;
                i++;
            }
            compressed += current + to_string(count);
            i++;
        }
        cout << "\n🗜️ Compressed String:\n" << compressed << endl;
    }
};

// Manager class to handle CRUD and display (OOP + Functions)
class AppManager {
private:
    WordCounter* counter = nullptr;

public:
    // Create instance and process paragraph
    void createAndProcess() {
        cin.ignore();
        string para;
        cout << "\n📝 Enter paragraph: ";
        getline(cin, para);

        delete counter;  // Delete old if exists
        counter = new WordCounter(para);
        counter->processText(para);

        cout << "✅ Paragraph processed successfully!\n";
    }

    // Show word frequencies
    void showFrequencies() {
        if (counter)
            counter->displayFrequencies();
        else
            cout << "⚠️ No data processed yet!\n";
    }

    // Delete word by user
    void deleteWord() {
        if (!counter) {
            cout << "⚠️ No data processed yet!\n";
            return;
        }
        string word;
        cout << "🔤 Enter word to delete: ";
        cin >> word;
        counter->deleteWord(word);
    }

    // Compress and show string
    void compress() {
        if (counter)
            counter->compressString();
        else
            cout << "⚠️ No paragraph available to compress!\n";
    }

    // Destructor
    ~AppManager() {
        delete counter;
    }
};

// Display menu
void menu() {
    cout << "\n========= 📘 WORD FREQUENCY MENU =========\n";
    cout << "1. Input & Process Paragraph\n";
    cout << "2. Show Word Frequencies\n";
    cout << "3. Delete Word from Frequency\n";
    cout << "4. Compress Paragraph String\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

// Main driver function
int main() {
    AppManager app;
    int choice;

    do {
        menu();
        cin >> choice;

        try {
            switch (choice) {
                case 1: app.createAndProcess(); break;
                case 2: app.showFrequencies(); break;
                case 3: app.deleteWord(); break;
                case 4: app.compress(); break;
                case 5: cout << "👋 Exiting... Goodbye!\n"; break;
                default: cout << "⚠️ Invalid choice!\n";
            }
        } catch (exception& e) {
            cout << "❗ Exception: " << e.what() << endl;
        }

    } while (choice != 5);

    return 0;
}

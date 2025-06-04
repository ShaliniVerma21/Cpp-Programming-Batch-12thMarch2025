//6. BMI Calculator

#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <stdexcept>
using namespace std;

// Abstract class for BMI Record (Abstraction)
class BMIRecord {
public:
    virtual void display() const = 0;  // Pure virtual function
    virtual ~BMIRecord() {}
};

// Concrete class (Encapsulation, Inheritance, Polymorphism)
class PersonBMI : public BMIRecord {
private:
    int id;
    string name;
    float height;  // in meters
    float weight;  // in kilograms
    float bmi;

    // Calculate BMI
    float calculateBMI() {
        return weight / (height * height);
    }

    // Determine BMI Category
    string getCategory() const {
        if (bmi < 18.5) return "Underweight";
        else if (bmi < 24.9) return "Normal";
        else if (bmi < 29.9) return "Overweight";
        else return "Obese";
    }

public:
    // Constructor
    PersonBMI(int i, string n, float h, float w)
        : id(i), name(n), height(h), weight(w) {
        bmi = calculateBMI();
    }

    // Update height and weight
    void updateData(float h, float w) {
        height = h;
        weight = w;
        bmi = calculateBMI();
    }

    int getId() const { return id; }

    // Overridden display method
    void display() const override {
        cout << left << setw(5) << id
             << setw(15) << name
             << setw(10) << height
             << setw(10) << weight
             << setw(10) << fixed << setprecision(2) << bmi
             << getCategory() << endl;
    }
};

// Manager class for CRUD Operations
class BMIManager {
private:
    map<int, PersonBMI*> records;
    int idCounter;

public:
    BMIManager() : idCounter(1) {}

    // Create BMI Record
    void addPerson(string name, float height, float weight) {
        PersonBMI* p = new PersonBMI(idCounter, name, height, weight);
        records[idCounter] = p;
        cout << "✅ Record added with ID: " << idCounter << "\n";
        idCounter++;
    }

    // Display All Records
    void displayAll() {
        if (records.empty()) {
            cout << "📭 No BMI records available.\n";
            return;
        }
        cout << "\n📋 BMI RECORDS\n";
        cout << left << setw(5) << "ID"
             << setw(15) << "Name"
             << setw(10) << "Height"
             << setw(10) << "Weight"
             << setw(10) << "BMI"
             << "Category\n";
        cout << "-------------------------------------------------------------\n";
        for (auto& [id, record] : records)
            record->display();
    }

    // Update Record
    void updateRecord(int id, float height, float weight) {
        if (records.find(id) == records.end())
            throw runtime_error("❌ Record ID not found.");
        records[id]->updateData(height, weight);
        cout << "🔁 Record updated.\n";
    }

    // Delete Record
    void deleteRecord(int id) {
        if (records.find(id) == records.end())
            throw runtime_error("❌ Record ID not found.");
        delete records[id];
        records.erase(id);
        cout << "🗑️ Record deleted.\n";
    }

    // Destructor
    ~BMIManager() {
        for (auto& [id, record] : records)
            delete record;
    }
};

// Menu Display Function
void showMenu() {
    cout << "\n🧮 BMI CALCULATOR MENU\n";
    cout << "---------------------------\n";
    cout << "1. Add Record\n";
    cout << "2. View All Records\n";
    cout << "3. Update Record\n";
    cout << "4. Delete Record\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

// Main Function
int main() {
    BMIManager manager;
    int choice, id;
    string name;
    float height, weight;

    do {
        showMenu();
        cin >> choice;
        cin.ignore(); // clear newline

        try {
            switch (choice) {
                case 1:
                    cout << "Enter name: ";
                    getline(cin, name);
                    cout << "Enter height (m): ";
                    cin >> height;
                    cout << "Enter weight (kg): ";
                    cin >> weight;
                    manager.addPerson(name, height, weight);
                    break;

                case 2:
                    manager.displayAll();
                    break;

                case 3:
                    cout << "Enter ID to update: ";
                    cin >> id;
                    cout << "Enter new height (m): ";
                    cin >> height;
                    cout << "Enter new weight (kg): ";
                    cin >> weight;
                    manager.updateRecord(id, height, weight);
                    break;

                case 4:
                    cout << "Enter ID to delete: ";
                    cin >> id;
                    manager.deleteRecord(id);
                    break;

                case 5:
                    cout << "👋 Exiting BMI Calculator. Stay healthy!\n";
                    break;

                default:
                    cout << "⚠️ Invalid choice. Try again.\n";
            }
        } catch (exception &e) {
            cout << "❗ Error: " << e.what() << endl;
        }

    } while (choice != 5);

    return 0;
}

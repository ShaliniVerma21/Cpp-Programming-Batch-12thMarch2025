//Pet Adoption System

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Enumeration for pet types
enum class PetType {
    DOG,
    CAT,
    BIRD,
    REPTILE
};

// Structure for a pet
struct Pet {
    string name; // Name of the pet
    PetType type; // Type of the pet
    int age; // Age of the pet in years
    bool isAdopted; // Adoption status

    // Constructor for Pet
    Pet(string n, PetType t, int a) : name(n), type(t), age(a), isAdopted(false) {}

    // Function to adopt the pet
    void adopt() {
        isAdopted = true;
    }
};

// Base class for AdoptionCenter
class AdoptionCenter {
protected:
    vector<Pet> pets; // List of pets available for adoption

public:
    // Function to add a pet to the adoption center
    void addPet(const Pet& pet) {
        pets.push_back(pet);
    }

    // Function to display all available pets
    void displayAvailablePets() const {
        cout << "Available Pets for Adoption:\n";
        for (const auto& pet : pets) {
            if (!pet.isAdopted) {
                cout << "Name: " << pet.name
                     << ", Type: " << getPetTypeString(pet.type)
                     << ", Age: " << pet.age << " years\n";
            }
        }
    }

    // Function to adopt a pet
    bool adoptPet(const string& petName) {
        for (auto& pet : pets) {
            if (pet.name == petName && !pet.isAdopted) {
                pet.adopt();
                cout << pet.name << " has been adopted!\n";
                return true;
            }
        }
        cout << "Pet not found or already adopted.\n";
        return false;
    }

    // Function to get string representation of pet type
    string getPetTypeString(PetType type) const {
        switch (type) {
            case PetType::DOG: return "Dog";
            case PetType::CAT: return "Cat";
            case PetType::BIRD: return "Bird";
            case PetType::REPTILE: return "Reptile";
            default: return "Unknown";
        }
    }

    // Virtual destructor
    virtual ~AdoptionCenter() {}
};

// Derived class for ExtendedAdoptionCenter
class ExtendedAdoptionCenter : public AdoptionCenter {
public:
    // Function to display adopted pets
    void displayAdoptedPets() const {
        cout << "Adopted Pets:\n";
        for (const auto& pet : pets) {
            if (pet.isAdopted) {
                cout << "Name: " << pet.name
                     << ", Type: " << getPetTypeString(pet.type)
                     << ", Age: " << pet.age << " years\n";
            }
        }
    }
};

int main() {
    // Create an instance of ExtendedAdoptionCenter
    ExtendedAdoptionCenter adoptionCenter;

    // Add pets to the adoption center
    adoptionCenter.addPet(Pet("Buddy", PetType::DOG, 3));
    adoptionCenter.addPet(Pet("Mittens", PetType::CAT, 2));
    adoptionCenter.addPet(Pet("Tweety", PetType::BIRD, 1));
    adoptionCenter.addPet(Pet("Snappy", PetType::REPTILE, 4));

    // Display available pets
    adoptionCenter.displayAvailablePets();
    cout << endl;

    // Adopt a pet
    adoptionCenter.adoptPet("Buddy");
    adoptionCenter.adoptPet("Mittens");

    // Display available pets after adoption
    adoptionCenter.displayAvailablePets();
    cout << endl;

    // Display adopted pets
    adoptionCenter.displayAdoptedPets();

    return 0;
}
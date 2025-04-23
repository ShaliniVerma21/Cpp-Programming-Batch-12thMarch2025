//Recipe Nutrition Calculator

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm> // For std::sort

using namespace std;

// Enumeration for nutrient types
enum class NutrientType {
    CALORIES,
    PROTEIN,
    FAT,
    CARBOHYDRATES
};

// Structure for an ingredient
struct Ingredient {
    string name; // Name of the ingredient
    double quantity; // Quantity of the ingredient
    NutrientType nutrientType; // Type of nutrient
    double nutrientValue; // Nutritional value per unit of the ingredient

    // Constructor for Ingredient
    Ingredient(string n, double q, NutrientType nt, double nv)
        : name(n), quantity(q), nutrientType(nt), nutrientValue(nv) {}
};

// Base class for Recipe
class Recipe {
protected:
    string recipeName; // Name of the recipe
    vector<Ingredient> ingredients; // Vector to store ingredients

public:
    // Constructor for Recipe
    Recipe(string name) : recipeName(name) {}

    // Function to add an ingredient
    void addIngredient(const Ingredient& ingredient) {
        ingredients.push_back(ingredient);
    }

    // Function to calculate total nutritional value
    double calculateTotalNutrient(NutrientType type) const {
        double total = 0.0;
        for (const auto& ingredient : ingredients) {
            if (ingredient.nutrientType == type) {
                total += ingredient.quantity * ingredient.nutrientValue;
            }
        }
        return total;
    }

    // Function to display recipe details
    void displayRecipe() const {
        cout << "Recipe: " << recipeName << endl;
        cout << "Ingredients:\n";
        for (const auto& ingredient : ingredients) {
            cout << "- " << ingredient.name << ": " << ingredient.quantity << " units, "
                 << "Nutrient Value: " << ingredient.nutrientValue << " per unit\n";
        }
    }

    // Virtual destructor
    virtual ~Recipe() {}
};

// Derived class for Detailed Recipe
class DetailedRecipe : public Recipe {
public:
    // Constructor for DetailedRecipe
    DetailedRecipe(string name) : Recipe(name) {}

    // Function to display nutritional summary
    void displayNutritionalSummary() const {
        cout << "=== Nutritional Summary ===\n";
        cout << "Total Calories: " << fixed << setprecision(2) << calculateTotalNutrient(NutrientType::CALORIES) << " kcal\n";
        cout << "Total Protein: " << fixed << setprecision(2) << calculateTotalNutrient(NutrientType::PROTEIN) << " g\n";
        cout << "Total Fat: " << fixed << setprecision(2) << calculateTotalNutrient(NutrientType::FAT) << " g\n";
        cout << "Total Carbohydrates: " << fixed << setprecision(2) << calculateTotalNutrient(NutrientType::CARBOHYDRATES) << " g\n";
    }
};

int main() {
    // Create an instance of DetailedRecipe
    DetailedRecipe myRecipe("Healthy Salad");

    // Add ingredients to the recipe
    myRecipe.addIngredient(Ingredient("Lettuce", 2.0, NutrientType::CALORIES, 5.0)); // 5 kcal per unit
    myRecipe.addIngredient(Ingredient("Tomato", 1.0, NutrientType::CALORIES, 18.0)); // 18 kcal per unit
    myRecipe.addIngredient(Ingredient("Cucumber", 1.0, NutrientType::CALORIES, 16.0)); // 16 kcal per unit
    myRecipe.addIngredient(Ingredient("Olive Oil", 0.1, NutrientType::FAT, 884.0)); // 884 kcal per unit
    myRecipe.addIngredient(Ingredient("Chicken Breast", 0.2, NutrientType::PROTEIN, 165.0)); // 165 kcal per unit
    myRecipe.addIngredient(Ingredient("Croutons", 0.05, NutrientType::CARBOHYDRATES, 400.0)); // 400 kcal per unit

    // Display recipe details
    myRecipe.displayRecipe();
    cout << endl;

    // Display nutritional summary
    myRecipe.displayNutritionalSummary();

    return 0;
}
//14. Recipe Nutrition Calculator

#include <iostream>
#include <unordered_map>

class Ingredient {
public:
    std::string name;
    double calories;

    Ingredient(std::string n, double cal) : name(n), calories(cal) {}
};

class NutritionCalculator {
private:
    std::unordered_map<std::string, Ingredient> ingredients;

public:
    NutritionCalculator() {
        ingredients["flour"] = Ingredient("flour", 364);
        ingredients["sugar"] = Ingredient("sugar", 387);
        ingredients["butter"] = Ingredient("butter", 717);
    }

    double calculateNutrition(const std::string& ingredientName, double quantity) {
        if (ingredients.find(ingredientName) != ingredients.end()) {
            return ingredients[ingredientName].calories * quantity;
        } else {
            std::cout << "Ingredient not found.\n";
            return 0;
        }
    }
};
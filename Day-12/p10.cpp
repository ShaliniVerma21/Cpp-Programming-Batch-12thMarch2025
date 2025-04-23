//Scientific Calculator

#include <iostream>
#include <cmath> // For mathematical functions
#include <iomanip> // For setting precision
#include <string>

using namespace std;

// Enumeration for operation types
enum class OperationType {
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    EXPONENTIATION,
    SINE,
    COSINE,
    TANGENT,
    LOGARITHM
};

// Structure for a calculation
struct Calculation {
    double operand1; // First operand
    double operand2; // Second operand (used for binary operations)
    OperationType operation; // Type of operation

    // Constructor for Calculation
    Calculation(double op1, double op2, OperationType op)
        : operand1(op1), operand2(op2), operation(op) {}
};

// Base class for Calculator
class Calculator {
public:
    // Function to perform a calculation based on the operation type
    double performCalculation(const Calculation& calc) const {
        switch (calc.operation) {
            case OperationType::ADDITION:
                return calc.operand1 + calc.operand2;
            case OperationType::SUBTRACTION:
                return calc.operand1 - calc.operand2;
            case OperationType::MULTIPLICATION:
                return calc.operand1 * calc.operand2;
            case OperationType::DIVISION:
                if (calc.operand2 != 0) {
                    return calc.operand1 / calc.operand2;
                } else {
                    throw runtime_error("Error: Division by zero.");
                }
            case OperationType::EXPONENTIATION:
                return pow(calc.operand1, calc.operand2);
            case OperationType::SINE:
                return sin(calc.operand1); // operand1 is treated as angle in radians
            case OperationType::COSINE:
                return cos(calc.operand1); // operand1 is treated as angle in radians
            case OperationType::TANGENT:
                return tan(calc.operand1); // operand1 is treated as angle in radians
            case OperationType::LOGARITHM:
                if (calc.operand1 > 0) {
                    return log(calc.operand1); // Natural logarithm
                } else {
                    throw runtime_error("Error: Logarithm of non-positive number.");
                }
            default:
                throw runtime_error("Error: Unknown operation.");
        }
    }

    // Virtual destructor
    virtual ~Calculator() {}
};

// Derived class for ScientificCalculator
class ScientificCalculator : public Calculator {
public:
    // Function to display the result of a calculation
    void displayResult(const Calculation& calc) const {
        try {
            double result = performCalculation(calc);
            cout << "Result: " << fixed << setprecision(4) << result << endl;
        } catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }
};

int main() {
    // Create an instance of ScientificCalculator
    ScientificCalculator sciCalc;

    // Example calculations
    Calculation calc1(5, 3, OperationType::ADDITION);
    sciCalc.displayResult(calc1); // 5 + 3

    Calculation calc2(10, 2, OperationType::SUBTRACTION);
    sciCalc.displayResult(calc2); // 10 - 2

    Calculation calc3(4, 2, OperationType::MULTIPLICATION);
    sciCalc.displayResult(calc3); // 4 * 2

    Calculation calc4(8, 2, OperationType::DIVISION);
    sciCalc.displayResult(calc4); // 8 / 2

    Calculation calc5(2, 3, OperationType::EXPONENTIATION);
    sciCalc.displayResult(calc5); // 2 ^ 3

    Calculation calc6(M_PI / 6, 0, OperationType::SINE); // Sine of 30 degrees
    sciCalc.displayResult(calc6);

    Calculation calc7(M_PI / 3, 0, OperationType::COSINE); // Cosine of 60 degrees
    sciCalc.displayResult(calc7);

    Calculation calc8(M_PI / 4, 0, OperationType::TANGENT); // Tangent of 45 degrees
    sciCalc.displayResult(calc8);

    Calculation calc9(1, 0, OperationType::LOGARITHM); // Logarithm of 1
    sciCalc.displayResult(calc9);

    return 0;
}
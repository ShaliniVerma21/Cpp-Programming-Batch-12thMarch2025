//Example 2: Scoped Enumeration with Underlying Type

#include <iostream>

// Define a scoped enumeration for error codes with an underlying type of int
enum class ErrorCode : int {
    None = 0,       // No error
    NotFound = 404, // Resource not found
    ServerError = 500 // Internal server error
};

int main() {
    // Create a variable of type ErrorCode
    ErrorCode code = ErrorCode::NotFound;

    // Check the value of code
    if (code == ErrorCode::NotFound) {
        std::cout << "Error: Resource not found (404)" << std::endl;
    }

    return 0;
}

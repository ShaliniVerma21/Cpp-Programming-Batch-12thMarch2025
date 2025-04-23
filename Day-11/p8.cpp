/*
 Constructors -->

 In C++, a constructor is a special member function that is automatically called when an object of
 a class is created. Constructors are used to initialize the object's data members and allocate
 resources if necessary. They have the same name as the class and do not have a return type.

 Syntax:

 class ClassName {
public:
    ClassName(); // Default constructor
    ClassName(const ClassName &obj); // Copy constructor
};

 Key Features of Constructors -->
Same Name as Class: The constructor must have the same name as the class.
No Return Type: Constructors do not have a return type, not even void.
Automatic Invocation: Constructors are called automatically when an object is created.
Overloading: You can have multiple constructors in a class with different parameters (constructor overloading).

Types of Constructors -->

1. Default Constructor: A constructor that takes no parameters or has default values for all its parameters.

2. Parameterized Constructor: A constructor that takes parameters to initialize an object with specific values.
*/

class MyClass {
    public:
        MyClass() { // Default constructor
            std::cout << "Default constructor called!" << std::endl;
        }
    };
    
    int main() {
        MyClass obj; // Calls the default constructor
        return 0;
    }
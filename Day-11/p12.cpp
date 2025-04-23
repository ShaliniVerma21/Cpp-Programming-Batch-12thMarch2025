/*
Constructor Initialization List :

You can use an initialization list to initialize data members before the constructor body executes. 
This is particularly useful for initializing const members or reference members.
*/

class MyClass {
    public:
        const int value;
    
        MyClass(int v) : value(v) { // Initialization list
            std::cout << "Constructor called with value: " << value << std::endl;
        }
    };
    
    int main() {
        MyClass obj(10); // Calls the constructor
        return 0;
    }
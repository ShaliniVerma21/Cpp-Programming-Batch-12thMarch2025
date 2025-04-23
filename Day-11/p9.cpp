//Parameterized Constructor

class MyClass {
    public:
        int value;
    
        MyClass(int v) { // Parameterized constructor
            value = v;
            std::cout << "Parameterized constructor called with value: " << value << std::endl;
        }
    };
    
    int main() {
        MyClass obj(10); // Calls the parameterized constructor
        return 0;
    }
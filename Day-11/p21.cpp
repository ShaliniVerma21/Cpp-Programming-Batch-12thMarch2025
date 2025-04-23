//2. Multiple Inheritance (Example: Printer and Scanner)

#include <iostream>
using namespace std;

// Base class 1
class Printer {
public:
    void print() {
        cout << "Printing document." << endl;
    }
};

// Base class 2
class Scanner {
public:
    void scan() {
        cout << "Scanning document." << endl;
    }
};

// Derived class
class MultiFunctionPrinter : public Printer, public Scanner {
};

int main() {
    MultiFunctionPrinter mfp;
    mfp.print(); // From Printer
    mfp.scan();  // From Scanner
    return 0;
}
//Real-World Example: A Resource class that manages a resource.

#include <iostream>
using namespace std;

class Resource {
public:
    Resource() {
        cout << "Resource acquired." << endl;
    }
    ~Resource() {
        cout << "Resource released." << endl;
    }
};

int main() {
    Resource res; // Constructor called
    // Resource will be released when it goes out of scope
    return 0;
}
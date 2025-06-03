// Program 2: Multimap – Multiple values for same key

#include <iostream>
#include <map>
using namespace std;

int main() {
    multimap<string, string> phones;

    phones.insert({"John", "1234"});
    phones.insert({"John", "5678"});

    cout << "John's numbers:\n";
    for(auto &p : phones)
        if(p.first == "John")
            cout << p.second << endl;
    return 0;
}

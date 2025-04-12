//13. Implementing a Hash Table Using Pointers

#include <iostream>
#include <list>
using namespace std;

class HashTable {
    static const int hashSize = 10;
    list<pair<int, string>> table[hashSize];

public:
    void insert(int key, string value) {
        int index = key % hashSize;
        table[index].emplace_back(key, value);
    }

    string search(int key) {
        int index = key % hashSize;
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return "Not found";
    }
};

int main() {
    HashTable ht;
    ht.insert(1, "One");
    ht.insert(2, "Two");
    cout << "Search for key 1: " << ht.search(1) << endl;
    cout << "Search for key 3: " << ht.search(3) << endl;
    return 0;
}
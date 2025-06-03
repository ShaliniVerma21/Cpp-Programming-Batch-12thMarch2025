/*
2. Algorithms

🔹 Definition:
STL Algorithms are predefined functions that perform common operations like searching, sorting, counting, etc., 
on containers like vectors, lists, sets, maps, etc.


🔹 Purpose:
To perform operations on container data without writing custom logic.


🔹 Real-World Examples:
1. Sorting a list of students by their age.
2. Finding the maximum value in a vector of integers.
3. Counting the number of elements in a set.
4. Searching for a specific element in a map.
*/

//Program 1: Sorting a vector
#include <iostream>
#include <vector>
#include <algorithm> // Required for sort
using namespace std;

int main() {
    vector<int> marks = {40, 90, 70, 50};

    // Sort in ascending order
    sort(marks.begin(), marks.end());

    // Display sorted marks
    cout << "Sorted marks: ";
    for(int m : marks)
        cout << m << " ";
    return 0;
}

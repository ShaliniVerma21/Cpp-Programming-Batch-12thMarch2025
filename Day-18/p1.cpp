/*
C++ STL (Standard Template Library)-->

In C++, a standard template library (STL) is a powerful set of template classes and functions that provide general 
data structures and algorithms. It allows developers to use well-optimized implementation of general programming 
components, such as dynamic arrays, linked lists, stacks, queues, sets, maps, and various algorithms.

Several features of STL in C++ are as follows:

Reusability: The code reduces repetition through the reusable components.
Efficiency: It includes adapted, pre-tested algorithms, and containers.
Generic programming: It uses templates to work with any data type.
Consistency: It provides uniform structure in various components, such as containers, algorithms, and recurrences.

C++ STL is mainly classified into four categories:

1. Containers
2. Algorithms
3. Iterators
4. Functors (Function Objects)

Purpose:

1. To save time and effort using pre-defined data structures and algorithms.
2. To promote code reusability, consistency, and performance.
3. To allow generic programming using templates (write once, use with any data type).

Real-World Examples:

1. Social Media Feeds: Use queues to show latest posts.
2. Search engines: Use maps for indexing and fast lookup.
3. E-commerce carts: Use vectors to manage dynamic lists of products.
4. Ranking systems: Use sets to keep sorted unique items.


 1. Containers -->

Containers store and manage collections of data. STL offers various containers like:

Vector – Dynamic array

List – Doubly linked list

Deque – Double-ended queue

Stack, Queue, Priority Queue – Specialized containers

Set, Multiset, Map, Multimap – Associative containers

Purpose:
To store, manage, and access data efficiently using ready-made data structures 
like arrays, lists, queues, sets, maps, etc.

Real-World Examples:

1. Shopping cart: Use a vector to store items.
2. Vector: List of students in a class
3. List: Playlist of songs with next and previous features
4. Deque: Train with bogies attachable/detachable from both ends
5. Stack: Browser’s back button history
6. Queue: People waiting in a line
7. Priority Queue: Task manager showing high priority tasks first
8. Set/Multiset: List of unique usernames (set), or duplicated scores (multiset)
9. Map/Multimap: Phonebook with names and numbers


A. Vector – Dynamic Array
➤ Real-World Use: Storing names of players in a cricket team

*/


//Program 1: Basic vector usage

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers = {10, 20, 30};

    // Adding elements
    numbers.push_back(40);

    // Display elements
    cout << "Vector elements: ";
    for(int num : numbers)
        cout << num << " ";
    return 0;
}



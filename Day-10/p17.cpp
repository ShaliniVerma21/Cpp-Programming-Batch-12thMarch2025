//6. Hotel Booking System

#include <iostream>
#include <vector>

class Room {
public:
    int roomNumber;
    bool isAvailable;

    Room(int num) : roomNumber(num), isAvailable(true) {}
};

class Customer {
public:
    std::string name;
    int id;

    Customer(std::string n, int i) : name(n), id(i) {}
};

class Booking {
private:
    std::vector<Room> rooms;
    std::vector<Customer> customers;

public:
    void addRoom(const Room& room) {
        rooms.push_back(room);
    }

    void addCustomer(const Customer& customer) {
        customers.push_back(customer);
    }

    void bookRoom(int roomNumber, const Customer& customer) {
        for (auto& room : rooms) {
            if (room.roomNumber == roomNumber && room.isAvailable) {
                room.isAvailable = false;
                std::cout << "Room " << roomNumber << " booked for " << customer.name << ".\n";
                return;
            }
        }
        std::cout << "Room not available.\n";
    }
};
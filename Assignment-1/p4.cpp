//Problem 3: Hotel Room Booking System

#include <iostream>
#include <string>
using namespace std;

struct Room {
    int roomNumber;
    string type;
    bool isBooked;
};

void bookRoom(Room &room) {
    if (!room.isBooked) {
        room.isBooked = true;
        cout << "Room " << room.roomNumber << " booked successfully!" << endl;
    } else {
        cout << "Room " << room.roomNumber << " is already booked!" << endl;
    }
}

int main() {
    Room rooms[5] = {
        {101, "Single", false},
        {102, "Double", false},
        {103, "Suite", false},
        {104, "Deluxe", false},
        {105, "Family", false}
    };

    int choice;
    cout << "Available Rooms:\n";
    for (Room room : rooms) {
        cout << "Room Number: " << room.roomNumber << ", Type: " << room.type << ", Status: " << (room.isBooked ? "Booked" : "Available") << endl;
    }

    cout << "Enter room number to book: ";
    cin >> choice;
    for (Room &room : rooms) {
        if (room.roomNumber == choice) {
            bookRoom(room);
            break;
        }
    }
    return 0;
}
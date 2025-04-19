//11. Travel Booking System

#include <iostream>
#include <vector>

class Destination {
public:
    std::string name;
    double price;

    Destination(std::string n, double p) : name(n), price(p) {}
};

class Traveler {
public:
    std::string name;

    Traveler(std::string n) : name(n) {}
};

class Booking {
private:
    std::vector<Destination> destinations;

public:
    void addDestination(const Destination& destination) {
        destinations.push_back(destination);
    }

    void bookDestination(const Traveler& traveler, const std::string& destinationName) {
        for (const auto& destination : destinations) {
            if (destination.name == destinationName) {
                std::cout << traveler.name << " booked a trip to " << destination.name << " for $" << destination.price << ".\n";
                return;
            }
        }
        std::cout << "Destination not found.\n";
    }
};
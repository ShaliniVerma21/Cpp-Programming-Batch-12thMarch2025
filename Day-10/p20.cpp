//9. Fitness Tracker

#include <iostream>
#include <vector>

class Workout {
public:
    std::string type;
    int duration; // in minutes

    Workout(std::string t, int d) : type(t), duration(d) {}
};

class FitnessTracker {
private:
    std::vector<Workout> workouts;

public:
    void addWorkout(const Workout& workout) {
        workouts.push_back(workout);
    }

    void displayWorkouts() const {
        for (const auto& workout : workouts) {
            std::cout << "Workout: " << workout.type << ", Duration: " << workout.duration << " minutes\n";
        }
    }
};
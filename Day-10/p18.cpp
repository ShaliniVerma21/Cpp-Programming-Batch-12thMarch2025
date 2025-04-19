//7. Movie Ticket Booking System

#include <iostream>
#include <vector>

class Movie {
public:
    std::string title;
    int availableTickets;

    Movie(std::string t, int tickets) : title(t), availableTickets(tickets) {}
};

class Booking {
private:
    std::vector<Movie> movies;

public:
    void addMovie(const Movie& movie) {
        movies.push_back(movie);
    }

    void bookTicket(const std::string& title) {
        for (auto& movie : movies) {
            if (movie.title == title && movie.availableTickets > 0) {
                movie.availableTickets--;
                std::cout << "Ticket booked for " << movie.title << ".\n";
                return;
            }
        }
        std::cout << "No tickets available for " << title << ".\n";
    }
};
// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

// Abstract class with a virtual destructor
class Machine {
public:
    virtual void travel() = 0;  // Pure virtual function

    virtual ~Machine() {
        cout << "Machine destructor called." << endl;
    }
};

// TimeMachine class inheriting from Machine
class TimeMachine : public Machine {
public:
    // Default constructor
    TimeMachine() {
        powerLevel = 0;
        cout << "TimeMachine default constructor called." << endl;
    }

    // Parameterized constructor
    TimeMachine(int level) {
        powerLevel = level;
        cout << "TimeMachine parameterized constructor called." << endl;
    }

    // Destructor
    ~TimeMachine() {
        cout << "TimeMachine destructor called." << endl;
    }

    // Setter and Getter for power level
    void setPowerLevel(int level) {
        powerLevel = level;
    }

    int getPowerLevel() const {
        return powerLevel;
    }

    // Overriding the pure virtual function
    void travel() override {
        cout << "TimeMachine traveling with power level " << powerLevel << "!" << endl;
    }

private:
    int powerLevel;  // Power level of the time machine
};

// TravelLog class - Manages travel statistics (SRP Example)
class TravelLog {
public:
    static void incrementTravel() {
        totalTravels++;
    }

    static int getTotalTravels() {
        return totalTravels;
    }

private:
    static int totalTravels;  // Static variable to track total travels
};

int TravelLog::totalTravels = 0;  // Initializing static variable

// Traveler class
class Traveler {
public:
    // Constructor with parameters for traveler name and destination
    Traveler(string travelerName, string dest) : name(travelerName), destination(dest) {
        cout << "Traveler constructor called for " << name << "." << endl;
    }

    // Destructor
    ~Traveler() {
        cout << "Traveler destructor called for " << name << "." << endl;
    }

    // Displaying traveler information
    void displayTravelerInfo() const {
        cout << "Traveler: " << name << ", Destination: " << destination << endl;
    }

private:
    string name;        // Name of the traveler
    string destination; // Destination of the traveler
};

// TravelerManager class - Handles traveler statistics (SRP Example)
class TravelerManager {
public:
    static void addTraveler() {
        totalTravelers++;
    }

    static int getTotalTravelers() {
        return totalTravelers;
    }

private:
    static int totalTravelers;  // Static variable to track travelers
};

int TravelerManager::totalTravelers = 0;  // Initializing static variable

int main() {
    // Creating Traveler objects
    Traveler travelers[2] = {
        Traveler("John Doe", "Future - 2050"),
        Traveler("Alice Smith", "Past - 1800")
    };

    // Registering travelers
    TravelerManager::addTraveler();
    TravelerManager::addTraveler();

    // Creating a TimeMachine object and logging travels
    TimeMachine tm(100);
    tm.travel();
    TravelLog::incrementTravel();

    // Displaying total travels and travelers
    cout << "Total Travels: " << TravelLog::getTotalTravels() << endl;
    cout << "Total Travelers: " << TravelerManager::getTotalTravelers() << endl;

    return 0;
}

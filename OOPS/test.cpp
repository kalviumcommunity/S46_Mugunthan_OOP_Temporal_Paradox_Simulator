#include <iostream>
using namespace std;

class TimeMachine {
public:
    void setPowerLevel(int level) { 
        powerLevel = level;
    }

    int getPowerLevel() { 
        return powerLevel;
    }

    void travel() { 
        cout << "TimeMachine traveling through time with power level " << powerLevel << "!" << endl;
    }

private:
    int powerLevel; 
};

class Traveler {
public:
    void setName(string travelerName) { 
        name = travelerName;
    }

    string getName() { 
        return name;
    }

    void setDestination(string dest) { 
        destination = dest;
    }

    string getDestination() { 
        return destination;
    }

    void displayTravelerInfo() {
        cout << "Traveler: " << name << ", Destination: " << destination << endl;
    }

private:
    string name; 
    string destination; 
};

int main() {

    TimeMachine tm;
    tm.setPowerLevel(100);
    cout << "Power Level: " << tm.getPowerLevel() << endl;    tm.travel(); 

    // Creating an object of Time-Traveler
    Traveler traveler;
    traveler.setName("John Doe");
    traveler.setDestination("Future - 2050"); 
    traveler.displayTravelerInfo(); 

    return 0;
}

#include <iostream>
using namespace std;

class TimeMachine {
public:
    TimeMachine() {
        powerLevel = 0; 
    }

    TimeMachine(int level) {
        this->powerLevel = level; 
    }

    void setPowerLevel(int level) { 
        this->powerLevel = level; 
    }

    int getPowerLevel() { 
        return this->powerLevel; 
    }

    void travel() { 
        cout << "TimeMachine traveling through time with power level " << this->powerLevel << "!" << endl; 
    }

private:
    int powerLevel; 
};

class Traveler {
public:
    Traveler() {
        name = "";        
        destination = "";  
    }

    Traveler(string travelerName, string dest) {
        this->name = travelerName;        
        this->destination = dest;          
    }

    void setName(string travelerName) { 
        this->name = travelerName; 
    }

    void setDestination(string dest) { 
        this->destination = dest; 
    }

    string getName() { 
        return this->name; 
    }

    string getDestination() { 
        return this->destination; 
    }

    void displayTravelerInfo() {
        cout << "Traveler: " << this->name << ", Destination: " << this->destination << endl; 
    }

private:
    string name; 
    string destination; 
};

int main() {
   Traveler travelers[3] = {
        Traveler("John Doe", "Future - 2050"),
        Traveler("Alice Smith", "Past - 1800"),
        Traveler("Bob Johnson", "Present - 2024")
    };
    TimeMachine tm;
    tm.setPowerLevel(100);
    cout << "Power Level: " << tm.getPowerLevel() << endl;    
    tm.travel(); 
    for (int i = 0; i < 3; ++i) {
        travelers[i].displayTravelerInfo();
    }
    return 0;
}

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
        numberOfTravels++; 
    }
    
    static int getNumberOfTravels(){
        return numberOfTravels;
    }

private:
    int powerLevel; 
    static int numberOfTravels;
};

int TimeMachine::numberOfTravels = 0; 

class Traveler {
public:
    Traveler() {
        name = "";        
        destination = "";  
        numberOfTravelers++; 
    }

    Traveler(string travelerName, string dest) {
        this->name = travelerName;        
        this->destination = dest;          
        numberOfTravelers++; 
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

    static int getNumberOfTravelers(){
        return numberOfTravelers;
    }

private:
    string name; 
    string destination; 
    static int numberOfTravelers;
};

int Traveler::numberOfTravelers = 0; 
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

    Traveler* traveler1 = new Traveler("Mugunthan", "Past-2015");
    traveler1->displayTravelerInfo();
    delete traveler1; 
    int totalTravels = TimeMachine::getNumberOfTravels(); 
    int totalTravelers = Traveler::getNumberOfTravelers(); 
    cout << "Total Travels: " << totalTravels << endl;
    cout << "Total Travelers: " << totalTravelers << endl;

    return 0;
}

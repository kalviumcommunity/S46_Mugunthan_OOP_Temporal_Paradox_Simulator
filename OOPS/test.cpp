#include <iostream>
using namespace std;

class Machine {
public:
    virtual void travel() = 0;

    virtual ~Machine() {
        cout << "Machine destructor called." << endl;
    }
};

class TimeMachine : public Machine {
public:
    TimeMachine() {
        powerLevel = 0;
        cout << "TimeMachine default constructor called." << endl;
    }

    TimeMachine(int level) {
        powerLevel = level;
        cout << "TimeMachine parameterized constructor called." << endl;
    }

    ~TimeMachine() {
        cout << "TimeMachine destructor called." << endl;
    }

    void setPowerLevel(int level) {
        powerLevel = level;
    }

    int getPowerLevel() {
        return powerLevel;
    }

    void travel() override {
        cout << "TimeMachine traveling with power level " << powerLevel << "!" << endl;
        numberOfTravels++;
    }

    static int getNumberOfTravels() {
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
        name = "Unknown";
        destination = "Unknown";
        cout << "Traveler default constructor called." << endl;
        numberOfTravelers++;
    }

    Traveler(string travelerName, string dest) {
        name = travelerName;
        destination = dest;
        cout << "Traveler parameterized constructor called." << endl;
        numberOfTravelers++;
    }

    ~Traveler() {
        cout << "Traveler destructor called for " << name << "." << endl;
    }

    void setName(string travelerName) {
        name = travelerName;
    }

    void setDestination(string dest) {
        destination = dest;
    }

    string getName() {
        return name;
    }

    string getDestination() {
        return destination;
    }

    void displayTravelerInfo() {
        cout << "Traveler: " << name << ", Destination: " << destination << endl;
    }

    static int getNumberOfTravelers() {
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

    Traveler* traveler1 = new Traveler("Mugunthan", "Past - 2015");
    traveler1->displayTravelerInfo();
    delete traveler1;

    int totalTravels = TimeMachine::getNumberOfTravels();
    int totalTravelers = Traveler::getNumberOfTravelers();
    cout << "Total Travels: " << totalTravels << endl;
    cout << "Total Travelers: " << totalTravelers << endl;

    return 0;
}

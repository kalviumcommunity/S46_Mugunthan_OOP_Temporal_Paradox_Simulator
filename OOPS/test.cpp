#include <iostream>
using namespace std;

class Machine {
public:
    virtual void travel() = 0;

    virtual ~Machine() {
        cout << "Machine destructor called." << endl;
    }
};

// Multilevel inheritance: TimeMachine inherits from Machine, AdvancedTimeMachine inherits from TimeMachine
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

// Multilevel inheritance: AdvancedTimeMachine extends TimeMachine
class AdvancedTimeMachine : public TimeMachine {
public:
    AdvancedTimeMachine(int level, string tech) : TimeMachine(level) {
        technology = tech;
        cout << "AdvancedTimeMachine constructor called." << endl;
    }

    void showTechnology() {
        cout << "Using advanced technology: " << technology << endl;
    }

private:
    string technology;
};

// Hierarchical inheritance: Traveler and Scientist inherit from a common base class "Person"
class Person {
public:
    Person(string name) {
        this->name = name;
    }

    string getName() {
        return name;
    }

    virtual void showRole() = 0;

protected:
    string name;
};

class Traveler : public Person {
public:
    Traveler(string travelerName, string dest) : Person(travelerName) {
        destination = dest;
        cout << "Traveler constructor called." << endl;
        numberOfTravelers++;
    }

    ~Traveler() {
        cout << "Traveler destructor called for " << name << "." << endl;
    }

    void displayTravelerInfo() {
        cout << "Traveler: " << name << ", Destination: " << destination << endl;
    }

    void showRole() override {
        cout << name << " is a traveler." << endl;
    }

    static int getNumberOfTravelers() {
        return numberOfTravelers;
    }

private:
    string destination;
    static int numberOfTravelers;
};

int Traveler::numberOfTravelers = 0;

class Scientist : public Person {
public:
    Scientist(string scientistName, string field) : Person(scientistName) {
        researchField = field;
        cout << "Scientist constructor called." << endl;
    }

    void displayResearch() {
        cout << name << " is researching " << researchField << "." << endl;
    }

    void showRole() override {
        cout << name << " is a scientist." << endl;
    }

private:
    string researchField;
};

int main() {
    Traveler travelers[2] = {
        Traveler("John Doe", "Future - 2050"),
        Traveler("Alice Smith", "Past - 1800")
    };

    AdvancedTimeMachine atm(200, "Quantum Flux Drive");
    atm.travel();
    atm.showTechnology();

    for (int i = 0; i < 2; ++i) {
        travelers[i].displayTravelerInfo();
        travelers[i].showRole();
    }

    Scientist scientist("Dr. Brown", "Time Paradoxes");
    scientist.displayResearch();
    scientist.showRole();

    int totalTravels = TimeMachine::getNumberOfTravels();
    int totalTravelers = Traveler::getNumberOfTravelers();

    cout << "Total Travels: " << totalTravels << endl;
    cout << "Total Travelers: " << totalTravelers << endl;

    return 0;
}

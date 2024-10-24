#include <iostream>
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
        numberOfTravels++;
    }

    // Static method to get the total number of travels
    static int getNumberOfTravels() {
        return numberOfTravels;
    }

private:
    int powerLevel;                // Power level of the time machine
    static int numberOfTravels;     // Static variable to track travels
};

int TimeMachine::numberOfTravels = 0;  // Initializing static variable

// AdvancedTimeMachine class inheriting from TimeMachine
class AdvancedTimeMachine : public TimeMachine {
public:
    // Constructor with parameters for power level and technology
    AdvancedTimeMachine(int level, string tech) : TimeMachine(level) {
        technology = tech;
        cout << "AdvancedTimeMachine constructor called." << endl;
    }

    // Displaying the advanced technology used
    void showTechnology() const {
        cout << "Using advanced technology: " << technology << endl;
    }

private:
    string technology;  // Technology used in the advanced time machine
};

// Person class with a pure virtual function
class Person {
public:
    Person(string name) : name(name) {}

    string getName() const {
        return name;
    }

    virtual void showRole() = 0;  // Pure virtual function

protected:
    string name;  // Name of the person
};

// Traveler class inheriting from Person
class Traveler : public Person {
public:
    // Constructor with parameters for traveler name and destination
    Traveler(string travelerName, string dest) : Person(travelerName), destination(dest) {
        cout << "Traveler constructor called." << endl;
        numberOfTravelers++;
    }

    // Destructor
    ~Traveler() {
        cout << "Traveler destructor called for " << name << "." << endl;
    }

    // Displaying traveler information
    void displayTravelerInfo() const {
        cout << "Traveler: " << name << ", Destination: " << destination << endl;
    }

    // Overriding the pure virtual function
    void showRole() override {
        cout << name << " is a traveler." << endl;
    }

    // Static method to get the total number of travelers
    static int getNumberOfTravelers() {
        return numberOfTravelers;
    }

private:
    string destination;  // Destination of the traveler
    static int numberOfTravelers;  // Static variable to track travelers
};

int Traveler::numberOfTravelers = 0;  // Initializing static variable

// Scientist class inheriting from Person
class Scientist : public Person {
public:
    // Constructor with parameters for scientist name and field of research
    Scientist(string scientistName, string field) : Person(scientistName), researchField(field) {
        cout << "Scientist constructor called." << endl;
    }

    // Displaying the research field
    void displayResearch() const {
        cout << name << " is researching " << researchField << "." << endl;
    }

    // Overriding the pure virtual function
    void showRole() override {
        cout << name << " is a scientist." << endl;
    }

private:
    string researchField;  // Field of research
};

int main() {
    // Creating Traveler objects
    Traveler travelers[2] = {
        Traveler("John Doe", "Future - 2050"),
        Traveler("Alice Smith", "Past - 1800")
    };

    // Creating an AdvancedTimeMachine object
    AdvancedTimeMachine atm(200, "Quantum Flux Drive");
    atm.travel();  // Calling travel method
    atm.showTechnology();  // Displaying technology

    // Displaying traveler information and roles
    for (int i = 0; i < 2; ++i) {
        travelers[i].displayTravelerInfo();
        travelers[i].showRole();
    }

    // Creating a Scientist object
    Scientist scientist("Dr. Brown", "Time Paradoxes");
    scientist.displayResearch();  // Displaying research field
    scientist.showRole();  // Displaying role

    // Displaying total travels and travelers
    int totalTravels = TimeMachine::getNumberOfTravels();
    int totalTravelers = Traveler::getNumberOfTravelers();

    cout << "Total Travels: " << totalTravels << endl;
    cout << "Total Travelers: " << totalTravelers << endl;

    return 0;
}

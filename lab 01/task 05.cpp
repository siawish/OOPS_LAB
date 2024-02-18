#include <iostream>
#include <string>
#include <vector>

using namespace std;

class House;

class Person {
public:
    string name;
    int age;
    House* residence; 

    void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Dog {
public:
    string name;
    string breed;
    int age;

    void displayDetails() {
        cout << "Dog Name: " << name << "\nBreed: " << breed << "\nAge: " << age << endl;
    }
};

class House {
public:
    vector<Person> residents;
    vector<Dog> dogs;

    void displayHouseInfo() {
        cout << "House Details:" << endl;
        cout << "Residents:" << endl;
        for (Person& resident : residents) {
            resident.displayDetails();
        }
        cout << "\nDogs:" << endl;
        for (Dog& dog : dogs) {
            dog.displayDetails();
        }
        cout << "----------------\n";
    }
};

class Neighborhood {
public:
    vector<House> houses;

    void addHouse(const House& newHouse) {
        houses.push_back(newHouse);
    }

    void displayNeighborhoodInfo() {
        cout << "Neighborhood Information:" << endl;
        for (size_t i = 0; i < houses.size(); i++) {
            cout << "House " << i + 1 << ":\n";
            houses[i].displayHouseInfo();
        }
    }
};

int main() {
    Neighborhood neighborhood;

    int numHouses;
    cout << "Enter the number of houses in the neighborhood: ";
    cin >> numHouses;

    for (int i = 0; i < numHouses; i++) {
        House house;

        int numResidents;
        cout << "\nEnter the number of residents in House " << i + 1 << ": ";
        cin >> numResidents;

        for (int j = 0; j < numResidents; j++) {
            Person resident;

            cout << "Enter resident " << j + 1 << "'s name: ";
            cin >> ws;
            getline(cin, resident.name);

            cout << "Enter resident " << j + 1 << "'s age: ";
            cin >> resident.age;

            house.residents.push_back(resident);
        }

        int numDogs;
        cout << "\nEnter the number of dogs in House " << i + 1 << ": ";
        cin >> numDogs;

        for (int k = 0; k < numDogs; k++) {
            Dog dog;

            cout << "Enter dog " << k + 1 << "'s name: ";
            cin.ignore();
            getline(cin, dog.name);

            cout << "Enter dog " << k + 1 << "'s breed: ";
            getline(cin, dog.breed);

            cout << "Enter dog " << k + 1 << "'s age: ";
            cin >> dog.age;

            house.dogs.push_back(dog);
        }

        neighborhood.addHouse(house);
    }

    neighborhood.displayNeighborhoodInfo();

    return 0;


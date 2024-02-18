#include<iostream>
 #include<string>
 using namespace std; 
#include <iostream>
#include <string>
using namespace std;

class Dog {
public:
    string name;
    string breed;
    int age;

    void bark() {
        cout << name << " says Woof!" << endl;
    }

    void displayDetails() {
        cout << "Dog Name: " << name << "\nBreed: " << breed << "\nAge: " << age << endl;
    }
};

class Person {
public:
    string name;
    int age;
    Dog pet;

    void DisplayDogInfo() {
        cout << "My name is " << name << "\nMy dog's name is " << pet.name << "\nIts breed is " << pet.breed << "\nAnd is " << pet.age << " years old." << endl;
    }

    void introducePet() {
        cout << "My dog's name is " << pet.name << endl;
        pet.bark();
    }
};

class House {
public:
    Person people[3];
    int num_people;

    House() {
        num_people = 0;
    }

    void addPeople(Person& newPerson) {
        if (num_people < 3) {
            people[num_people++] = newPerson;
        }
    }

    void displayPersons() {
        cout << "No. of People in the House" << endl;
        for (int i = 0; i < num_people; i++) {
            cout << "Name: " << people[i].name << ", Age: " << people[i].age << endl;
        }
    }

    void displayDogDetails() {
        cout << "\nDog Details:" << endl;
        for (int i = 0; i < num_people; i++) {
            cout << "Details for " << people[i].name << "'s dog:" << endl;
            people[i].pet.displayDetails();
            cout << "------" << endl;
        }
    }
};

int main() {
    House house;

    // Person 1
    Person person1;
    person1.name = "Siawish";
    person1.age = 18;
    person1.pet.name = "Buddy";
    person1.pet.breed = "American Shepherd";
    person1.pet.age = 3;
    house.addPeople(person1);

    // Person 2
    Person person2;
    person2.name = "Arham";
    person2.age = 19;
    person2.pet.name = "Leo";
    person2.pet.breed = "Golden Retriever";
    person2.pet.age = 4;
    house.addPeople(person2);

    // Person 3
    Person person3;
    person3.name = "Amaan";
    person3.age = 20;
    person3.pet.name = "Rocky";
    person3.pet.breed = "German Shepherd";
    person3.pet.age = 5;
    house.addPeople(person3);

    house.displayPersons();
    house.displayDogDetails();

    return 0;
}


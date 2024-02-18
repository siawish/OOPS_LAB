#include<iostream>
#include<string>
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

    void changePet(Dog newPet) {
        cout << name << " is introducing a new pet." << endl;
        pet = newPet;
        cout << "My new dog's name is " << pet.name << "\nBreed is " << pet.breed << "\nAge is " << pet.age << endl;
    }
};

int main() {
    Person person1;
    cout << "Enter person's name: ";
    getline(cin, person1.name);
    cout << "Enter person's age: ";
    cin >> person1.age;

    cin.ignore(); // Ignore the newline character left in the buffer

    Dog oldDog;
    cout << "Enter dog's name: ";
    getline(cin, oldDog.name);
    cout << "Enter dog's breed: ";
    getline(cin, oldDog.breed);
    cout << "Enter dog's age: ";
    cin >> oldDog.age;

    person1.pet = oldDog;

    cout << "\nOriginal Dog Details:" << endl;
    person1.DisplayDogInfo();

    Dog newDog;
    cin.ignore(); // Ignore the newline character left in the buffer
    cout << "\nEnter new dog's name: ";
    getline(cin, newDog.name);
    cout << "Enter new dog's breed: ";
    getline(cin, newDog.breed);
    cout << "Enter new dog's age: ";
    cin >> newDog.age;

    person1.changePet(newDog);

    cout << "\nUpdated Dog Details:" << endl;
    person1.DisplayDogInfo();

    return 0;
}


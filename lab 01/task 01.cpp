#include<iostream>
#include<string>
using namespace std;

class Dog {
public:
    string name;
    string Breed;
    int age;

    void bark() {
        cout << name << " says Woof!" << endl;
    }
};

class Person {
public:
    string name;
    int age;
    Dog pet;

    void DisplayDogInfo() {
        cout << "My name is " << name << "\nMy dog's name is " << pet.name << "\nIts breed is " << pet.Breed << "\nAnd is " << pet.age << " years old." << endl;
    }

    void introducePet() {
        cout << "My dog's name is " << pet.name << endl;
        pet.bark();
    }
};


int main() {
    Person person1;
    person1.name = "Siawish";
    person1.age = 18;
    person1.pet.name = "Buddy";
    person1.pet.age = 15;
    person1.pet.Breed = "American Shepherd";

    person1.DisplayDogInfo();
    person1.pet.bark();
    return 0;
}


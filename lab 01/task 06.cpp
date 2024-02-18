#include <iostream>
#include <string>

using namespace std;

class Vehicle {
private:
    string make;
    string model;
    int year;
    int mileage;

public:
  
    Vehicle(string mk, string mdl, int yr) : make(mk), model(mdl), year(yr), mileage(0) {}

    void setMake(string mk) {
        make = mk;
    }
    
    void setModel(string mdl) {
        model = mdl;
    }
    
    void setYear(int yr) {
        year = yr;
    }
    
    void setMileage(int miles) {
        mileage = miles;
    }
    void displayVehicleInfo() {
        cout << "Make: " << make << ", Model: " << model << ", Year: " << year << ", Mileage: " << mileage << " miles" << endl;
    }
    bool needsServicing() {
        return mileage >= 10000;
    }
};

int main() { 
    Vehicle myVehicle("Toyota", "Corolla", 2020);
    
    myVehicle.setMileage(1000);
    
    myVehicle.displayVehicleInfo();

    if (myVehicle.needsServicing()) {
        cout << "Car needs servicing." << endl;
    } else {
        cout << "Car is in good condition." << endl;
    }

    // Update vehicle information
    myVehicle.setModel("Camry");
    myVehicle.setYear(2022);
    myVehicle.setMileage(12000);

    myVehicle.displayVehicleInfo();

    if (myVehicle.needsServicing()) {
        cout << "Car needs servicing." << endl;
    } else {
        cout << "Car is in good condition." << endl;
    }

    return 0;
}


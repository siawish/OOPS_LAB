#pragma once 
#include<iostream>
using namespace std;
#include "Plant.h"

class Bush : public Plant {
private:
    double height;
    double growthRate;
public:
    Bush(double initialHeight) : height(initialHeight), growthRate(0.7) {}
    void grow() override {
        height += growthRate;
    }
    void displayHeight() const override {
        cout << "Bush height: " << height << " cm" << endl;
    }
}; 


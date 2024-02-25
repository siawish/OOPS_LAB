#pragma once
#include<iostream>
using namespace std;
#include "Plant.h"

class Flower : public Plant {
private:
    double height;
    double growthRate;
public:
    Flower(double initialHeight) : height(initialHeight), growthRate(0.5) {}
    void grow() override {
        height += growthRate;
    }
    void displayHeight() const override {
        cout << "Flower height: " << height << " cm" << endl;
    }
};


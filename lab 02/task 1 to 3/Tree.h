#pragma once
#include<iostream>
using namespace std;
#include "Plant.h"

class Tree : public Plant {
private:
    double height;
    double growthRate;
public:
    Tree(double initialHeight) : height(initialHeight), growthRate(0.2) {}
    void grow() override {
        height += growthRate;
    }
    void displayHeight() const override {
        cout << "Tree height: " << height << " cm" << endl;
    }
};


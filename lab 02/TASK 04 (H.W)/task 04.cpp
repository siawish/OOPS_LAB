#include "Plant.h"
#include "Flower.h"
#include "Tree.h"
#include "Bush.h"

int main() {

    Flower flower(10.0);
    Tree tree(20.0);
    Bush bush(15.0);

    for (int day = 1; day <= 30; ++day) {
        flower.grow();
        tree.grow();
        bush.grow();
    }
    flower.displayHeight();
    tree.displayHeight();
    bush.displayHeight();

    return 0;
}


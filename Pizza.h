#pragma once
#include "LeakedObjectDetector.h"

struct Pizza
{
    Pizza();
    ~Pizza();
    int numOfToppings;
    int diameter;
    double sliceSize;
    double calculateSliceSize(int slices);
    Pizza makePizza();
    void distributeToppings(int toppings, int slices);
    void properties();
    JUCE_LEAK_DETECTOR(Pizza)
};

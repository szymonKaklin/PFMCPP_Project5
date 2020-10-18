#include "LeakedObjectDetector.h"

struct Airliner
{
    Airliner();
    ~Airliner();
    int engines = 2;
    int capacity = 416;
    int fuelCapacity = 183380;
    char company = 'b';
    void checkFuelAmount();
    bool isTakeoffReady(double fuelAmount);
    int beginBoarding(int passengers);
    void status();
    JUCE_LEAK_DETECTOR(Airliner)
};

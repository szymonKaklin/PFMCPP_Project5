#include "LeakedObjectDetector.h"
#include "Airliner.h"
#include "Pizza.h"
#include "Guitar.h"

struct Party
{
    Party();
    ~Party();
    Airliner plane;
    Pizza pizza;
    Guitar guitar;

    void increasePizzaDiameter();
    void startParty(double fuel);
    void partyPrep();
    JUCE_LEAK_DETECTOR(Party)
};

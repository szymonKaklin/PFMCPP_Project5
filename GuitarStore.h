#include "LeakedObjectDetector.h"
#include "Guitar.h"
#include "Airliner.h"

struct GuitarStore 
{
    GuitarStore();
    ~GuitarStore();
    Guitar guitar;
    Guitar::Strings strings;
    Airliner plane;

    void modifyGuitar(double gauge, char model, int frets, int stringNum);
    void loadPlane(int guitarNum, int passangers);
    void info();
    JUCE_LEAK_DETECTOR(GuitarStore)
};

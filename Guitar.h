#pragma once
#include "LeakedObjectDetector.h"

struct Guitar
{
    Guitar();
    ~Guitar();
    int stringNum = 7;
    int fretNum = 24;
    char model = 'i';
    bool tuned = false;

    struct Strings
    {
        Strings();
        double gauge;
    };

    void restringGuitar(Strings strings);
    void tune();
    void info();
    JUCE_LEAK_DETECTOR(Guitar)
};

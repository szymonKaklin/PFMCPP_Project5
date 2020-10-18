#include <iostream>
#include "Guitar.h"

Guitar::Guitar() { std::cout << "Constructing Guitar" << std::endl;  } 
Guitar::Strings::Strings()
{
    gauge = 0.011;
}

Guitar::~Guitar() { std::cout << "Destroying Guitar" << std::endl; }

void Guitar::info()
{
    std::cout << "Number of frets on guitar: " << this->fretNum << "\nNumber of strings: " << this->stringNum << std::endl;
}

void Guitar::restringGuitar(Guitar::Strings strings)
{
    std::cout << "Guitar of model " << model << ", with string number: "<< stringNum << ", re-strung using strings of gauge: "<< strings.gauge << "\n" << std::endl;
}

void Guitar::tune()
{
    std::cout << "\nTuning Guitar..." << std::endl;
    for ( int i = 0; i < stringNum; ++i )
    {
        std::cout << "Tuned string " << i+1 << std::endl;
    }
    tuned = true;
    std::cout << "Guitar Tuned!" << std::endl;
}

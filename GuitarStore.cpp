#include <iostream>

#include "Guitar.h"
#include "Airliner.h"

#include "GuitarStore.h"

GuitarStore::GuitarStore() { std::cout << "Constructing Guitar Store " << std::endl; }
    
GuitarStore::~GuitarStore() { std::cout << "Destroying GuitarStore" << std::endl; }

void GuitarStore::info()
{
    std::cout << "Store Guitar info:\n Model:" << this->guitar.model << "\n String number: "<< this->guitar.stringNum << "\n Fret number: "<< this->guitar.fretNum << "\nModified to: " << std::endl;
}

void GuitarStore::modifyGuitar(double gauge, char model, int frets, int stringNum)
{
    std::cout << "Modifying guitar:\n Model:" << guitar.model << "\n String number: "<< guitar.stringNum << "\n Fret number: "<< guitar.fretNum << "\nModified to: " << std::endl;

    strings.gauge = gauge;
    guitar.model = model;
    guitar.fretNum = frets;
    guitar.stringNum = stringNum;
    
    guitar.restringGuitar(strings);
}

void GuitarStore::loadPlane(int guitarNum, int passengers)
{
    plane.beginBoarding(passengers);
    while( (plane.capacity && guitarNum) > 0 )
    {
        --plane.capacity;
        --guitarNum;
    }
    std::cout << "Guitars Loaded!\n Leftover guitars: " << guitarNum << "\n Empty Seats: " << plane.capacity << std::endl; 
}

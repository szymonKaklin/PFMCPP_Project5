#include <iostream>
#include "Party.h"

Party::Party() { std::cout << "Constructing Party" << std::endl; }
Party::~Party() { std::cout << "Destroying Party" << std::endl; }

void Party::partyPrep()
{
    std::cout << std::boolalpha << "Running party checks: \n Guitar tuned: " << this->guitar.tuned << "\n Plane capacity: " << this->plane.capacity << "\n Pizza slice size > 0.5 per person? : " << (this->pizza.calculateSliceSize(this->plane.capacity) >= 0.5) << std::endl;
}

void Party::increasePizzaDiameter()
{
    while( pizza.calculateSliceSize(plane.capacity) < 0.5 )
    {
        ++pizza.diameter;
    }
    std::cout << "Final Pizza diameter: " << pizza.diameter << std::endl; 
}

void Party::startParty(double fuel)
{
    if( plane.isTakeoffReady(fuel) && guitar.tuned && pizza.calculateSliceSize(plane.capacity) >= 0.5)
    {
        std::cout << "Party can start! Guitar tuned, pizza per person OK, fuel OK" << std::endl;
    }
    else
    {
        std::cout << "not enough preperations" << std::endl;
    }
}

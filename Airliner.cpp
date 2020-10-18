#include <iostream>
#include "Airliner.h"

Airliner::Airliner() { std::cout << "Constructing Airliner" << std::endl; }

Airliner::~Airliner() { std::cout << "Destroying Airliner" << std::endl; }

void Airliner::status()
{
    std::cout << std::boolalpha << "Airliner capacity: " << this->capacity << "\nAirliner Fuel: " << this->fuelCapacity << "\nIs Airliner takeoff ready: " << this->isTakeoffReady(190000) << std::endl;
}

void Airliner::checkFuelAmount()
{
    std::cout << "Fuel amount: " << fuelCapacity << std::endl;
}

bool Airliner::isTakeoffReady(double fuelAmount)
{
    return fuelAmount > fuelCapacity;
}

int Airliner::beginBoarding(int passengers)
{
    while( passengers > 0 )
    {
        --capacity;
        if( capacity < 0 )
        {
            std::cout << "Plane Full! Leftover Passengers: " << passengers << std::endl;
            return 0;
        }
        --passengers;
    }
    std::cout << "Boarding Complete! Empty Seats: " << capacity << std::endl;
    return 1;
}

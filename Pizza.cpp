#include <iostream>
#include "Pizza.h"

Pizza::Pizza() : numOfToppings(1), diameter(14), sliceSize(4.5) { std::cout << "Constructing Pizza" << std::endl;  } 

Pizza::~Pizza() { std::cout << "Destroying Pizza" << std::endl; }

void Pizza::properties()
{
    std::cout << "Pizza diameter is: " << this->diameter << "\nSlice size is: " << this->calculateSliceSize(6) << std::endl;
}

double Pizza::calculateSliceSize(int slices)
{
    return diameter / (sliceSize * slices);
}

Pizza Pizza::makePizza()
{
    Pizza pepperoni;
    std::cout << "Pizza made!" << std::endl;
    return pepperoni;
}

void Pizza::distributeToppings(int toppings, int slices)
{
    int tps = toppings/slices;
    for( int i = 0; i < slices; ++i )
    {
        std::cout << "Added " << tps << " toppings to slice" << std::endl;
    }
    int leftover = toppings % slices;
    std::cout << "Leftover toppings: " << leftover << std::endl;
    numOfToppings -= 1;
    std::cout << "Toppings left to distribute: " << numOfToppings << std::endl;
}

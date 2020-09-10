/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

 Destructors
        
 0) move all of your implementations of all functions to OUTSIDE of the class. 
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
 2) add destructors
        make the destructors do something like print out the name of the class.

 3) add 2 new UDTs that use only the types you copied above as member variables.

 4) add 2 member functions that use your member variables to each of these new UDTs

 5) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 6) copy over your main() from the end of Project3 and get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 7) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
 
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */

#include <iostream>
/*
 copied UDT 1:
 */
struct Pizza
{
    Pizza();
    ~Pizza() { std::cout << "Destroying Pizza" << std::endl; }
    int numOfToppings;
    int diameter;
    double sliceSize;
    double calculateSliceSize(int slices);
    Pizza makePizza();
    void distributeToppings(int toppings, int slices);
};

Pizza::Pizza() : numOfToppings(1), diameter(14), sliceSize(4.5) {}

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


/*
 copied UDT 2:
 */
struct Guitar
{
    Guitar();
    ~Guitar() { std::cout << "Destroying Guitar" << std::endl; }
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
};

Guitar::Guitar() {}
Guitar::Strings::Strings()
{
    gauge = 0.011;
}

void Guitar::restringGuitar(Guitar::Strings strings)
{
    std::cout << "Guitar of model " << model << ", with string number: "<< stringNum << ", has been   re-strung using strings of gauge: "<< strings.gauge << "\n" << std::endl;
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

/*
 copied UDT 3:
 */
struct Airliner
{
    Airliner();
    ~Airliner() { std::cout << "Destroying Airliner" << std::endl; }
    int engines = 2;
    int capacity = 416;
    int fuelCapacity = 183380;
    char company = 'b';
    void checkFuelAmount();
    bool isTakeoffReady(double fuelAmount);
    int beginBoarding(int passengers);
    
};

Airliner::Airliner() {}

void Airliner::checkFuelAmount()
{
    std::cout << "Fuel amount: " << fuelCapacity << "\n" << std::endl;
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
    return 0;
}

/*
 new UDT 4:
 with 2 member functions
 */

struct PizzaPlane 
{
    PizzaPlane()
    {
        std::cout << "Constructing PizzaPlane with pizza of slice size " << pizza.sliceSize << " and plane of type " << plane.company << std::endl;
    }
    ~PizzaPlane()
    {
        std::cout << "Destroying PizzaPlane" << std::endl;
    }

    Pizza pizza;
    Airliner plane;

    void loadPizza();
    double calculatePizzaPerPerson(); 
};

void PizzaPlane::loadPizza()
{
    std::cout << "loading pizza of diameter " << pizza.diameter << " on plane of type " << plane.company << std::endl;
}

double PizzaPlane::calculatePizzaPerPerson()
{
    double r = pizza.diameter/2;
    return (r*r*3.1415)/plane.capacity;
}

/*
 new UDT 5:
 with 2 member functions
 */

struct Party
{
    Party()
    {
        std::cout << "Constructing Party for a maximum of " << plane.capacity << " people" << std::endl;
    }
    ~Party()
    {
        std::cout << "Destroying Party" << std::endl;
    }
    
    Pizza pizza;
    Airliner plane;

    void addToppingsPerString(Guitar guitar);
    void startParty(double fuel, Guitar guitar);
};

void Party::addToppingsPerString(Guitar guitar)
{
    pizza.numOfToppings += guitar.stringNum;
    std::cout << "Added " << guitar.stringNum << " toppings" << std::endl;
}

void Party::startParty(double fuel, Guitar guitar)
{
    if( plane.isTakeoffReady(fuel) && guitar.tuned)
    {
        std::cout << "Party can start! Guitar tuned and fuel amount is OK" << std::endl;
    }
    else
    {
        std::cout << "not enough preperations" << std::endl;
    }
}

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */
int main()
{
    std::cout << "good to go!\n" << std::endl;
    
    Guitar gibson;
    Guitar::Strings ernie;
    gibson.restringGuitar(ernie);

    Airliner airbus737;
    airbus737.checkFuelAmount();
    if(airbus737.isTakeoffReady(500000))
    {
        std::cout << "Is takeoff ready \n" << std::endl;
    }
    else
    {
        std::cout << "Is not takeoff ready \n" << std::endl;
    }

    Pizza margharita;
    std::cout << "Slice size is: " << margharita.calculateSliceSize(6) << "\n" << std::endl;


    // Project 3 Part 5 Checks
    std::cout << "\nProject 3 Part 5 Checks\n" << std::endl;

    gibson.tune();

    std::cout << "\n" << std::endl;
    airbus737.beginBoarding(420);

    std::cout << "\n" << std::endl;
    margharita.distributeToppings(35, 8);

    // Project 5 Part 1
    std::cout << "\nProject 5 Part 1 Checks\n" << std::endl;

    PizzaPlane order;
    order.loadPizza();

    std::cout << "Pizza per person with max passanger count: " << order.calculatePizzaPerPerson() << std::endl;

    Party party;
    party.addToppingsPerString(gibson);
    party.startParty(183390, gibson);
}


/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */








#include <iostream>
#include "LeakedObjectDetector.h"
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
    void properties();
    JUCE_LEAK_DETECTOR(Pizza)
};

Pizza::Pizza() : numOfToppings(1), diameter(14), sliceSize(4.5) { std::cout << "Constructing Pizza" << std::endl;  } 

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

struct PizzaWrapper
{
    PizzaWrapper( Pizza* ptr ) : pointerToPizza( ptr ) { }
    ~PizzaWrapper()
    {
        delete pointerToPizza;
    }
    
    Pizza* pointerToPizza = nullptr;
};

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
    void info();
    JUCE_LEAK_DETECTOR(Guitar)
};

Guitar::Guitar() { std::cout << "Constructing Guitar" << std::endl;  } 
Guitar::Strings::Strings()
{
    gauge = 0.011;
}

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

struct GuitarWrapper
{
    GuitarWrapper( Guitar* ptr ) : pointerToGuitar( ptr ) { }
    ~GuitarWrapper()
    {
        delete pointerToGuitar;
    }
    
    Guitar* pointerToGuitar = nullptr;
};

struct StringsWrapper
{
    StringsWrapper( Guitar::Strings* ptr ) : pointerToStrings( ptr ) { }
    ~StringsWrapper()
    {
        delete pointerToStrings;
    }
    
    Guitar::Strings* pointerToStrings = nullptr;
};

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
    void status();
    JUCE_LEAK_DETECTOR(Airliner)
};

Airliner::Airliner() { std::cout << "Constructing Airliner" << std::endl; }

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

struct AirlinerWrapper
{
    AirlinerWrapper( Airliner* ptr ) : pointerToAirliner( ptr ) { }
    ~AirlinerWrapper()
    {
        delete pointerToAirliner;
    }
    
    Airliner* pointerToAirliner = nullptr;
};

/*
 new UDT 4:
 with 2 member functions
 */
struct GuitarStore 
{
    GuitarStore()
    {
        std::cout << "Constructing Guitar Store " << std::endl;
    }
    ~GuitarStore()
    {
        std::cout << "Destroying GuitarStore" << std::endl;
    }

    Guitar guitar;
    Guitar::Strings strings;
    Airliner plane;

    void modifyGuitar(double gauge, char model, int frets, int stringNum);
    void loadPlane(int guitarNum, int passangers);
    void info();
    JUCE_LEAK_DETECTOR(GuitarStore)
};

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

struct GuitarStoreWrapper
{
    GuitarStoreWrapper( GuitarStore* ptr ) : pointerToGuitarStore( ptr ) { }
    ~GuitarStoreWrapper()
    {
        delete pointerToGuitarStore;
    }
    
    GuitarStore* pointerToGuitarStore = nullptr;
};

/*
 new UDT 5:
 with 2 member functions
 */
struct Party
{
    Party()
    {
        std::cout << "Constructing Party" << std::endl;
    }
    ~Party()
    {
        std::cout << "Destroying Party" << std::endl;
    }
    
    Airliner plane;
    Pizza pizza;
    Guitar guitar;

    void increasePizzaDiameter();
    void startParty(double fuel);
    void partyPrep();
    JUCE_LEAK_DETECTOR(Party)
};

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

struct PartyWrapper
{
    PartyWrapper( Party* ptr ) : pointerToParty( ptr ) { }
    ~PartyWrapper()
    {
        delete pointerToParty;
    }
    
    Party* pointerToParty = nullptr;
};

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
    
    GuitarWrapper gibson( new Guitar() );
    StringsWrapper ernie( new Guitar::Strings() );
    
    gibson.pointerToGuitar->restringGuitar( *ernie.pointerToStrings );
    std::cout << "Number of frets on guitar: " << gibson.pointerToGuitar->fretNum << "\nNumber of strings: " << gibson.pointerToGuitar->stringNum << std::endl;
    gibson.pointerToGuitar->info();

    std::cout << "\n" << std::endl;

    AirlinerWrapper airbus737( new Airliner() );
    std::cout << std::boolalpha << "Airliner capacity: " << airbus737.pointerToAirliner->capacity << "\nAirliner fuel: " << airbus737.pointerToAirliner->fuelCapacity << "\nIs Airliner takeoff ready: " << airbus737.pointerToAirliner->isTakeoffReady(190000) << std::endl;
    airbus737.pointerToAirliner->status();

    std::cout << "\n" << std::endl;
    
    PizzaWrapper margharita( new Pizza() );
    std::cout << "Pizza diameter is: " << margharita.pointerToPizza->diameter << "\nSlice size is: " << margharita.pointerToPizza->calculateSliceSize(6) << std::endl;
    margharita.pointerToPizza->properties();


    // Project 3 Part 5 Checks
    //std::cout << "\nProject 3 Part 5 Checks\n" << std::endl;

    // gibson.tune();

    //std::cout << "\n" << std::endl;
    //airbus737.beginBoarding(420);

    //std::cout << "\n" << std::endl;
    //margharita.distributeToppings(35, 8);

    // Project 5 Part 1
    //std::cout << "\nProject 5 Part 1 Checks\n" << std::endl;

    std::cout << "\n" << std::endl;

    GuitarStoreWrapper store( new GuitarStore() );
    //store.modifyGuitar(0.13, 'g', 21, 6);
    std::cout << "Store Guitar info:\n Model:" << store.pointerToGuitarStore->guitar.model << "\n String number: "<< store.pointerToGuitarStore->guitar.stringNum << "\n Fret number: "<< store.pointerToGuitarStore->guitar.fretNum << std::endl;
    store.pointerToGuitarStore->info();
    //store.loadPlane(18, 400);

    std::cout << "\n" << std::endl;

    PartyWrapper party( new Party() );
    //party.guitar.tune();
    //party.increasePizzaDiameter();
    std::cout << std::boolalpha << "Running party checks: \n Guitar tuned: " << party.pointerToParty->guitar.tuned << "\n Plane capacity: " << party.pointerToParty->plane.capacity << "\n Pizza slice size > 0.5 per person? : " << (party.pointerToParty->pizza.calculateSliceSize(party.pointerToParty->plane.capacity) >= 0.5) << std::endl;
    party.pointerToParty->partyPrep();
    //party.startParty(183390);
}


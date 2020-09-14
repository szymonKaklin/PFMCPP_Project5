/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via 'this->' and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.
 
 2) For each std::cout statement in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
        c) call that member function after your std::cout statement in main.
        d) you should see 2 (almost) identical messages in the program output for each member function you add:
            one for the std::cout line, and one for the member function's output
 
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
		
		// 2a) the member function whose function body is almost identical to the std::cout statement in main.
        void memberFunc() 
		{ 
            // 2b) explicitly using 'this' inside this member function.
			std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
		}
		
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
		
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
		
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.memberFunc();
        return 0;
    }
}


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
    void properties();
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
    // gibson.restringGuitar(ernie);
    std::cout << "Number of frets on guitar: " << gibson.fretNum << "\nNumber of strings: " << gibson.stringNum << std::endl;
    gibson.info();

    std::cout << "\n" << std::endl;

    Airliner airbus737;
    std::cout << std::boolalpha << "Airliner capacity: " << airbus737.capacity << "\nAirliner fuel: " << airbus737.fuelCapacity << "\nIs Airliner takeoff ready: " << airbus737.isTakeoffReady(190000) << std::endl;
    airbus737.status();

    std::cout << "\n" << std::endl;
    
    Pizza margharita;
    std::cout << "Pizza diameter is: " << margharita.diameter << "\nSlice size is: " << margharita.calculateSliceSize(6) << std::endl;
    margharita.properties();


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

    GuitarStore store;
    //store.modifyGuitar(0.13, 'g', 21, 6);
    std::cout << "Store Guitar info:\n Model:" << store.guitar.model << "\n String number: "<< store.guitar.stringNum << "\n Fret number: "<< store.guitar.fretNum << std::endl;
    store.info();
    //store.loadPlane(18, 400);

    std::cout << "\n" << std::endl;

    Party party;
    //party.guitar.tune();
    //party.increasePizzaDiameter();
    std::cout << std::boolalpha << "Running party checks: \n Guitar tuned: " << party.guitar.tuned << "\n Plane capacity: " << party.plane.capacity << "\n Pizza slice size > 0.5 per person? : " << (party.pizza.calculateSliceSize(party.plane.capacity) >= 0.5) << std::endl;
    party.partyPrep();
    //party.startParty(183390);
}


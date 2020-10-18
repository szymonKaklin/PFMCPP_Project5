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
#include "Pizza.h"
#include "Guitar.h"
#include "Airliner.h"
#include "GuitarStore.h"
#include "Party.h"
#include "Wrappers.h"

/*
 copied UDT 1:
 */

/*
 copied UDT 2:
 */

/*
 copied UDT 3:
 */

/*
 new UDT 4:
 with 2 member functions
 */

/*
 new UDT 5:
 with 2 member functions
 */

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


#include "Party.h"
#include "GuitarStore.h"

struct PizzaWrapper
{
    PizzaWrapper( Pizza* ptr );
    ~PizzaWrapper();
    Pizza* pointerToPizza = nullptr;
};

struct GuitarWrapper
{
    GuitarWrapper( Guitar* ptr );
    ~GuitarWrapper();
    Guitar* pointerToGuitar = nullptr;
};

struct StringsWrapper
{
    StringsWrapper( Guitar::Strings* ptr );
    ~StringsWrapper();
    Guitar::Strings* pointerToStrings = nullptr;
};

struct AirlinerWrapper
{
    AirlinerWrapper( Airliner* ptr );
    ~AirlinerWrapper(); 
    Airliner* pointerToAirliner = nullptr;
};

struct GuitarStoreWrapper
{
    GuitarStoreWrapper( GuitarStore* ptr );
    ~GuitarStoreWrapper();
    GuitarStore* pointerToGuitarStore = nullptr;
};

struct PartyWrapper
{
    PartyWrapper( Party* ptr );
    ~PartyWrapper();
    Party* pointerToParty = nullptr;
};

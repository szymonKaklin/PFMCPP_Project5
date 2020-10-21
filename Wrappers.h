// Is there a way for me to not have to include Guitar.h?
// I need it for Guitar::Strings, as if i just forward declare struct Guitar,
// I get incomplete type used in nested name specifier error.
#include "Guitar.h"

struct Pizza;
struct Airliner;
struct GuitarStore;
struct Party;

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

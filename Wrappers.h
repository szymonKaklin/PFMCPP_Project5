struct PizzaWrapper
{
    PizzaWrapper( Pizza* ptr ) : pointerToPizza( ptr ) { }
    ~PizzaWrapper()
    {
        delete pointerToPizza;
    }
    
    Pizza* pointerToPizza = nullptr;
};

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

struct AirlinerWrapper
{
    AirlinerWrapper( Airliner* ptr ) : pointerToAirliner( ptr ) { }
    ~AirlinerWrapper()
    {
        delete pointerToAirliner;
    }
    
    Airliner* pointerToAirliner = nullptr;
};

struct GuitarStoreWrapper
{
    GuitarStoreWrapper( GuitarStore* ptr ) : pointerToGuitarStore( ptr ) { }
    ~GuitarStoreWrapper()
    {
        delete pointerToGuitarStore;
    }
    
    GuitarStore* pointerToGuitarStore = nullptr;
};

struct PartyWrapper
{
    PartyWrapper( Party* ptr ) : pointerToParty( ptr ) { }
    ~PartyWrapper()
    {
        delete pointerToParty;
    }
    
    Party* pointerToParty = nullptr;
};



#include "Wrappers.h"

PizzaWrapper::PizzaWrapper( Pizza* ptr ) : pointerToPizza( ptr ) { }
PizzaWrapper::~PizzaWrapper() { delete pointerToPizza; }

GuitarWrapper::GuitarWrapper( Guitar* ptr ) : pointerToGuitar( ptr ) { }
GuitarWrapper::~GuitarWrapper() { delete pointerToGuitar; }

StringsWrapper::StringsWrapper( Guitar::Strings* ptr ) : pointerToStrings( ptr ) { }
StringsWrapper::~StringsWrapper() { delete pointerToStrings; }

AirlinerWrapper::AirlinerWrapper( Airliner* ptr ) : pointerToAirliner( ptr ) { }
AirlinerWrapper::~AirlinerWrapper() { delete pointerToAirliner; }

GuitarStoreWrapper::GuitarStoreWrapper( GuitarStore* ptr ) : pointerToGuitarStore( ptr ) { }
GuitarStoreWrapper::~GuitarStoreWrapper() { delete pointerToGuitarStore; }

PartyWrapper::PartyWrapper( Party* ptr ) : pointerToParty( ptr ) { }
PartyWrapper::~PartyWrapper() { delete pointerToParty; }

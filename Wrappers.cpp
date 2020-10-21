#include "Wrappers.h"
#include "Pizza.h"
#include "Airliner.h"
// As I included Guitar.h in Wrappers.h in order to have the struct be complete
// in order to invoke the member struct Strings, Guitar.h is not necessary here,
// but pragma once solves re-definition issues.
#include "Guitar.h"
#include "GuitarStore.h"
#include "Party.h"

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

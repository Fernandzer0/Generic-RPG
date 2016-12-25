#include "Interactions.h"



Interactions::Interactions()
{
	canIntWCharacter = false;
	canIntWItems = false;
	canIntWPlaces = false;
}

Interactions::Interactions(bool intChar, bool intPlace, bool intItem)
{
	canIntWCharacter = intChar;
	canIntWItems = intItem;
	canIntWPlaces = intPlace;
}

Interactions::~Interactions()
{
}

void Interactions::interactWithChar()
{
}

void Interactions::interactWithItem()
{
}

void Interactions::interactWithPlace()
{
}


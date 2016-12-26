#include "Places.h"
#include "Characters.h"

Places::Places()
{
}

Places::~Places()
{
}

void Places::moveCharacterTo(Places &destination, int characterIndex)
{
	destination.addCharacter(charactersInPlace[characterIndex]);
	charactersInPlace.erase(charactersInPlace.begin() + characterIndex);
}

void Places::addItem(Items item)
{
	itemsInPlace.push_back(item);
}

Items Places::removeItem(std::vector<Items> &itemsInPlace, int elementIndex)
{
	Items removedItem = itemsInPlace[elementIndex];
	itemsInPlace.erase(itemsInPlace.begin() + elementIndex);
	return removedItem;
}

void Places::addCharacter(Characters character)
{
	charactersInPlace.push_back(character);
}

Characters Places::removeCharacters(std::vector<Characters> &charactersInPlace, int elementIndex)
{
	Characters removedCharacter = charactersInPlace[elementIndex];
	charactersInPlace.erase(charactersInPlace.begin() + elementIndex);
	return removedCharacter;
}

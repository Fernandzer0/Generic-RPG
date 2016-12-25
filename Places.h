#pragma once
#include "Items.h"
#include <vector>

class Characters;

class Places
{
public:

	int locationID;

	std::string placeName, placeDescription;

	std::vector<Items> itemsInPlace;
	std::vector<Characters> charactersInPlace;
	std::vector<Places> canMoveTo;

	Places();
	~Places();

	void moveCharacterTo(Places &destination, int characterIndex);

	void addItem(Items item);
	Items removeItem(std::vector<Items> itemsInPlace, int elementIndex);

	void addCharacter(Characters character);
	Characters removeCharacters(std::vector<Characters> character, int elementIndex);
};


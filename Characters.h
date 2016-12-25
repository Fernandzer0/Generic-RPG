#pragma once
#include <iostream>
#include <vector>
#include "Items.h"
#include "Places.h"

class Characters
{
private:

public:
	
	std::string characterName;

	int characterHealth, characterMana, characterStrength, characterDexterity, characterMagic, characterInventorySize, characterOccupation, characterLevel, characterExperience;

	//head, chest, legs, feet, hand, offhand, none = 0-6
	Items equipSlot[6];

	std::vector<Items> inventory;
	
	//constructors
	Characters();
	Characters(std::string name, int health, int mana, int strength, int dexterity, int magic, int inventorySize, int occupation, int level, int experience);
	~Characters();

	//character actions
	void levelUp();
	void moveTo();
	void add(Items item);
	void equip(Items item);
	Items remove(std::vector<Items> &inv, int elementIndex);
	void transfer(std::vector<Items> &invFrom, int elementIndex);
};


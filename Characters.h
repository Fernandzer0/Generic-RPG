#pragma once
#include <iostream>
#include <vector>
#include "Items.h"
#include "Places.h"

enum alignment { hostile, neutral, friendly, player };

class Characters
{
private:

public:
	
	std::string characterName;

	int characterHealth, characterMana, characterStrength, characterDexterity, characterMagic, characterInventorySize, characterOccupation, characterLevel, characterExperience;

	std::vector<Items> inventory;

	//head, chest, legs, feet, hand, offhand, none = 0-6
	Items equipSlot[6];

	//hostile, neutral, friendly, player = 0-3
	alignment charAlignment; 

	//combat
	std::vector<Characters> targets;
	
	//constructors
	Characters();
	Characters(std::string name, alignment alignment, int health, int mana, int strength, int dexterity, int magic, int inventorySize, int level, int experience);
	~Characters();

	//character actions
	void levelUp();
	void add(Items item);
	void equip(Items item);
	void target(Characters &target);
	Items remove(std::vector<Items> &inv, int elementIndex);
	void transfer(std::vector<Items> &invFrom, int elementIndex);
};


#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Items.h"
#include "Places.h"

class Characters
{
private:

public:
	
	std::string name;

	int health, mana, strength, dexterity, magic, inventorySize, occupation, level, experience;

	//head chest legs feet hand offhand
	Items equipSlot[6];

	std::vector<Items> inventory;

	int locationID;
	
	//constructors
	Characters();
	Characters(std::string name, int health, int mana, int strength, int dexterity, int magic, int inventorySize, int occupation, int level, int experience);
	~Characters();

	//character actions
	void levelUp();
	void moveTo(Places place);
	void add(Items item);
	void equip(Items item);
	Items remove(std::vector<Items> &inv, int elementIndex);
};


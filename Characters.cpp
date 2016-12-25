#include "Characters.h"

Characters::Characters()
{
	health = 0;
	mana = 0;
	strength = 0;
	dexterity = 0;
	magic = 0;
	inventorySize = 0;
	occupation = 0;
	level = 0;
	experience = 0;
	for(int i = 0; i < 6; i++)
	{
		Items default;
		equipSlot[i] = default;
	}
}

Characters::Characters(std::string name, int health, int mana, int strength, int dexterity, int magic, int inventorySize, int occupation, int level, int experience)
{
	this->name = name;
	this->health = health;
	this->mana = mana;
	this->strength = strength;
	this->dexterity = dexterity;
	this->magic = magic;
	this->inventorySize = inventorySize;
	this->occupation = occupation;
	this->level = level;
	this->experience = experience;
	for (int i = 0; i < 6; i++)
	{
		Items default;
		equipSlot[i] = default;
	}
}

Characters::~Characters() 
{
}

void Characters::levelUp()
{
}

void Characters::moveTo(Places place)
{
}

void Characters::add(Items item)
{
	if(inventory.size() < inventorySize)
	{	
		inventory.push_back(item);
	}
	else
		std::cout << "You don't have enough inventory space!\n";
}

void Characters::equip(Items item)
{
	if (item.slot == none)
		std::cout << "You can't equip that!\n";
	else
		for(int i = 0; i < 6; i++)
			if(item.slot == i)
				equipSlot[i] = item;
}

Items Characters::remove(std::vector<Items> &inv, int elementIndex)
{
	Items removedItem = inv[elementIndex];
	inv.erase(inv.begin() + elementIndex);
	return removedItem;
}
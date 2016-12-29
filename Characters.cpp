#include "Characters.h"
#include <assert.h>
Characters::Characters()
{
	characterName = "";
	characterHealth = 0;
	characterMana = 0;
	characterStrength = 0;
	characterDexterity = 0;
	characterMagic = 0;
	characterInventorySize = 0;
	characterOccupation = 0;
	characterLevel = 0;
	characterExperience = 0;
	currentHealth = characterHealth;
	for(int i = 0; i < 6; i++)
	{
		Items default;
		equipSlot[i] = default;
	}
	Items fists("Fists",1,0,1,0, noSlot, noAtt);
	equipSlot[hand] = fists;
	charAlignment = neutral;
}

Characters::Characters(std::string name, alignment alignment, int health, int mana, int strength, int dexterity, int magic, int inventorySize, int level, int experience)
{
	characterName = name;
	charAlignment = alignment;
	characterHealth = health;
	characterMana = mana;
	characterStrength = strength;
	characterDexterity = dexterity;
	characterMagic = magic;
	characterInventorySize = inventorySize;
	characterLevel = level;
	characterExperience = experience;
	currentHealth = characterHealth;
	for (int i = 0; i < 6; i++)
	{
		Items default;
		equipSlot[i] = default;
	}
	Items fists("Fists", 1, 0, 1, 0, noSlot, noAtt);
	equipSlot[hand] = fists;
}

Characters::~Characters() {}

void Characters::levelUp()
{
}

void Characters::add(Items item)
{
	if (inventory.size() < characterInventorySize)
		inventory.push_back(item);
	else
		std::cout << "You don't have enough inventory space!\n";
}

void Characters::equip(Items item)
{
	if (item.slot == noSlot)
		std::cout << "You can't equip that!\n";
	if (item.slot < 6)
	{
		if (item.slot == equipSlot[item.slot].slot)
		{
			inventory.push_back(equipSlot[item.slot]);
			equipSlot[item.slot] = item;
		}
		else
			equipSlot[item.slot] = item;
	}
}

void Characters::target(Characters &target)
{
	Characters *temp = &target;
	for (int i = 0; i < targets.size(); i++)
		if (targets[i] == temp)
			targets.erase(targets.begin() + i);
	for (int i = targets.size(); i > equipSlot[hand].targets - 1; i--) {
		targets.erase(targets.begin());
	}
	targets.push_back(temp);
}

Items Characters::remove(std::vector<Items> &inv, int elementIndex)
{
	Items removedItem = inv[elementIndex];
	inv.erase(inv.begin() + elementIndex);
	return removedItem;
}

void Characters::transfer(std::vector<Items> &invFrom, int elementIndex)
{
	if (inventory.size() < characterInventorySize)
	{
		inventory.push_back(invFrom[elementIndex]);
		invFrom.erase(invFrom.begin() + elementIndex);
	}
	else
		std::cout << "You don't have enough inventory space!";
}


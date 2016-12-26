#pragma once
#include <string>

enum equipSlot { head, chest, legs, feet, hand, offhand, noSlot };
enum attribute { strength, dexterity, magic, noAtt };

class Items
{
public:

	std::string itemName, itemDescription;

	int damage, defense, targets, price;
	equipSlot slot;
	attribute stat;

	Items();
	Items(std::string name, int damage, int defense, int targets, int price, equipSlot slot, attribute itemStat);
	~Items();
};


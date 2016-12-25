#pragma once
#include <string>

enum equipSlot { head, chest, legs, feet, hand, offhand, none };

class Items
{
public:

	std::string itemName, itemDescription;

	int damage, defense, attribute, range, price;
	equipSlot slot;

	int locationID;
		
	Items();
	Items(std::string name, int damage, int defense, int attribute, int range, int price, equipSlot slot);
	~Items();
};


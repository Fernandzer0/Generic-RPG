#include "Items.h"

Items::Items()
{
	itemName = "";
	damage = 0;
	defense = 0;
	attribute = 0;
	range = 0;
	price = 0;
	slot = none;
}

Items::Items(std::string name, int damage, int defense, int attribute, int range, int price, equipSlot slot)
{
	itemName = name;
	this->damage = damage;
	this->defense = defense;
	this->attribute = attribute;
	this->price = price;
	this->slot = slot;
	this->range = range;
}

Items::~Items()
{
}

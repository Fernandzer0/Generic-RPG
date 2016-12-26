#include "Items.h"

Items::Items()
{
	itemName = "";
	damage = 0;
	defense = 0;
	targets = 0;
	price = 0;
	slot = noSlot;
	stat = noAtt;
}

Items::Items(std::string name, int damage, int defense, int targets, int price, equipSlot slot, attribute itemStat)
{
	itemName = name;
	this->damage = damage;
	this->defense = defense;
	this->price = price;
	this->targets = targets;
	this->slot = slot;
	stat = itemStat;

}

Items::~Items()
{
}

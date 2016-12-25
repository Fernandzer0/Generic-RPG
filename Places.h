#pragma once
#include "Items.h"
#include <vector>
class Places
{
public:

	int locationID;

	std::vector<Items> itemsInPlace;

	std::vector<Places> canTravelTo;

	Places();
	~Places();
};


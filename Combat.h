#pragma once
#include "Characters.h"

class Combat
{
public:

	std::vector<Characters> inCombat;


	Combat();
	~Combat();

	void Combat::addToCombat(std::vector<Characters> &character, int elementIndex);
	void Combat::dexSort();
	void Combat::setTargets();
	void Combat::removeTargets();
	void Combat::fight();
	void Combat::resolveFight();

};


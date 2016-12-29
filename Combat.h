#pragma once
#include "Characters.h"
#include "time.h"

class Combat
{
public:

	std::vector<Characters> inCombat, diedInCombat;

	Combat();
	~Combat();

	void Combat::addToCombat(std::vector<Characters> &character, int elementIndex);
	void Combat::dexSort();
	void Combat::setTargets();
	void Combat::removeDeadTargets();
	void Combat::fight();
	void Combat::resolveFight();

};

std::vector<int> nonRRN(int xNum, int range);


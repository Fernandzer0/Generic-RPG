#include "Combat.h"

Combat::Combat()
{
}

Combat::~Combat()
{
}

void Combat::addToCombat(std::vector<Characters> &character, int elementIndex)
{
	inCombat.push_back(character[elementIndex]);
	character.erase(character.begin() + elementIndex);
}

void Combat::dexSort()
{
	for (int i = 0; i < inCombat.size(); i++)
	{
		for (int j = i; j < inCombat.size(); j++)
		{
			if (inCombat[i].characterDexterity < inCombat[j].characterDexterity)
			{
				Characters temp = inCombat[i];
				inCombat[i] = inCombat[j];
				inCombat[j] = temp;
			}
		}
	}
}

void Combat::setTargets()
{
}

void Combat::removeTargets()
{
	for (int i = 0; i < inCombat.size(); i++)
		for (int j = 0; j < inCombat[i].targets.size(); j++)
			if (inCombat[i].targets[j].characterHealth == 0)
				inCombat[i].targets.erase(inCombat[i].targets.begin() + j);
}

void Combat::fight()
{
}

void Combat::resolveFight()
{
}

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
	if (inCombat.size() < 2)
		return;
	std::vector<Characters*> targetsHostile, targetsFriendly, targetsNeutral;
	Characters *temp;
	for (int i = 0; i < inCombat.size(); i++)
	{
		temp = &inCombat[i];
		if (inCombat[i].charAlignment == hostile)
			targetsHostile.push_back(temp);
		if (inCombat[i].charAlignment == neutral)
			targetsNeutral.push_back(temp);
		if (inCombat[i].charAlignment == friendly)
			targetsFriendly.push_back(temp);
		if (inCombat[i].charAlignment == player)
			targetsFriendly.push_back(temp);
	}
	for (int i = 0; i < inCombat.size(); i++)
	{
		srand((i*i*104729)%29);
		if (inCombat[i].charAlignment == hostile)
		{
			std::vector<Characters*> targetsFinal = targetsFriendly;
			for (int i = 0; i < targetsNeutral.size(); i++)
				targetsFinal.push_back(targetsNeutral[i]);
			std::vector<int> targElements = nonRRN(inCombat[i].equipSlot[hand].targets, targetsFinal.size());			
			for (int j = 0; j < targElements.size(); j++)
				inCombat[i].target(*targetsFinal[targElements[j]]);
		}
		if (inCombat[i].charAlignment == friendly)
		{
			std::vector<int> targElements = nonRRN(inCombat[i].equipSlot[hand].targets, targetsHostile.size());
			for (int j = 0; j < targElements.size(); j++)
				inCombat[i].target(*targetsHostile[targElements[j]]);
		}
	}
}

void Combat::removeDeadTargets()
{
	for (int i = 0; i < inCombat.size(); i++)
		for (int j = inCombat[i].targets.size() - 1; j > -1 ; j--)
		{
			Characters temp = *inCombat[i].targets[j];
			if (temp.currentHealth == 0)
				inCombat[i].targets.erase(inCombat[i].targets.begin() + j);
		}
	for (int i = inCombat.size() - 1; i > -1 ;  i--)
	{
		if (inCombat[i].currentHealth == 0)
		{
			diedInCombat.push_back(inCombat[i]);
			inCombat.erase(inCombat.begin()  + i);
		}
	}
}

void Combat::fight()
{
	setTargets();
	int damageSubtotal;
	for (int i = 0; i < inCombat.size(); i++)
	{
		for (int j = 0; j < inCombat[i].targets.size() ; j++)
		{
			damageSubtotal = 0;
			damageSubtotal += inCombat[i].equipSlot[hand].damage;
			for (int k = 0; k < 6; k++)
				damageSubtotal -= (*inCombat[i].targets[j]).equipSlot[k].defense;
			if (damageSubtotal < 1)
				damageSubtotal = 1;
			if ((*inCombat[i].targets[j]).charAlignment == neutral)
				(*inCombat[i].targets[j]).target(inCombat[i]);
			(*inCombat[i].targets[j]).currentHealth -= damageSubtotal;
		}
		removeDeadTargets();
	}
}

void Combat::resolveFight()
{
	bool fightOver = false;
	int hostiles,  friendlies;
	dexSort();
	while(!fightOver)
	{
		hostiles = 0;
		friendlies = 0;
		fight();
		for (int i = 0; i < inCombat.size(); i++)
			if (inCombat[i].charAlignment == hostile)
				hostiles++;
		for (int i = 0; i < inCombat.size(); i++)
			if (inCombat[i].charAlignment == friendly || inCombat[i].charAlignment == neutral)
				friendlies++;
		if (friendlies == 0 || hostiles == 0)
			fightOver = true;
	}
}

std::vector<int> nonRRN(int xNum, int range)
{
	if (range < xNum)
		xNum = range;
	std::vector<int> nonRRN;
	int temp;
	bool works = true;
	nonRRN.push_back(rand() % range);
	for (int i = 0; i < xNum; i = nonRRN.size())
	{
		works = true;
		temp = rand() % range;
		for (int j = 0; j < nonRRN.size(); j++)
			if(nonRRN[j] == temp)
				works = false;
		if (works)
			nonRRN.push_back(temp);
	}
	return nonRRN;
}
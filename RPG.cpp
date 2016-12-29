#include "Combat.h"

using namespace std;

//rand seed

int main()
{
	Characters hostile1("Hostile 1", hostile, 10, 0, 1, 5, 0, 5, 0, 0);
	Characters hostile2("Hostile 2", hostile, 10, 0, 1, 4, 0, 5, 0, 0);
	Characters hostile3("Hostile 3", hostile, 10, 0, 1, 3, 0, 5, 0, 0);
	Characters hostile4("Hostile 4", hostile, 10, 0, 1, 2, 0, 5, 0, 0);

	Characters neutral1("Neutral 1", neutral, 10, 0, 1, 0, 0, 5, 0, 0);
	Characters neutral2("Neutral 2", neutral, 10, 0, 1, 1, 0, 5, 0, 0);
	
	Characters friendly1("Friendly 1", friendly, 10, 0, 1, 2, 0, 5, 0, 0); 
	Characters friendly2("Friendly 2", friendly, 10, 0, 1, 4, 0, 5, 0, 0);
	Characters friendly3("Friendly 3", friendly, 10, 0, 1, 6, 0, 5, 0, 0);

	Items weapon("Trident", 1, 1, 2, 0, hand, noAtt);

	hostile1.equip(weapon);
	hostile2.equip(weapon);
	hostile3.equip(weapon);
	hostile4.equip(weapon);

//	neutral1.equip(weapon);
//	neutral2.equip(weapon);
	
//	friendly1.equip(weapon);
//	friendly2.equip(weapon);
//	friendly3.equip(weapon);

	Places tavern;

	tavern.addCharacter(hostile1);
	tavern.addCharacter(hostile2);
	tavern.addCharacter(hostile3);
	tavern.addCharacter(hostile4);

	tavern.addCharacter(neutral1);
	tavern.addCharacter(neutral2);

	tavern.addCharacter(friendly1);
	tavern.addCharacter(friendly2);
	tavern.addCharacter(friendly3);

	Combat barFight;

	for (int i = 0; tavern.charactersInPlace.size() > 0 ; i++)
		barFight.addToCombat(tavern.charactersInPlace, 0);

	barFight.resolveFight();

	cin.get();
}
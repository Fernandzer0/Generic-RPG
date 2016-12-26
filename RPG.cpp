#include "Combat.h"

using namespace std;

int main()
{
	Items POS("POS helmet", 2, 3, 0, 2, head, noAtt);
	Items gewd("gewd helmet", 5, 5, 0, 2, head, noAtt);
	Items pls("pls work, the legendary blade", 1, 1, 1, 1, hand, noAtt);
	Items fck("fk u up m8", 1, 1, 2, 1, hand, noAtt);

	Characters bill("bill", neutral, 10, 0, 2, 1, 0, 5, 0, 0);
	Characters tom("tom", friendly, 10, 0, 2, 3, 0, 5, 0, 0);
	Characters jim("jim", hostile, 10, 0, 2, 5, 0, 5, 0, 0);
	
	bill.equip(fck);
	tom.equip(pls);
	jim.equip(POS);

	Places tavern;

	tavern.addCharacter(jim);
	tavern.addCharacter(tom);
	tavern.addCharacter(bill);

	Combat barFight;

	barFight.addToCombat(tavern.charactersInPlace, 0);
	barFight.addToCombat(tavern.charactersInPlace, 0);
	barFight.addToCombat(tavern.charactersInPlace, 0);

	barFight.inCombat[1].target(barFight.inCombat[2]);
	barFight.inCombat[2].target(barFight.inCombat[1]);

	barFight.inCombat[2].characterHealth = 0;


	barFight.removeTargets();

	cin.get();
}
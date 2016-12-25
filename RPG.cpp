#include "Characters.h"

using namespace std;

int main()
{
	Items POS("POShelmet", 2, 3, 3, 2, 3, head), gewd("gewdhead", 5, 5, 7, 2, 8, head), ugh, pls("pls work, the legendary blade" , 1, 1, 1, 1, 1, hand);
	ugh.itemName = "ughh";
	Characters bill("bill", 2, 2, 2, 2, 2, 3, 2, 2, 2), tom("tom", 2, 2, 2, 2, 2, 10, 2, 2, 2), jim;

	Places livingRoom;
	Places bathRoom;

	livingRoom.addCharacter(bill);
	livingRoom.addItem(POS);
	
	livingRoom.moveCharacterTo(bathRoom, 0);

	//cout << bathRoom.charactersInPlace[0].characterName << livingRoom.itemsInPlace[0].itemName;

	cin.get();
}
#include <iostream>
#include <string>
#include "Characters.h"

using namespace std;

int main()
{
	Items POS("POShelmet", 2, 3, 3, 2, 3, head), gewd("gewdshirt", 5, 5, 7, 2, 8, chest), ugh, pls("pls work, the legendary blade" , 1, 1, 1, 1, 1, hand);
	ugh.itemName = "ughh";
	Characters bill("bill", 2, 2, 2, 2, 2, 10, 2, 2, 2), tom("tom", 2, 2, 2, 2, 2, 10, 2, 2, 2), jim;

	bill.add(POS);
	bill.equip(bill.remove(bill.inventory, 0));

 	cin.get();
}
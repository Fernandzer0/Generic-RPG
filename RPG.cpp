#include "Combat.h"
#include "CSV.h"
using namespace std;

//rand seed

int main()
{
	Items* ItemsList;
	int numItems;
	try {
		CSV myFile("ItemsList.csv");
		myFile.GetHeaders();
		numItems = myFile.GetData().size();

		ItemsList = new Items[numItems];

		vector<vector<string>> itemData = myFile.GetData();

		for (int i = 0; i < itemData.size(); i++) {
			ItemsList[i].itemName = itemData[i][0];
			ItemsList[i].damage = atoi(itemData[i][1].c_str());
			ItemsList[i].defense = atoi(itemData[i][2].c_str());
			ItemsList[i].targets = atoi(itemData[i][3].c_str());
			ItemsList[i].price = atoi(itemData[i][4].c_str());

			if (itemData[i][5] == "head") {
				ItemsList[i].slot = head;
			}
			else if (itemData[i][5] == "chest") {
				ItemsList[i].slot = chest;
			}
			else if (itemData[i][5] == "legs") {
				ItemsList[i].slot = legs;
			}
			else if (itemData[i][5] == "feet") {
				ItemsList[i].slot = feet;
			}
			else if (itemData[i][5] == "hand") {
				ItemsList[i].slot = hand;
			}
			else if (itemData[i][5] == "offhand") {
				ItemsList[i].slot = offhand;
			}
			else {
				ItemsList[i].slot = noSlot;
			}

			if (itemData[i][6] == "strength") {
				ItemsList[i].stat = strength;
			}
			else if (itemData[i][6] == "dexterity") {
				ItemsList[i].stat = dexterity;
			}
			else if (itemData[i][6] == "magic") {
				ItemsList[i].stat = magic;
			}
			else {
				ItemsList[i].stat = noAtt;
			}
		}
	}
	catch (exception e) {
		cout << e.what() << endl;
		return 0;
	}

	//myFile has all item stat data
	for (int i = 0; i < numItems; i++) {
		cout << ItemsList[i].itemName << endl;
	}

	cout << ItemsList[1].stat << endl;
	srand(time(NULL));
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

	for (int i = 0; tavern.charactersInPlace.size() > 0; i++)
		barFight.addToCombat(tavern.charactersInPlace, 0);

	barFight.resolveFight();
	cin.get();
}

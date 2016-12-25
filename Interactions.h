#pragma once
class Interactions
{
public:

	bool canIntWCharacter, canIntWPlaces , canIntWItems;

	Interactions();
	Interactions(bool intChar, bool intPlace, bool intItem);
	~Interactions();

	void interactWithChar();
	void interactWithItem();
	void interactWithPlace();
};


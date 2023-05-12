#pragma once

#include<queue>

#include "deck.h"

class War {
public:
	War();
	~War();

public:
	void play();

protected:
	void initialize();
	void round();
	void war();
	void shuffle_spoils();
	void add_spoils(char winner);

protected:
	Deck full_deck;
	std::queue<Card*> player_hand;
	std::queue<Card*> computer_hand;
	std::vector<Card*> spoils;
};
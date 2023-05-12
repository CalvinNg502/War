#include <random>
#include <iostream>

#include "war.h"

static std::random_device rd;
static std::mt19937 rng(rd());

/**
* constructor
*/
War::War() {
	Deck full_deck();
}

/**
* deconstructor
*/
War::~War() {

}

/**
* plays a game of war
*/
void War::play() {
	initialize();
	std::string keep_playing = "y";
	
	//each iteration is one round of War (including any war outbreaks)
	while (!this->computer_hand.empty() && !this->player_hand.empty() && keep_playing == "y") {
		std::cout << "Player hand size: " << this->player_hand.size() << std::endl;
		std::cout << "Computer hand size: " << this->computer_hand.size() << std::endl;
		std::cout << "Would you like to keep playing (y/n)?";

		//check if player wants to keep playing
		do {
			std::cin >> keep_playing;
			if (keep_playing != "y" && keep_playing != "n") {
				std::cout << "invalid input; please enter 'y' or 'n'";
			}
		} while (keep_playing != "y" &&	keep_playing != "n");

		if (keep_playing == "y") {
			std::cout << std::endl;
			round();
		}
	}

	//game is over, check who won
	if (this->computer_hand.empty()) {
		std::cout << "The player has claimed victory!" << std::endl;
	}
	else if (this->player_hand.empty()) {
		std::cout << "The computer has claimed victory!" << std::endl;
	}

}

/**
* shuffle the deck and initialize hands
*/
void War::initialize() {
	this->full_deck.shuffle();

	for (int i = 0; i < 52; i++) {
		if (i % 2 == 0) {
			this->player_hand.push(this->full_deck.draw());
		}
		else {
			this->computer_hand.push(this->full_deck.draw());
		}
	}
}

/**
* performs one draw and gives spoils to the player who drew a higher card
*/
void War::round() {
	//draw from hands and add to spoils
	Card* player_draw = this->player_hand.front();
	this->player_hand.pop();
	Card* computer_draw = this->computer_hand.front();
	this->computer_hand.pop();

	this->spoils.push_back(player_draw);
	this->spoils.push_back(computer_draw);

	//print what each player drew
	std::cout << "The computer drew a " << computer_draw->print() << std::endl;
	std::cout << "The player drew a " << player_draw->print() << std::endl;

	//decide who wins the spoils
	if (player_draw->compareValue(*computer_draw) == 1) {
		std::cout << "The player won the spoils (" << this->spoils.size() << " cards)" << std::endl;
		add_spoils('p');
	}
	else if (player_draw->compareValue(*computer_draw) == -1) {
		std::cout << "The computer won the spoils (" << this->spoils.size() << " cards)" << std::endl;
		add_spoils('c');
	}
	else {
		std::cout << "War! Both players draw a face-down card and a face-up card to determine who wins the spoils!" << std::endl;
		war();
	}
}

/**
* shuffles the vector of spoils
*/
void War::shuffle_spoils() {
	std::shuffle(this->spoils.begin(), this->spoils.end(), rng);
}

/**
* adds the spoils vector to the winner.  'c' for computer and 'p' for player.
* Empties the spoils vector.
*/
void War::add_spoils(char winner) {
	shuffle_spoils();

	if (winner == 'c') {
		for (int i = 0; i < this->spoils.size(); i++) {
			this->computer_hand.push(spoils[i]);
		}
	}
	else {
		for (int i = 0; i < this->spoils.size(); i++) {
			this->player_hand.push(spoils[i]);
		}
	}

	//empty spoils
	while (!this->spoils.empty()) {
		this->spoils.pop_back();
	}
}

/**
* Performs war until a winner claims all the spoils
*/
void War::war() {
	//if one player does not have the cards to support the war, the game is over
	if (this->player_hand.size() < 2) {
		std::cout << "The player does not have enough cards to support the war and has lost" << std::endl;
		//empty the player's hand so the play method recognizes that they have lost
		while (!this->player_hand.empty()) {
			this->player_hand.pop();
		}
		return;
	}
	else if (this->computer_hand.size() < 2) {
		std::cout << "The computer does not have enough cards to support the war and has lost" << std::endl;
		//empty the computer's hand so the play method recognizes that they have lost
		while (!this->computer_hand.empty()) {
			this->computer_hand.pop();
		}
		return;
	}

	//add face-down card to spoils
	this->spoils.push_back(this->player_hand.front());
	this->player_hand.pop();
	this->spoils.push_back(this->computer_hand.front());
	this->computer_hand.pop();

	//draws the face-up card and compares; it is more or less just another round of war, but with higher stakes
	round();
}
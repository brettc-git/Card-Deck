#pragma once
#include <iostream>
#include "card_deck.h"
using std::cout;
using std::string;

const string suits[] = { "S", "H", "C", "D" }; // Spades, Hearts, Clubs, Diamonds
enum Face { Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };


class Card : public card_deck {

private:
	string suit; 
	Face face;
	
public:
	Card() : suit(), face() {};
	Card(string s, Face num) : suit(s), face(num) {};
	void printCard();
};

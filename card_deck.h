#pragma once

#include <iostream>

#include <algorithm>
#include <chrono>
#include <random>
#include <vector>

#include "card.h"

using std::string;
using std::vector;

const int deck_size = 52;

class card_deck
{
private:
	vector<Card> deck;  // Dynamically allocate memory for 52 cards;
public:
	card_deck(); // Constructor
	~card_deck(); // Deconstructor
	void shuffleDeck(); 
	vector<Card> dealCards(vector<Card> set);
};

card_deck::card_deck()
{
	deck.resize(52);

	for (int i = 0; i < deck_size; i++) // i < 4
	{
		deck[i] = Card(suits[i % 4], (i % 13) + 1);
	}
}

card_deck::~card_deck()
{
	deck.clear();
}

void card_deck::shuffleDeck()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle (deck.begin(), deck.end(), std::default_random_engine(seed));
}

vector<Card> card_deck::dealCards(vector<Card> set) {
	
	auto top = deck.begin();
	auto stop = deck.begin() + set.size();
	vector<Card> hand(top, stop);
	return hand;
}

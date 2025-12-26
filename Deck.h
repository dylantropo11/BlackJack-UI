#pragma once
#include "Card.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

class Deck {
private:
	vector<Card> cards;
	int currentCardIndex = 0;
public:
	Deck() {
		vector<string> values = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
		vector<string> suits = { "Diamonds","Hearts","Spades","Blades" };

		for (const auto& suit : suits) {
			for (const auto& value : values) {
				cards.push_back(Card(value, suit));
			}
		}
		shuffleCards();
	}

	void shuffleCards() {
		random_device rd;
		mt19937 gen(rd());
		shuffle(cards.begin(), cards.end(), gen);
		currentCardIndex = 0;
	}

	Card drawCard() {
		if (currentCardIndex >= cards.size()) {
			throw out_of_range("No hay más cartas en el mazo");
		}
		return cards[currentCardIndex++];
	}


};




#pragma once
#include <iostream>
#include <string>
using namespace std;

class Card {
private:
	string value;   //1,2,3,4,5,6,7,8,9,10,11
	string suit;   //Clubs, Diamonds, Hearts, and Spades
public:
	Card(string val, string sui) {
		value = val;
		suit = sui;
	}
	void showCard() const{
		cout << value << " of " << suit << endl;
	}

	int getValue() const {
		if (value == "A") return 11;
		if (value == "J" || value == "Q" || value == "K") return 10;
		return stoi(value);
	}
	//string getSuit() {
	//	return suit;
	//}
};



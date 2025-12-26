#pragma once
#include "Card.h"
#include <iostream> // Necesario para cout y endl
#include <vector>   // Necesario para std::vector
#include <string>   // Necesario para std::string
using namespace std;

class Player {
protected: // CAMBIO CLAVE: Cambiado de private a protected
	vector<Card> hand;
	string pName;
public:
	Player(string name) {
		pName = name;
	}

	string getName() const {
		return pName;
	}

	void setName(string name) {
		pName = name;
	}

	void addCard(const Card& card) {
		hand.push_back(card);
	}

	// Método para mostrar la mano completa (útil para el jugador o cuando el crupier revela su mano)
	void showHand() const {
		cout << pName << "'s hand:" << endl;
		if (hand.empty()) {
			cout << "  (Mano vacia)" << endl;
			return;
		}
		for (const auto& card : hand) {
			card.showCard(); // Muestra "valor of palo", como "A of Hearts"
		}
		cout << "Puntaje total: " << getScore() << endl << endl;
	}

	void clearHand() {
		hand.clear();
	}

	int getScore() const {
		int total = 0;
		int numAs = 0;

		for (const auto& card : hand) {
			int value = card.getValue();
			total += value;

			if (card.getValue() == 11) { // As initial value
				numAs++;
			}
		}

		while (total > 21 && numAs > 0) {
			total -= 10; // Change Ace value from 11 to 1
			numAs--;
		}
		return total;
	}
};
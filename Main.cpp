
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept> // Para std::out_of_range
#include <limits>    // Para std::numeric_limits

// --- Incluye los archivos de cabecera de tus clases aquí ---
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Dealer.h"

// Función auxiliar para limpiar el buffer de entrada
void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::cout << "--- Inicio de Pruebas de Funciones de Blackjack ---" << std::endl;

    // --- PRUEBAS DE LA CLASE CARD ---
    std::cout << "\n--- Prueba: Clase Card ---" << std::endl;
    Card testCard1("A", "Hearts");
    Card testCard2("K", "Spades");
    Card testCard3("7", "Diamonds");

    std::cout << "Carta 1: "; testCard1.showCard();
    std::cout << "  Valor: " << testCard1.getValue() << std::endl; // Debería ser 11
    std::cout << "Carta 2: "; testCard2.showCard();
    std::cout << "  Valor: " << testCard2.getValue() << std::endl; // Debería ser 10
    std::cout << "Carta 3: "; testCard3.showCard();
    std::cout << "  Valor: " << testCard3.getValue() << std::endl; // Debería ser 7


    // --- PRUEBAS DE LA CLASE DECK ---
    std::cout << "\n--- Prueba: Clase Deck ---" << std::endl;
    Deck testDeck;
    std::cout << "Mazo creado y barajado.\n";

    std::cout << "Repartiendo 3 cartas:\n";
    for (int i = 0; i < 3; ++i) {
        try {
            Card drawn = testDeck.drawCard();
            std::cout << "  Repartida: "; drawn.showCard();
        }
        catch (const std::out_of_range& e) {
            std::cerr << "Error al robar carta: " << e.what() << std::endl;
        }
    }
    std::cout << "Barajando el mazo de nuevo...\n";
    testDeck.shuffleCards();
    std::cout << "Mazo barajado. Repartiendo 2 cartas más:\n";
    for (int i = 0; i < 2; ++i) {
        try {
            Card drawn = testDeck.drawCard();
            std::cout << "  Repartida: "; drawn.showCard();
        }
        catch (const std::out_of_range& e) {
            std::cerr << "Error al robar carta: " << e.what() << std::endl;
        }
    }


    // --- PRUEBAS DE LA CLASE PLAYER ---
    std::cout << "\n--- Prueba: Clase Player ---" << std::endl;
    Player testPlayer("Alice");
    Deck playerDeck; // Nuevo mazo para Alice

    testPlayer.addCard(playerDeck.drawCard());
    testPlayer.addCard(playerDeck.drawCard());
    testPlayer.showHand(); // Mostrar mano de Alice y su puntaje inicial

    // Prueba de lógica de puntuación del As
    std::cout << "\nProbando lógica de As (11 vs 1):\n";
    testPlayer.clearHand();
    testPlayer.addCard(Card("A", "Clubs"));
    testPlayer.addCard(Card("K", "Diamonds"));
    std::cout << "Mano: As, Rey -> "; testPlayer.showHand(); // Debería ser 21

    testPlayer.clearHand();
    testPlayer.addCard(Card("A", "Spades"));
    testPlayer.addCard(Card("8", "Hearts"));
    testPlayer.addCard(Card("5", "Clubs"));
    std::cout << "Mano: As, 8, 5 -> "; testPlayer.showHand(); // Debería ser 14 (As como 1)


    // --- PRUEBAS DE LA CLASE DEALER ---
    std::cout << "\n--- Prueba: Clase Dealer ---" << std::endl;
    Dealer testDealer("Croupier Bob");
    Deck dealerDeck; // Nuevo mazo para el crupier

    testDealer.addCard(dealerDeck.drawCard());
    testDealer.addCard(dealerDeck.drawCard());
    testDealer.showHand(); // Mostrar mano del crupier y su puntaje

    // Prueba de la herencia: getName(), getScore(), clearHand()
    std::cout << "Nombre del crupier: " << testDealer.getName() << std::endl;
    std::cout << "Puntaje del crupier: " << testDealer.getScore() << std::endl;
    testDealer.clearHand();
    std::cout << "Mano del crupier limpiada. Ahora tiene " << testDealer.getScore() << " puntos.\n";


    std::cout << "\n--- Fin de Pruebas de Funciones ---" << std::endl;

    return 0;
}
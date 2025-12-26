#pragma once
#include "Player.h" // Incluimos Player para la herencia

class Dealer : public Player {
public:
    // Constructor de Dealer. Llama al constructor base de Player.
    Dealer(string name = "Crupier") : Player(name) {
        // No es necesario inicializar pName aquí si Player ya lo hace.
        // El valor por defecto "Crupier" es útil si no se especifica un nombre.
    }

    // Método para mostrar la mano del crupier al inicio del juego (una carta oculta)
    void showInitialHand() const {
        cout << pName << "'s hand:" << endl;
        if (hand.empty()) {
            cout << "  (Mano vacia)" << endl;
            return;
        }
        // Asumiendo que la primera carta es la oculta y la segunda es la visible
        cout << "  [Carta Oculta]" << endl;
        if (hand.size() > 1) {
            cout << "  "; // Pequeña indentación para la carta visible
            hand[1].showCard();
        }
        // No mostramos el puntaje aquí, ya que una carta está oculta.
        // Opcional: podrías mostrar solo el valor de la carta visible si eso es parte de tu regla.
        cout << endl; // Salto de línea para claridad
    }

    // Método para la lógica de "pedir" del crupier
    // Asume que se le pasa un mazo para robar cartas
    void playTurn(Deck& deck) {
        // El crupier revela su mano completa antes de empezar a pedir
        cout << "\n--- Turno del " << pName << " ---\n";
        showHand(); // Usa el showHand de Player para mostrar todo

        while (getScore() < 17) {
            cout << pName << " pide carta...\n";
            try {
                Card newCard = deck.drawCard();
                addCard(newCard); // Usa el addCard heredado
                cout << pName << " recibe: ";
                newCard.showCard();
                showHand(); // Muestra la mano actualizada
                if (getScore() > 21) {
                    cout << "¡" << pName << " se ha pasado (BUST)!" << endl;
                    break; // Crupier se pasó, termina su turno
                }
            }
            catch (const std::out_of_range& e) {
                std::cerr << "¡Mazo vacío! " << e.what() << std::endl;
                break; // No hay más cartas, termina el turno
            }
        }
        if (getScore() <= 21) {
            cout << pName << " se planta con " << getScore() << " puntos." << endl;
        }
    }

    // El método addCard heredado de Player es suficiente, no es necesario sobrescribirlo
    // unless you want special dealer-specific logic for adding cards.
    // void addCard(const Card& card) {
    //     hand.push_back(card);
    // }
};
#include "includes.h"
#include "deck.h"
std::vector<Card> deck;
void printDeck(const std::vector<Card>& DECK) {
    if (deck.empty()) {
        std::cout << "Deck is empty" << "\n";
    }
    else {
        for (auto card : deck)
            {
            std::cout << card.rank << card.suit << ", Value == " << card.value << ". \n";
        }
        std::cout << "\tCapacity: " << deck.capacity() << "Length: " << deck.size() << ". \n";
    }
}
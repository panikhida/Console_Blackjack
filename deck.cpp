#include "deck.h"
#include "includes.h"
std::vector<Card> deck (deck_size);

void printDeck(const std::vector<Card>& deck) {
    if (deck.empty()) {
        std::cout << "Deck is empty" << "\n";
    }
    else {
        for (auto card : deck)
            {
            std::cout << card.rank << card.suit << ", Value == " << card.value << ". \n";
            std::cout << "\tCapacity: " << deck.capacity() << "Length: " << deck.size() << ". \n";
        }
    }
}
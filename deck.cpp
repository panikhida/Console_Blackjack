#include "includes.h"
#include "deck.h"
void printDeck(const std::vector<Card>& d) {
    if (d.empty()) {
        std::cout << "Deck is empty" << "\n";
    }
    else {
        for (auto card : d)
            {
            std::cout << card.rank << card.suit << ", Value == " << card.value << ". \n";
        }
        std::cout << "\tCapacity: " << d.capacity() << "Length: " << d.size() << ". \n";
    }
}
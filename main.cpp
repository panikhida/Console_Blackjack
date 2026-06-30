#include "includes.h"
#include "deck.h"
int main() {
 std::cout << "CBlackjack \n";
 std::vector<Card> deck;
 fillDeck(deck);
 printDeck(deck);
 return 0;
}
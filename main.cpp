#include "includes.h"
#include "deck.h"

int main() {
 std::cout << "CBlackjack \n";

 // Rank card_rank1 { };
 // std::cout << "card_rank1(two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace) : ";
 // std::cin >> card_rank1;
 // std::cout << "Card rank is: " << card_rank1 << "\n";
 // std::cout << "It gives you " << getValue(card_rank1) << " points! \n";
 //deck
 std::vector<Card> deck;
 fillDeck(deck);
 printDeck(deck);
 return 0;
}
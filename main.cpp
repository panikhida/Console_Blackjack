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
 deck.resize(52);
 Card card1 {Rank::two, Suit::clubs};
 Card card2 {Rank::ten, Suit::hearts};
 Card card3 {Rank::jack, Suit::spades};
 Card card4 {Rank::ace, Suit::diamonds};
 Card card5 {Rank::seven, Suit::hearts};
 Card card6 {Rank::queen, Suit::clubs};
 deck.push_back(card1);
 deck.push_back(card2);
 deck.push_back(card3);
 deck.push_back(card4);
 deck.push_back(card5);
 deck.push_back(card6);
 fillDeck(deck);
 printDeck(deck);
 return 0;
}
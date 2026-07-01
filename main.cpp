#include "includes.h"
#include "deck.h"
int main() {
  Card card1 { Rank::eight, Suit::clubs };
  Card card2 { Rank::ten, Suit::diamonds };
  Card card3 { Rank::ace, Suit::clubs };
  std::cout << "CBlackjack \n";
  std::vector<Card> deck;
  std::vector<Card> deck_plr;
  fillDeck(deck);
  shuffleDeck(deck);
  printDeck(deck);
  insertCard(deck_plr, card3);
  insertCard(deck_plr, card3);
  insertCard(deck_plr, card3);
  insertCard(deck_plr, card3);
  insertCard(deck_plr, card3);
  insertCard(deck_plr, card3);
  printDeck(deck_plr);
  std::cout << calcDeckValue(deck_plr) << " -- deck value \n";
  return 0;
}
#ifndef CONSOLE_BLACKJACK_DECK_H
#define CONSOLE_BLACKJACK_DECK_H
#include "includes.h"
#include "Card.h"
void printDeck(const std::vector<Card>& d);
void fillDeck(std::vector<Card>& d);
void shuffleDeck(std::vector<Card>& d);
void giveCard(std::vector<Card>& d, std::vector<Card>& d2);
int calcDeckValue(const std::vector<Card>& d);
void insertCard(std::vector<Card>& d, Card card);
int calcDeckValue(const std::vector<Card>& d, int c);
#endif //CONSOLE_BLACKJACK_DECK_H

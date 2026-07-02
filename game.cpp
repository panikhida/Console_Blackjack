#include "includes.h"
#include "game.h"

bool hasUnextractedInput() {
    return !std::cin.eof() && std::cin.peek() != '\n';
}

void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getInt() {
    while (true) {
        int i{};
        std::cin >> i;

        if (!std::cin) {
            std::cin.clear();
            ignoreLine();
            std::cout << "Incorrect input, try again: ";
            continue;
        }
        ignoreLine();
        return i;
    }
}

void blackjack()
{
    int cash { 100 };
    std::vector<Card> deck;
    std::vector<Card> deck_plr;
    std::vector<Card> deck_dlr;
    while (cash > 0) {
        auto bid { 0 };
        fillDeck(deck);
        shuffleDeck(deck);
        std::cout << "\nRound started, your balance is " << cash << "$\nChoose your bid: ";
        bid = getInt();
        std::cout << ".\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\nYour bid is " << bid << "$\n\n\n\n";
        giveCard(deck, deck_plr);
        giveCard(deck, deck_plr);
        std::cout << "Deck shuffled... \nDealer gave you two cards: \n";
        printCard(deck_plr);
        std::cout << "It gives you " << calcDeckValue(deck_plr) << " points.";



        deck.clear();
        deck_plr.clear();
        deck_dlr.clear();
    }
}
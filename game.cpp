#include "includes.h"
#include "game.h"

bool hasUnextractedInput() {
    return !std::cin.eof() && std::cin.peek() != '\n';
}

void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool getBool() {
    while (true) {
        bool b{};
        std::cin >> b;
        if (!std::cin) {
            std::cin.clear();
            ignoreLine();
            std::cout << "Incorrect input, try again: ";
            continue;
        }
        ignoreLine();
        return b;
    }
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

int askIfContinue() {
    while (true) {
        int a;
        std::cin >> a;
        if (!std::cin || a > 1 || a < 0) {
            std::cin.clear();
            ignoreLine();
            std::cout << "Incorrect choice, try again (0|1, No|Yes): ";
            continue;
        }
        ignoreLine();
        return a;
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
        std::cout << "\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\nYour bid is " << bid << "$\n\n\n\n";
        giveCard(deck, deck_plr);
        giveCard(deck, deck_plr);
        std::cout << "Deck shuffled... \nDealer gave you two cards: \n";
        printCard(deck_plr);
        giveCard(deck, deck_dlr);
        giveCard(deck, deck_dlr);
        std::cout << "Dealer got two cards\n";
        std::cout << "Dealer opens one card\n";
        printCard(deck_dlr, 1);
        std::cout << "Your deck value is " << calcDeckValue(deck_plr);

        //end
        deck.clear();
        deck_plr.clear();
        deck_dlr.clear();
    }
}
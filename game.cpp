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
        bool b;
        std::cout << "Do you want to take a card? (0|1)";
        std::cin >> a;
        if (!std::cin || a > 1 || a < 0) {
            std::cin.clear();
            ignoreLine();
            std::cout << "Incorrect choice, try again (0|1): ";
            continue;
        }
        ignoreLine();
        if (a == 1) {
            b = true;
        }
        else {
        b = false;
        }
        return b;
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
        std::cout << "\nYour bid is " << bid << "$\n\n\n\n";
        giveCard(deck, deck_plr);
        giveCard(deck, deck_plr);
        std::cout << "Deck shuffled... \nDealer gave you two cards: \n";
        printCard(deck_plr);
        giveCard(deck, deck_dlr);
        giveCard(deck, deck_dlr);
        std::cout << "Dealer got two cards\n";
        std::cout << "Dealer opens one card\n";
        printCard(deck_dlr, 1);
        std::cout << "Your deck value is " << calcDeckValue(deck_plr) << " points\n";
        std::cout << "Dealer's visible deck value is " << calcDeckValue(deck_dlr, 1) << "\n";
            while (calcDeckValue(deck_plr) < 21) {
                if (askIfContinue()) {
                    giveCard(deck, deck_plr);
                    std::cout << "Dealer gave you a card:\n";
                    std::cout << "Your deck updated:\n";
                    printDeck(deck_plr, 'p');
                    std::cout << "Your deck value is " << calcDeckValue(deck_plr) << " points\n";
                    std::cout << "Dealer's visible deck value is " << calcDeckValue(deck_dlr, 1) << "\n";
                } else {
                    break;
                }
            }

        std::cout << "Quit getting cards...\n";

        std::cout << "The dealer opens another card:\n";
        printDeck(deck_dlr, 'd');
        std::cout << "Dealer has " << calcDeckValue(deck_dlr) << " points\n";
        while (calcDeckValue(deck_dlr) < 13) {
            std::cout << "It is less than 13, dealer takes another card.\n";
            giveCard(deck, deck_dlr);
            std::cout << "Dealer got a new card!, new dealer's deck value is " << calcDeckValue(deck_dlr);
        }

        //endgame
        std::cout << "\n";
        std::cout << "Calculating winner...\n";
        const int f_dlr {calcDeckValue(deck_dlr)};
        const int f_plr {calcDeckValue(deck_plr)};
        char winner { 'u' };
            if (f_dlr == 21 && f_plr != 21) {
                winner = 'd';
            }
            if (f_dlr < 21 && f_plr < f_dlr) {
                winner = 'd';
            }
            if (f_plr > 21) {
                winner = 'd';
            }
            if (f_plr == 21 && f_dlr != 21 && winner == 'u') {
                winner = 'p';
            }
            if (f_plr < 21 && f_dlr < f_plr && winner == 'u') {
                winner = 'p';
            }
            if (f_dlr == f_plr && winner == 'u') {
                winner = 't';
            }
            if (f_dlr > 21 && winner == 'u') {
            winner = 'p';
            }

        switch (winner) {
            case 'd':
                std::cout << "Dealer won, you lost your bid!\n";
                cash = cash - bid;
                break;
            case 'p':
                std::cout << "You won! You doubled your bid!\n";
                cash = cash + bid;
                break;
            default:
                std::cout << "It's a tie!\n";
                break;
        }
        //end
        deck.clear();
        deck_plr.clear();
        deck_dlr.clear();
    }
    std::cout << "Game ended.";
}
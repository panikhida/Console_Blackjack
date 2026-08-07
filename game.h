#ifndef CONSOLE_BLACKJACK_GAME_H
#define CONSOLE_BLACKJACK_GAME_H
#include "includes.h"
#include "deck.h"
#include "btui/includes/BTUI.h"

class BJ {
public:
    /*** Handlers ***/
    bool getBool();
    int askIfContinue();
    int getInt();
    int getInt(int mn, int mx);

    /*** Base ***/
    void initBlackJack();

    /*** Tools ***/
    void changeMoney(int m);
    void changeBid(int b);

private:
    int cash { 100 };
    int plr_win { 0 };
    int dlr_win { 0 };
    std::vector<Card> deck;
    std::vector<Card> deck_plr;
    std::vector<Card> deck_dlr;
};
#endif //CONSOLE_BLACKJACK_GAME_H

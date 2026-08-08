#ifndef CONSOLE_BLACKJACK_GAME_H
#define CONSOLE_BLACKJACK_GAME_H
#include "includes.h"
#include "deck.h"
// #include "btui/includes/BTUI.h"
class BTUI;
class BJ {
public:
    /*** Handlers ***/
    bool getBool();
    int askIfContinue();
    int getInt();
    int getInt(int mn, int mx);

    /*** Base ***/
    void initBlackJack();
    void playBJ();

    /*** Tools ***/
    void changeMoney(int m);
    void changeBid(int b);
    void addCash();
    void decreaseCash();
    void addBid();
    void decreaseBid();

    /*** State ***/
    enum State {
        s_begin,
        INIT,
        BID,
        PLAYER,
        END,
        s_end,
      };

    State curr_state {BID};
    int cash { 100 };
    int bid { 0 };

private:
    int plr_win { 0 };
    int dlr_win { 0 };
    std::vector<Card> deck;
    std::vector<Card> deck_plr;
    std::vector<Card> deck_dlr;
};
#endif //CONSOLE_BLACKJACK_GAME_H

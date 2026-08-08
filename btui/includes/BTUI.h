#ifndef CONSOLE_BLACKJACK_BTUI_H
#define CONSOLE_BLACKJACK_BTUI_H
#include "paints.h"
#include "settings.h"
#include <termios.h>
#include <string>
#include "../../game.h"

// btui class help me
class BTUI {
public:
    /*** Basic ***/
    ~BTUI();
    void initUI();
    static char readKey();
    void processKeypress();
    static void refreshScreen();
    static void die(const char* s);
    void linkGame(BJ* game);
    /*** Raw ***/
    void enableRaw();
    constexpr void disableRaw() const;

    /*** Buff ***/
    void bufAppend(std::string_view t);
    void bufAppend(int t);
    void bufAppend(Paint p);
    void bufClear();

    /*** Gets ***/
    static int getTSize(int* rows, int* columns);
    void checkSize();
    // int getCursorPos(int* rows, int* columns);

    /*** Paints ***/
    void setPaint(Paint paint);
    void renderUi();
    void nextPaint();
    void insertText(int r, int c, std::string_view str);
    void insertText(int r, int c, int n);


    /*** Color ***/
    static void resetClr();
    static void getClr();
    void setClr(int c);

    /*** Logic ***/
    void checkChoice(Paint p, char iKey);
    void updateMoney(int& m);

    std::string buf{};
    bool needRender{true};
    Paint p_curr;
    struct Config c;
    BJ* m_game {nullptr};

private:
    // std::size_t buf_s {2048};
    struct Params {
        int scrHeight{0};
        int scrLength{0};
        struct termios m_orig_termios {};
    };
#define BUF_INIT {NULL, 0}
    struct Params E;
};
#endif //CONSOLE_BLACKJACK_BTUI_H

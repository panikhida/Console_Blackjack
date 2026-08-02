#ifndef CONSOLE_BLACKJACK_BTUI_H
#define CONSOLE_BLACKJACK_BTUI_H
#include "formats.h"
#include <termios.h>

// btui class help me
class BTUI {
public:
    /*** basic ***/
    ~BTUI();
    void initUI();
    static char readKey();
    static void processKeypress();
    static void refreshScreen();
    static void die(const char* s);

    /*** gets ***/
    static int getTSize(int* rows, int* columns);
    // int getCursorPos(int* rows, int* columns);

    /*** paints ***/
    void p_drawLBorder(char c) const;
    void p_drawBox() const;

    /*** raw ***/
    void enableRaw();
    constexpr void disableRaw() const;

    /*** colors ***/
    static void resetClr();
    static void getClr();
    static void setClr(int c);

private:
    struct Config {
        int scrHeight{0};
        int scrLength{0};
        struct termios m_orig_termios {};
    };
    struct Buffer {
        char *b;
        int len;
    };
#define BUF_INIT {NULL, 0}
    struct Config E;
};
#endif //CONSOLE_BLACKJACK_BTUI_H

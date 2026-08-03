#ifndef CONSOLE_BLACKJACK_BTUI_H
#define CONSOLE_BLACKJACK_BTUI_H
#include "formats.h"
#include <termios.h>
#include <string>

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

    /*** buff ***/
    void bufAppend(std::string_view t);
    void bufClear();

    /*** gets ***/
    static int getTSize(int* rows, int* columns);
    // int getCursorPos(int* rows, int* columns);

    /*** paints ***/
    void p_drawLBorder(std::string_view c);
    void p_drawBox();
    void renderUi() const;
    /*** raw ***/
    void enableRaw();
    constexpr void disableRaw() const;

    /*** colors ***/
    static void resetClr();
    static void getClr();
    static void setClr(int c);

    std::string buf{};

private:
    // std::size_t buf_s {2048};

    struct Config {
        int scrHeight{0};
        int scrLength{0};
        struct termios m_orig_termios {};
    };
#define BUF_INIT {NULL, 0}
    struct Config E;
};
#endif //CONSOLE_BLACKJACK_BTUI_H

#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include "../includes/BTUI.h"
#include "sys/ioctl.h"
#include <string>
#include <string_view>
#include <vector>
#include "../../includes.h"
#include "../includes/paints.h"
using BJ::State::BID;
using BJ::State::PLAYER;
using BJ::State::INIT;
using BJ::State::END;
std::vector<Paint> g_paintsAll;
/*** basic ***/
BTUI::~BTUI() {
    disableRaw();
    buf.clear();
    std::string_view onex = "\x1b[0m\x1b[?25h\x1b[?1049l";
    write(STDOUT_FILENO, &onex, onex.size());
}
void BTUI::initUI() {
    write(STDOUT_FILENO, "\x1b[?1049h\x1b[?25l\x1b[32m", 15);
    if (getTSize(&E.scrHeight, &E.scrLength) == -1) die("getSize");
    buf.reserve(4096);
    bufAppend("\x1b[32m");
    for (int r {0}; r < std::to_underlying(Paint::p_end); ++r) {
        Paint paint;
        paint = static_cast<Paint>(r);
        g_paintsAll.push_back(paint);
    }
    p_curr = Paint::p_main;
}
char BTUI::readKey() {
    char c = '\0';
    ssize_t nread = read(STDIN_FILENO, &c, 1);

        if (nread == -1 && errno != EAGAIN) {
            die("read");
        }
    return (nread == 1) ? c : '\0';
}
void BTUI::processKeypress() {
    const char cc = readKey();
    if (cc == '\0') return;
    switch (cc) {
        case CTRL('q'): {
            buf.clear();
            write(STDOUT_FILENO, "\x1b[2J", 4);
            write(STDOUT_FILENO,"\x1b[H", 3);
            write(STDOUT_FILENO, "\x1b[0m\x1b[?25h\x1b[?1049l", 19);
            disableRaw();
            exit(0);
        }
            case CTRL('a'): {
            nextPaint();
        }
            case ('1'):case ('2'):case ('3'):case ('4'):case ('5'):case ('6'):case ('7'):case ('8'):case ('9'): case('0'):
            checkChoice(p_curr, cc);
            default:
        break;
    }
}
void BTUI::refreshScreen() {
    write(STDOUT_FILENO,"\x1b[H", 3);
}
void BTUI::die(const char* s) {
    write(STDOUT_FILENO, "\x1b[2J", 4);
    write(STDOUT_FILENO,"\x1b[H", 3);
    write(STDOUT_FILENO, "\x1b[?25h", 4);

    perror(s);
    exit(1);
}
void BTUI::linkGame(BJ* game) {
    m_game = game;
}
/*** raw ***/
void BTUI::enableRaw() {
    if (tcgetattr(STDIN_FILENO, &E.m_orig_termios) == -1) die("tcgetattr");
    tcgetattr(STDIN_FILENO, &E.m_orig_termios);
    struct termios raw = E.m_orig_termios;

    tcgetattr(STDIN_FILENO, &raw);
    raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    raw.c_oflag &= ~(OPOST);
    raw.c_cflag &= ~(CS8);
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1;

    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) die("tcsetattr");
}
constexpr void BTUI::disableRaw() const {
    tcsetattr (STDIN_FILENO, TCSAFLUSH, &E.m_orig_termios);
}

/*** Buffer ***/
void BTUI::bufAppend(std::string_view t) {
   buf.append(t);
}
void BTUI::bufAppend(int t) {
    std::string text;
    text += std::to_string(t);
    buf.append(text);
}
void BTUI::bufAppend(Paint p) {
    std::string text;
    text += getPaint(p, E.scrHeight, E.scrLength);
    buf.append(text);
}
void BTUI::bufClear() {
    buf.clear();
    write(STDOUT_FILENO, "\x1b[H", 3);
    bufAppend("\x1b[32m");
}

/*** Gets ***/
int BTUI::getTSize(int *height, int *length) {
    struct winsize ws {};

    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0) {
        return -1;
    } else {
        *length = ws.ws_col;
        *height = ws.ws_row;
        return 0;
    }
}
void BTUI::checkSize() {
    int nH, nL;
    if (getTSize(&nH, &nL) == 0) {
        if (nH != E.scrHeight || nL != E.scrLength) {
            E.scrHeight = nH;
            E.scrLength = nL;

            bufClear();
            bufAppend(p_curr);
            needRender = true;
        }
    }
}
std::string_view nl {"\r\n"};

/*** Paints ***/
void BTUI::setPaint(Paint paint) {
    switch (paint) {
        case(Paint::p_begin): {
            bufClear();
            bufAppend(getPaint(Paint::p_begin, E.scrHeight, E.scrLength));
            needRender = true;
            p_curr = Paint::p_begin;

            break;
        }
        case(Paint::p_main): {
            bufClear();
            bufAppend(getPaint(Paint::p_main, E.scrHeight, E.scrLength));
            needRender = true;
            p_curr = Paint::p_main;

            break;
        }

        case(Paint::p_game): {
            bufClear();
            bufAppend(getPaint(Paint::p_game, E.scrHeight, E.scrLength));
            needRender = true;
            p_curr = Paint::p_game;

            break;
        }

        case(Paint::p_settings): {
            bufClear();
            bufAppend(getPaint(Paint::p_settings, E.scrHeight, E.scrLength));
            needRender = true;
            p_curr = Paint::p_settings;

            break;
        }

        case(Paint::p_history): {
            bufClear();
            bufAppend(getPaint(Paint::p_history, E.scrHeight, E.scrLength));
            needRender = true;
            p_curr = Paint::p_history;

            break;
        }

        default:
            break;
    }
}
void BTUI::renderUi() {
    refreshScreen();
    write(STDOUT_FILENO, "\x1b[H", 3);
    write(1, buf.data(), buf.size());
    needRender = false;
}
void BTUI::nextPaint() {
    bufClear();

    int p_c {static_cast<int>(p_curr)};
    int p_n{};

    if (p_c + 1 >= static_cast<int>(Paint::p_end) || p_c >= static_cast<int>(Paint::p_end)) {
        p_n = static_cast<int>(Paint::p_main);
    } else {
        p_n = p_c + 1;
    }
    p_curr = static_cast<Paint>(p_n);
    bufAppend(p_curr);
    needRender = true;
}
void BTUI::insertText(int rows, int colns, std::string_view str) {
    std::string text{"\x1b["};
    text += std::to_string(rows);
    text += ";";
    text += std::to_string(colns);
    text += "H";
    text += str;
    bufAppend(text);
    needRender = true;
}
void BTUI::insertText(int r, int co, int n) {
    std::string text{"\x1b["};
    text += std::to_string(r);
    text += ";";
    text += std::to_string(co);
    text += "H";
    text += std::to_string(n);
    bufAppend(text);
    needRender = true;
}

/*** Color ***/
void BTUI::resetClr() {
    write(STDOUT_FILENO, "\x1b[0m", 4);
}
void BTUI::getClr() {
    std::cout << "setclr wip";
}
void BTUI::setClr(int clr) {
    bufAppend("\x1b[");
    bufAppend(std::to_string(clr));
    bufAppend("m");
}

/*** Logic ***/
void BTUI::checkChoice(Paint cur_paint, char iKey) {

    switch (iKey) {
        case '1': {
            switch (cur_paint) {
                case Paint::p_main: {
                    nextPaint();
                    m_game->curr_state = BID;
                    break;
                }

                case Paint::p_game: {
                    switch (m_game->curr_state == BID) {
                        case true:
                            bufAppend("\x1b[");
                            bufAppend(E.scrHeight - 3);
                            bufAppend(";");
                            bufAppend(10);
                            bufAppend(std::to_string(m_game->cash));
                            bufAppend("H");
                            m_game->addCash();
                            needRender = true;
                            break;
                    }
                }
                default:
                    break;
            }
            default:
            break;
        }
    }

}
void BTUI::updateMoney(int& m) {
    buf.clear();
    setPaint(Paint::p_game);
    insertText(9, E.scrHeight - 3, m);
}
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
    int nread;
    char c = '\0';
    while ((nread = read(STDIN_FILENO, &c, 1)) !=1) {
        if (nread == -1 && errno != EAGAIN) {
            die("read");
        }
    }
    return c;
}
void BTUI::processKeypress() {
    char c = readKey();
    if (c == '\0') return;
    switch (c) {
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
        default:
        break;
    }
}
void BTUI::refreshScreen() {
    write(STDOUT_FILENO, "\x1b[2J", 4);
    write(STDOUT_FILENO,"\x1b[H", 3);
}
void BTUI::die(const char* s) {
    write(STDOUT_FILENO, "\x1b[2J", 4);
    write(STDOUT_FILENO,"\x1b[H", 3);
    write(STDOUT_FILENO, "\x1b[?25h", 4);

    perror(s);
    exit(1);
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
    text += getPaint(p);
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

std::string_view nl {"\r\n"};

void BTUI::p_drawBox() {
    buf.clear();
    std::string_view welcome {"BlackJack"};
    bufAppend("\x1b[32m");
    bufAppend("╭");

    for (int y{0}; y < E.scrLength - 2; ++y) bufAppend("━");
    bufAppend("╮\r\n");
    for (int y{0}; y < E.scrHeight - 2; ++y) {
        bufAppend("|");
        for (int s{0}; s < E.scrLength - welcome.size() - 2; ++s) {
            bufAppend(".");
            if (s == E.scrLength / 2 - welcome.size() / 2 - 2) {
                bufAppend(welcome);
            }
        }
        bufAppend("|\r\n");
    }
    bufAppend("╰");
    for (int y{0}; y < E.scrLength - 2; ++y) bufAppend("━");
    bufAppend("╯");
    needRender = true;

}

/*** Paints ***/
void BTUI::setPaint(Paint paint) {
    switch (paint) {
        case(Paint::p_main): {
            bufClear();
            bufAppend(getPaint(Paint::p_main));
            needRender = true;
            p_curr = Paint::p_main;

            break;
        }

        case(Paint::p_game): {
            bufClear();
            bufAppend(getPaint(Paint::p_game));
            needRender = true;
            p_curr = Paint::p_game;

            break;
        }

        case(Paint::p_settings): {
            bufClear();
            bufAppend(getPaint(Paint::p_settings));
            needRender = true;
            p_curr = Paint::p_settings;

            break;
        }

        case(Paint::p_history): {
            bufClear();
            bufAppend(getPaint(Paint::p_history));
            needRender = true;
            p_curr = Paint::p_history;

            break;
        }

        default:
            break;
    }
}
void BTUI::p_drawLBorder(std::string_view c)  {
    for (int y{0}; y < E.scrHeight;++y) {
        bufAppend(c);
        if (y < E.scrHeight - 1) {
            bufAppend(nl);
        }
    }
    bufAppend("\x1b[H");
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
        p_n = static_cast<int>(Paint::p_begin);
    } else {
        p_n = p_c + 1;
    }
    p_curr = static_cast<Paint>(p_n);
    bufAppend(p_curr);
    needRender = true;
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
/*** Color ***/
void BTUI::resetClr() {
    write(STDOUT_FILENO, "\x1b[0m", 4);
}
void BTUI::getClr() {
    std::cout << "setclr wip";
}
void BTUI::setClr(int c) {
}
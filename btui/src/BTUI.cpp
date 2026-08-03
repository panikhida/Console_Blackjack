#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include "../includes/BTUI.h"
#include "sys/ioctl.h"
#include <string>
#include <string_view>

/*** basic ***/
BTUI::~BTUI() {
    disableRaw();
}
void BTUI::initUI() {
    if (getTSize(&E.scrHeight, &E.scrLength) == -1) die("getSize");
    buf.reserve(4096);
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
    switch (readKey()) {
        case CTRL('q'):
            write(STDOUT_FILENO, "\x1b[2J", 4);
            write(STDOUT_FILENO,"\x1b[H", 3);

            exit(0);
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

    perror(s);
    exit(1);
}

/*** Buffer ***/
void BTUI::bufAppend(std::string_view t) {
   buf.append(t);
}

void BTUI::bufClear() {
    buf.erase();
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
/*** Paints ***/
void BTUI::p_drawLBorder(std::string_view c)  {
    for (int y{0}; y < E.scrHeight;++y) {
        bufAppend(c);
        if (y < E.scrHeight - 1) {
            bufAppend(nl);
        }
    }
    bufAppend("\x1b[H");
}
void BTUI::p_drawBox() const {
    write(STDOUT_FILENO, "╭", 4);

    for (int y{0}; y < E.scrLength * 2 - 4; ++y) {
        write(STDOUT_FILENO, "━", 4);
        ++y;
    }
    write(STDOUT_FILENO, "╮", 4);
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
        if (tcsetattr (STDIN_FILENO, TCSAFLUSH, &E.m_orig_termios) == -1)
            die("tcsetattr");
    }

/*** Color ***/
void BTUI::resetClr() {
    std::cout << "\x1b[0m";
}
void BTUI::getClr() {
    std::cout << "setclr wip";
}
void BTUI::setClr(int c) {
    std::cout << "\x1b["<<c<<"m\r\n";
}
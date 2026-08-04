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
    buf.clear();
    std::string_view onex = "\x1b[0m\x1b[?25h\x1b[?1049l";
    write(STDOUT_FILENO, &onex, onex.size());
}
void BTUI::initUI() {
    write(STDOUT_FILENO, "\x1b[?1049h\x1b[?25l\x1b[32m", 15);
    if (getTSize(&E.scrHeight, &E.scrLength) == -1) die("getSize");
    buf.reserve(4096);
    bufAppend("\x1b[32m");
}
char BTUI::readKey() {
    int nread;
    char c = '\0';
    while ((nread = read(STDIN_FILENO, &c, 1)) !=1) {
        if (nread == -1 && errno != EAGAIN) {
            die("read");
        }
    }
    return (nread == 1) ? c : '\0';
}
void BTUI::processKeypress() {
    char cc = readKey();
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
void BTUI::p_drawLBorder(std::string_view c)  {
    for (int y{0}; y < E.scrHeight;++y) {
        bufAppend(c);
        if (y < E.scrHeight - 1) {
            bufAppend(nl);
        }
    }
    bufAppend("\x1b[H");
}

void BTUI::renderUi() const{
    refreshScreen();
    write(STDOUT_FILENO, "\x1b[H", 3);
    write(1, buf.data(), buf.size());
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
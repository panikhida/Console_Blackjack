#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include "../includes/BTUI.h"
void BTUI::die(const char* s) {
        perror(s);
        exit(1);
    }

     void BTUI::enableRaw() {
         if (tcgetattr(STDIN_FILENO, &m_orig_termios) == -1) die("tcgetattr");
        tcgetattr(STDIN_FILENO, &m_orig_termios);
         struct termios raw = m_orig_termios;

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
        if (tcsetattr (STDIN_FILENO, TCSAFLUSH, &m_orig_termios) == -1)
            die("tcsktattr");
    }

void BTUI::getClr() {
    std::cout << "setclr wip";
}

void BTUI::setClr() {
    std::cout << "setclr wip";
}

BTUI::~BTUI() {
         disableRaw();
     }
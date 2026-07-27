#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <cerrno>
#include <cctype>
#include "BTUI.h"
    void BTUI::die(const char* s) {
        perror(s);
        exit(1);
    }

     void BTUI::enableRaw() {
         tcgetattr(STDIN_FILENO, &m_orig_termios);
         struct termios raw = m_orig_termios;

         tcgetattr(STDIN_FILENO, &raw);
         raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
         raw.c_oflag &= ~(OPOST);
         raw.c_cflag &= ~(CS8);
         raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
         raw.c_cc[VMIN] = 0;
         raw.c_cc[VTIME] = 1;

        tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
    }

    void BTUI::disableRaw() {
         tcsetattr(STDIN_FILENO, TCSAFLUSH, &m_orig_termios);
     }

    BTUI::~BTUI() {
         disableRaw();
     }
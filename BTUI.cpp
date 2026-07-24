#include <iostream>
#include <termios.h>
#include <unistd.h>

#include "BTUI.h"
     void BTUI::enableRaw() {
        tcgetattr(STDIN_FILENO, &m_orig_termios);
        struct termios raw = m_orig_termios;
        tcgetattr(STDIN_FILENO, &raw);
        raw.c_lflag &= ~(ECHO);

        tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
    }

    void BTUI::disableRaw() {
         tcsetattr(STDIN_FILENO, TCSAFLUSH, &m_orig_termios);
     }

    BTUI::~BTUI() {
         disableRaw();
     }
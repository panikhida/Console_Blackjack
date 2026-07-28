#ifndef CONSOLE_BLACKJACK_BTUI_H
#define CONSOLE_BLACKJACK_BTUI_H
#include <termios.h>

// btui class help me
class BTUI {
        public:
            ~BTUI();
            void die(const char* s);
            void enableRaw();
            void disableRaw();
            // wip
            void 
            void getClr();
            void setClr();
        private:
    struct termios m_orig_termios {};
};

#endif //CONSOLE_BLACKJACK_BTUI_H

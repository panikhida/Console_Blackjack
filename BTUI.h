#ifndef CONSOLE_BLACKJACK_BTUI_H
#define CONSOLE_BLACKJACK_BTUI_H
#include <termios.h>
class BTUI {
        public:
            ~BTUI();
            void enableRaw();
            void disableRaw();
        private:
    struct termios m_orig_termios {};
};

#endif //CONSOLE_BLACKJACK_BTUI_H

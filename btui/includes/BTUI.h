#ifndef CONSOLE_BLACKJACK_BTUI_H
#define CONSOLE_BLACKJACK_BTUI_H
#include "formats.h"
#include <termios.h>

// btui class help me
class BTUI {
        public:
            ~BTUI();
            static void die(const char* s);
            void enableRaw();
            constexpr void disableRaw() const;

            static void resetClr();
            static void getClr();
            static void setClr(int c);
        private:
    struct termios m_orig_termios {};
};

#endif //CONSOLE_BLACKJACK_BTUI_H

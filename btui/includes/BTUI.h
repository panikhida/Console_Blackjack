#ifndef CONSOLE_BLACKJACK_BTUI_H
#define CONSOLE_BLACKJACK_BTUI_H
#include <termios.h>

// btui class help me
class BTUI {
        public:
            ~BTUI();
            static void die(const char* s);
            void enableRaw();
            constexpr void disableRaw() const;
            // wip
            static void getClr();
            static void setClr();
        private:
    struct termios m_orig_termios {};
};

#endif //CONSOLE_BLACKJACK_BTUI_H

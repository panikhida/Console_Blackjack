#ifndef CONSOLE_BLACKJACK_SETTINGS_H
#define CONSOLE_BLACKJACK_SETTINGS_H
#include "formats.h"

struct Config {
    bool debugMode{false};
    Color uiColor {Color::green};
};
#endif //CONSOLE_BLACKJACK_SETTINGS_H

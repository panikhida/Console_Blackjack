#ifndef CONSOLE_BLACKJACK_PAINTS_H
#define CONSOLE_BLACKJACK_PAINTS_H
#include <string>
std::string text;
enum class Paint {
    p_begin,
    p_main,
    p_game,
    p_settings,
    p_history,
    p_end
};
constexpr std::string_view getPaint(Paint paint) {
    switch (paint) {
        case Paint::p_begin: {
            /*     buf.clear();
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
    needRender = true;*/
            text += "\x1b[32m";

            return text;
        }
        case Paint::p_main: {
            return "main\r\n1";
        }
        case Paint::p_game: {
            return "game\r\n2";
        }
        case Paint::p_settings: {
            return "settings\r\n3";
        }
        case Paint::p_history: {
            return "history\r\n4";
        }
        case Paint::p_end: {
            return "wrong painting. paint - end";
        }
        default:
            return "painting error";
            break;
    }
}
#endif //CONSOLE_BLACKJACK_PAINTS_H

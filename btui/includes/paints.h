#ifndef CONSOLE_BLACKJACK_PAINTS_H
#define CONSOLE_BLACKJACK_PAINTS_H
#include <iomanip>
#include <string>
enum class Paint {
    p_begin,
    //
    p_main,
    p_game,
    p_settings,
    p_history,
    //
    p_end,
};
inline std::string getPaint(Paint paint, int scrHeight, int scrLength) {
    std::string text;
    text += "\x1b[32m"; //colur
    text += "╭";
    for (int y{0}; y < scrLength - 2; ++y) text +=("━");
    text += "╮\r\n";
    for (int y{0}; y < scrHeight - 2; ++y) {
        text += ("|");
        for (int s{0}; s < scrLength - 2; ++s) {
            text += (" ");
        }
        text += ("|\r\n");
    }
    text += ("╰");
    for (int y{0}; y < scrLength - 2; ++y) text += ("━");
    text += ("╯");

    switch (paint) {
        case Paint::p_begin: {
            text += "\x1b[" + std::to_string(1) + ";" + std::to_string(3) + "H404";
            text += "\x1b[" + std::to_string(scrLength - 3) + ";" + std::to_string(scrHeight - 3) + "HBlackJack";
            // insides



            return text;
        }
        case Paint::p_main: {
            text += "\x1b[" + std::to_string(1) + ";" + std::to_string(3) + "HMain";
            text += "\x1b[" + std::to_string(scrLength - 3) + ";" + std::to_string(scrHeight - 3) + "HBlackJack";
            // insides



            return text;
        }
        case Paint::p_game: {
            text += "\x1b[1;3HGame";
            text += "\x1b[" + std::to_string(scrLength - 3) + ";" + std::to_string(scrHeight - 3) + "HBlackJack";
            // insides

            text += "\x1b[" + std::to_string(scrHeight - 3) + ";3HMoney: ";
            text += "\x1b[" + std::to_string(scrHeight - 4) + ";2H";
            for (int p {0}; p < scrLength - 2; ++p) text += "-";
            // vertial line in the middle
            text += "\x1b[" + std::to_string(scrHeight - 3) + ";" + std::to_string(scrLength / 2 ) + "H|" ;;
            text += "\x1b[" + std::to_string(scrHeight - 2) + ";" + std::to_string(scrLength / 2 ) + "H|" ;;
            text += "\x1b[" + std::to_string(scrHeight - 1) + ";" + std::to_string(scrLength / 2 ) + "H|" ;;
            return text;
        }
        case Paint::p_settings: {
            text += "\x1b[" + std::to_string(1) + ";" + std::to_string(3) + "HSettings";
            text += "\x1b[" + std::to_string(scrHeight) + ";2HBlackJack";
            // insides



            return text;
        }
        case Paint::p_history: {
            text += "\x1b[" + std::to_string(1) + ";" + std::to_string(3) + "HHistory";
            text += "\x1b[" + std::to_string(scrLength - 3) + ";" + std::to_string(scrHeight - 3) + "HBlackJack";
            // insides



            return text;
        }
        case Paint::p_end: {
            text += "\x1b[" + std::to_string(1) + ";" + std::to_string(3) + "HResults";
            text += "\x1b[" + std::to_string(scrHeight - 3) + ";" + std::to_string(scrLength - 3) + "HBlackJack";
            // insides



            return text;
        }
        default:
            text += "\x1b[" + std::to_string(1) + ";" + std::to_string( 3) + "H404";
            text += "\x1b[" + std::to_string(scrHeight - 3) + ";" + std::to_string(scrLength - 3) + "HBlackJack";
            // insides



            return text;
    }
}
#endif //CONSOLE_BLACKJACK_PAINTS_H

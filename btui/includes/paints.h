#ifndef CONSOLE_BLACKJACK_PAINTS_H
#define CONSOLE_BLACKJACK_PAINTS_H
#include <string>

enum class Paint {
    p_begin,
    p_main,
    p_game,
    p_settings,
    p_history,
    p_end
};
inline std::string getPaint(Paint paint, int scrHeight, int scrLength) {
    switch (paint) {
        case Paint::p_begin: {
            std::string text;
            text += "\x1b[32m"; //colur
            text += "╭";
            std::string_view welcome {"BlackJack"};

            for (int y{0}; y < scrLength - 2; ++y) text +=("━");
            text += "╮\r\n";
            for (int y{0}; y < scrHeight - 2; ++y) {
                text += ("|");
                for (int s{0}; s < scrLength - welcome.size() - 2; ++s) {
                    text += (".");
                    if (s == scrLength / 2 - welcome.size() / 2 - 2) {
                        text += (welcome);
                    }
                }
                text += ("|\r\n");
            }
            text += ("╰");
            for (int y{0}; y < scrLength - 2; ++y) text += ("━");
            text += ("╯");
            return text;
        }
        case Paint::p_main: {
            std::string text;
            text += "\x1b[32m"; //colur
            text += "╭";
            std::string_view welcome {"Main"};

            for (int y{0}; y < scrLength - 2; ++y) text +=("━");
            text += "╮\r\n";
            for (int y{0}; y < scrHeight - 2; ++y) {
                text += ("|");
                for (int s{0}; s < scrLength - welcome.size() - 2; ++s) {
                    text += (".");
                    if (s == scrLength / 2 - welcome.size() / 2 - 2) {
                        text += (welcome);
                    }
                }
                text += ("|\r\n");
            }
            text += ("╰");
            for (int y{0}; y < scrLength - 2; ++y) text += ("━");
            text += ("╯");
            return text;
        }
        case Paint::p_game: {
            std::string text;
            text += "\x1b[32m"; //colur
            text += "╭";
            std::string_view welcome {"Game"};

            for (int y{0}; y < scrLength - 2; ++y) text +=("━");
            text += "╮\r\n";
            for (int y{0}; y < scrHeight - 2; ++y) {
                text += ("|");
                for (int s{0}; s < scrLength - welcome.size() - 2; ++s) {
                    text += (".");
                    if (s == scrLength / 2 - welcome.size() / 2 - 2) {
                        text += (welcome);
                    }
                }
                text += ("|\r\n");
            }
            text += ("╰");
            for (int y{0}; y < scrLength - 2; ++y) text += ("━");
            text += ("╯");
            return text;        }
        case Paint::p_settings: {
            std::string text;
            text += "\x1b[32m"; //colur
            text += "╭";
            std::string_view welcome {"Settings"};

            for (int y{0}; y < scrLength - 2; ++y) text +=("━");
            text += "╮\r\n";
            for (int y{0}; y < scrHeight - 2; ++y) {
                text += ("|");
                for (int s{0}; s < scrLength - welcome.size() - 2; ++s) {
                    text += (".");
                    if (s == scrLength / 2 - welcome.size() / 2 - 2) {
                        text += (welcome);
                    }
                }
                text += ("|\r\n");
            }
            text += ("╰");
            for (int y{0}; y < scrLength - 2; ++y) text += ("━");
            text += ("╯");
            return text;        }
        case Paint::p_history: {
            std::string text;
            text += "\x1b[32m"; //colur
            text += "╭";
            std::string_view welcome {"History"};

            for (int y{0}; y < scrLength - 2; ++y) text +=("━");
            text += "╮\r\n";
            for (int y{0}; y < scrHeight - 2; ++y) {
                text += ("|");
                for (int s{0}; s < scrLength - welcome.size() - 2; ++s) {
                    text += (".");
                    if (s == scrLength / 2 - welcome.size() / 2 - 2) {
                        text += (welcome);
                    }
                }
                text += ("|\r\n");
            }
            text += ("╰");
            for (int y{0}; y < scrLength - 2; ++y) text += ("━");
            text += ("╯");
            return text;        }
        case Paint::p_end: {
            std::string text;
            text += "\x1b[32m"; //colur
            text += "╭";
            std::string_view welcome {"End"};

            for (int y{0}; y < scrLength - 2; ++y) text +=("━");
            text += "╮\r\n";
            for (int y{0}; y < scrHeight - 2; ++y) {
                text += ("|");
                for (int s{0}; s < scrLength - welcome.size() - 2; ++s) {
                    text += (".");
                    if (s == scrLength / 2 - welcome.size() / 2 - 2) {
                        text += (welcome);
                    }
                }
                text += ("|\r\n");
            }
            text += ("╰");
            for (int y{0}; y < scrLength - 2; ++y) text += ("━");
            text += ("╯");
            return text;        }
        default:
            std::string text;
            text += "\x1b[32m"; //colur
            text += "╭";
            std::string_view welcome {"Default"};

            for (int y{0}; y < scrLength - 2; ++y) text +=("━");
            text += "╮\r\n";
            for (int y{0}; y < scrHeight - 2; ++y) {
                text += ("|");
                for (int s{0}; s < scrLength - welcome.size() - 2; ++s) {
                    text += (".");
                    if (s == scrLength / 2 - welcome.size() / 2 - 2) {
                        text += (welcome);
                    }
                }
                text += ("|\r\n");
            }
            text += ("╰");
            for (int y{0}; y < scrLength - 2; ++y) text += ("━");
            text += ("╯");
            return text;    }
}
#endif //CONSOLE_BLACKJACK_PAINTS_H

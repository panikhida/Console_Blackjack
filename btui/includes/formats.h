#ifndef CONSOLE_BLACKJACK_FORMATS_H
#define CONSOLE_BLACKJACK_FORMATS_H
#include <string_view>
    enum class Color {
        black,
        red,
        green,
        yellow,
        blue,
        purple,
        cyan,
        white
    };

    constexpr unsigned int Clr(Color color) {
        switch (color) {
            case Color::black:
                return 30;
            case Color::red:
                return 31;
            case Color::green:
                return 32;
            case Color::yellow:
                return 33;
            case Color::blue:
                return 34;
            case Color::purple:
                return 35;
            case Color::cyan:
                return 36;
            case Color::white:
            default:
                return 37;
        }
    }

// enum class Type {
//     bold,
//     underline,
// };

// constexpr int getType(Type type) {
//     switch (type) {
//         case Type::bold:
//             return "1";
//         case Type::underline:
//             return "4";
//     }
// }
#endif //CONSOLE_BLACKJACK_FORMATS_H

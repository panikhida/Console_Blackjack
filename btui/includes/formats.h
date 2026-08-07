#ifndef CONSOLE_BLACKJACK_FORMATS_H
#define CONSOLE_BLACKJACK_FORMATS_H
    enum class Color {
        c_begin,
        black,
        red,
        green,
        yellow,
        blue,
        purple,
        cyan,
        white,
        c_end
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
                return 0;
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

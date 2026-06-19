#ifndef CONSOLE_BLACKJACK_HEADER_H
#define CONSOLE_BLACKJACK_HEADER_H
#include <string_view>
#include <optional>

    enum class Suit {spades, diamonds, hearts, clubs};
constexpr std::string_view getSuit(Suit suit) {
    switch (suit) {
        case Suit::spades:
            return "♠";
        case Suit::clubs:
            return "♣";
        case Suit::diamonds:
            return "♦";
        case Suit::hearts:
            return "♥";
        default:
            return "No suit found";
    }
}
constexpr std::optional<Suit> getSuitInput(std::string_view sv) {
    if (sv == "spades") return Suit::spades;
    if (sv == "clubs") return Suit::clubs;
    if (sv == "diamonds") return Suit::diamonds;
    if (sv == "hearts") return Suit::hearts;
    return {};
}
std::ostream& operator<<(std::ostream& out, Suit suit);
std::istream& operator>>(std::istream& in, Suit& suit);

    enum class Rank {two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};
constexpr std::string_view getRank(Rank rank)
{
    switch (rank) {
        case Rank::two:
            return "2";
        case Rank::three:
            return "3";
        case Rank::four:
            return "4";
        case Rank::five:
            return "5";
        case Rank::six:
            return "6";
        case Rank::seven:
            return "7";
        case Rank::eight:
            return "8";
        case Rank::nine:
            return "9";
        case Rank::ten:
            return "10";
        case Rank::jack:
            return "J";
        case Rank::queen:
            return "Q";
        case Rank::king:
            return "K";
        case Rank::ace:
            return "A";
        default:
            return "No rank found";
    }
}
constexpr std::optional<Rank> getRankInput(std::string_view sv) {
    if (sv == "two") return Rank::two;
    if (sv == "three") return Rank::three;
    if (sv == "four") return Rank::four;
    if (sv == "five") return Rank::five;
    if (sv == "six") return Rank::six;
    if (sv == "seven") return Rank::seven;
    if (sv == "eight") return Rank::eight;
    if (sv == "nine") return Rank::nine;
    if (sv == "ten") return Rank::ten;
    if (sv == "jack") return Rank::jack;
    if (sv == "queen") return Rank::queen;
    if (sv == "king") return Rank::king;
    if (sv == "ace") return Rank::ace;
    return {};
}
std::ostream& operator<<(std::ostream& out, Rank rank);
std::istream& operator>>(std::istream& in, Rank& rank);

//get points
int getValue(Rank rank);
#endif //CONSOLE_BLACKJACK_HEADER_H

// struct
struct Card {
    Rank rank {};
    Suit suit {};
    int value = getValue(rank);
};

void printCard(Card card);
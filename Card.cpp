#include "includes.h"
#include "Card.h"
// ----------------------- translators overloads
    //rank op<<
    std::ostream& operator<<(std::ostream& out, Rank rank)
    {
        out << getRank(rank);
        return out;
    }
    //rank op>>
    std::istream& operator>>(std::istream& in, Rank& rank)
    {
        std::string s{ };
        in >> s;
        std::optional<Rank> match {getRankInput(s)};
        if (match)
        {
        rank = *match;
            return in;
        }
        in.setstate(std::ios_base::failbit);
        return in;
    }
    //suit op<<
    std::ostream& operator<<(std::ostream& out, Suit suit)
    {
        out << getSuit(suit);
        return out;
    }
    //suit op>>
    std::istream& operator>>(std::istream& in, Suit& suit)
    {
        std::string s{};
        in >> s;

        std::optional<Suit> match { getSuitInput(s) };
        if (match) {
            suit = *match;
            return in;
        }
        in.setstate(std::ios_base::failbit);
        return in;
    }

    //overload +suit
template<typename T>
constexpr auto operator+(T e) noexcept {
        return static_cast<std::underlying_type_t<T>>(e);
    }
// ----------------------- translators overloads end

//get value
int getValue(Rank rank) {
    switch (rank) {
        case Rank::jack:
        case Rank::queen:
        case Rank::king:
        case Rank::ten:
            return 10;
        case Rank::ace:
            return 11;
        default:
            return +rank;
    }
}
int getValue(Suit suit) {
        switch (suit) {
            default:
                return +suit;
        }
    }

void printCard(Card card) {
        std::cout << getRank(card.rank) << std::endl;
        if (card.rank == Rank::ten) {
            std::cout << "┌───────┐\n";
            std::cout << "│ " << getRank(card.rank) << "    │\n";
            std::cout << "│   " << getSuit(card.suit) << "   │\n" ;
            std::cout << "│    " << getRank(card.rank) << " │\n";
            std::cout << "└───────┘\n" ;
        }
        else {
            std::cout << "┌───────┐\n";
            std::cout << "│ " << getRank(card.rank) << "     │\n";
            std::cout << "│   " << getSuit(card.suit) << "   │\n" ;
            std::cout << "│     " << getRank(card.rank) << " │\n";
            std::cout << "└───────┘\n" ;
        }
    }
void printCard(const std::vector<Card>& d) {
        for (Card card : d) {
            if (card.rank == Rank::ten) {
                std::cout << "┌───────┐\n";
                std::cout << "│ " << getRank(card.rank) << "    │\n";
                std::cout << "│   " << getSuit(card.suit) << "   │\n" ;
                std::cout << "│    " << getRank(card.rank) << " │\n";
                std::cout << "└───────┘\n" ;
            }
            else {
                std::cout << "┌───────┐\n";
                std::cout << "│ " << getRank(card.rank) << "     │\n";
                std::cout << "│   " << getSuit(card.suit) << "   │\n" ;
                std::cout << "│     " << getRank(card.rank) << " │\n";
                std::cout << "└───────┘\n" ;
            }
        }
    }
void printCard(const std::vector<Card>& d, int c) {
        for (int i {0}; i < c; ++i) {
            if (d[i].rank == Rank::ten) {
                std::cout << "┌───────┐\n";
                std::cout << "│ " << getRank(d[i].rank) << "    │\n";
                std::cout << "│   " << getSuit(d[i].suit) << "   │\n" ;
                std::cout << "│    " << getRank(d[i].rank) << " │\n";
                std::cout << "└───────┘\n" ;
            }
            else {
                std::cout << "┌───────┐\n";
                std::cout << "│ " << getRank(d[i].rank) << "     │\n";
                std::cout << "│   " << getSuit(d[i].suit) << "   │\n" ;
                std::cout << "│     " << getRank(d[i].rank) << " │\n";
                std::cout << "└───────┘\n" ;
                }
            }
        }
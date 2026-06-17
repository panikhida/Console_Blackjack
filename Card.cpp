#include "Card.h"
#include "includes.h"
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
void getValue(Rank rank) {
    std::cout << "Card rank: " << getRank(rank) << " it gives you ";
    switch (rank) {
        case Rank::jack:
        case Rank::queen:
        case Rank::king:
        case Rank::ten:
            std::cout << "10";
        case Rank::ace:
            std::cout << "11";
        default:
            std::cout << +rank;
    }
}
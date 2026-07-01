#include "includes.h"
#include "deck.h"
#include <algorithm>
#include <random>
//┌ ─ ┐
//│
//└ ─ ┘
void printDeck(const std::vector<Card>& d) {
    if (d.empty()) {
            std::cout << "Deck is empty" << "\n";
        }
    {
        std::cout << "          DECK         \n";
        std::cout << "==========----==========\n";
        for (auto card : d)
        {
            if (card.value > 9 && card.rank == Rank::ten)
                {
                    std::cout << "││   " << card.rank << card.suit << ", Value == " << card.value << " ││\n";
                }
            else if (card.value > 9 || card.rank == Rank::ten)
                    {
                        std::cout << "││   " << card.rank << card.suit << ", Value == " << card.value << "  ││\n";
                    }
            else {
                        std::cout << "││   " << card.rank << card.suit << ", Value == " << card.value << "   ││\n";
                }
            }
            std::cout << "└──────────────────────┘\n";
            std::cout << "│Capacity: " << d.capacity() << " Length: " << d.size() << "\n";
    }
}
//getValue(Rank::ranks_end)
//getValue(Suit::suits_end)
void fillDeck(std::vector<Card>& d) {
    std::cout << "\nFilling deck ...________________\n";
    d.clear();
    std::cout << "Deck cleared ............_______\n";
    for (int r { 2 }; r < std::to_underlying(Rank::ranks_end); ++r ) {
        for (int s { 0 }; s < std::to_underlying(Suit::suits_end); ++s) {
            Card card;
            card.rank = static_cast<Rank>(r);
            card.suit = static_cast<Suit>(s);
            card.value = getValue(card.rank);
            d.push_back(card);
        }
    }
    d.resize(52);
    d.shrink_to_fit();
    std::cout << "Deck filled  ...................\n";
}
void shuffleDeck(std::vector<Card>& d) {
    std::ranges::shuffle(d, std::default_random_engine(std::random_device{}()));
    }
void giveCard(std::vector<Card>& d, std::vector<Card>& d2) {
    d2.push_back(d.back());
    d.pop_back();
}

void insertCard(std::vector<Card>& d, Card card) {
    d.push_back(card);
    std::cout << "Card " << card.rank << card.suit << " added to deck\n";
};
int calcDeckValue(const std::vector<Card>& d) {
    int sum { 0 };
    std::cout << "sum = " << sum << "\n";
    for (Card card : d) {
        std::cout << "for started, sum = " << sum;
        sum += card.value;
        std::cout << "Card " << card.rank << card.suit << " added\n";
        if (card.rank == Rank::ace && sum + 11 > 21)  {
            std::cout << " Ace! \n sum = " << sum << "\n";
            sum = sum - 10;
        }
        std::cout << "for ended, sum = " << sum;

    }
    return sum;
}
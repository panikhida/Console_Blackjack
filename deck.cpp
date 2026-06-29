#include "includes.h"
#include "deck.h"
//┌ ─ ┐
//│
//└ ─ ┘
    void printDeck(const std::vector<Card>& d) {
        if (d.empty()) {
            std::cout << "Deck is empty" << "\n";
        }
        else {
            std::cout << "          DECK         \n";
            std::cout << "==========----==========\n";
            for (auto card : d)
                {
                if (card.value > 9 && card.rank == Rank::ten) {
                    std::cout << "││   " << card.rank << card.suit << ", Value == " << card.value << " ││\n";
                } else if (card.value > 9 || card.rank == Rank::ten) {
                        std::cout << "││   " << card.rank << card.suit << ", Value == " << card.value << "  ││\n";
                    } else {
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
                for (int r { 2 }; r < static_cast<int>(Rank::ranks_end); ++r ) {
                    for (int s { 0 }; s < static_cast<int>(Suit::suits_end); ++s) {
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
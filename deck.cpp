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
            std::cout << "│Capacity: " << d.capacity() << " Length: " << d.size() << " │\n";
            std::cout << "└──────────────────────┘\n";
        }
    }
    void fillDeck(std::vector<Card>& d) {
        std::cout << "\nFilling deck...\n--------------------------\n";
        for (int i { 0 }; i < d.capacity() ; ++i) {
            for (int r { 0 }; r < 13; ++r ) {
                for (int s { 0 }; s < 4; ++s) {
                    
                }
            }
        }
    }
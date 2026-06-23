#include "includes.h"

int main() {
 std::cout << "CBlackjack \n";

 // Rank card_rank1 { };
 // std::cout << "card_rank1(two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace) : ";
 // std::cin >> card_rank1;
 // std::cout << "Card rank is: " << card_rank1 << "\n";
 // std::cout << "It gives you " << getValue(card_rank1) << " points! \n";

 //deck
Card card1 {Rank::two, Suit::clubs};
 Card card2 {Rank::two, Suit::hearts};
 std::cout << "card1: " << card1.rank << card1.suit << ", Value: " << card1.value << "\n";
 printCard(card1, card2);
 return 0;
}
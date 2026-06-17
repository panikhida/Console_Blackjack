#include "includes.h"

int main() {
 Rank card_rank { Rank::two };
 Suit card_suit { Suit::clubs };
 std::cout << card_rank << card_suit << "\n";

 Rank card_rank1 { };\
 std::cout << "card_rank1 : ";
 std::cin >> card_rank1;
 std::cout<< card_rank1 << "\n";

 std::cout << getValue(card_rank1);
 return 0;
}
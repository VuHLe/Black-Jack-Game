#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <cstdlib>

class Deck
{
private:
    // ranks, suits, deck,
    // and the 'card_num' int represent the amounts of cards in a deck
    std::vector<std::string> ranks{ "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
    std::vector<std::string> suits{ "Clubs", "Diamonds", "Hearts", "Spades" };
    std::vector<Card> deck;
public:
    Deck();
    Deck(std::vector<std::string> ranks_param, std::vector<std::string> suits_param, 
        std::vector<Card> deck_param);
    void set_deck();
    std::vector<Card> get_deck();
    void shuffle_card();
    void take_out_card();
};

#endif


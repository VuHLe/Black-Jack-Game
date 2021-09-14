#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <cstdlib>

Deck::Deck()
{
    deck = {};
}

Deck::Deck(std::vector<std::string> ranks_param, std::vector<std::string> suits_param,
    std::vector<Card> deck_param)
{
    ranks = ranks_param;
    suits = suits_param;
    deck = deck_param;
}

// create a deck contain 52 cards
Card card;
void Deck::set_deck()
{
    for (int i = 0; i < ranks.size(); i++)
    {
        // get rank for a card from 'ranks' vector
        card.set_rank(ranks[i]);
        // loop through all the suits for one rank
        for (int n = 0; n < suits.size(); n++)
        {
            std::string::size_type sz;   // alias of size_t
            card.set_suit(suits[n]); // get suit for a card from 'suits' vector
            // set value for each card
            if (ranks[i].find("2") == 0 || ranks[i].find("3") == 0 || 
                ranks[i].find("4") == 0 || ranks[i].find("5") == 0 || 
                ranks[i].find("6") == 0 || ranks[i].find("7") == 0 || 
                ranks[i].find("8") == 0 || ranks[i].find("9") == 0 ||
                ranks[i].find("10") == 0)
            {
                card.set_value(std::stoi(ranks[i], &sz));
            }
            else if (ranks[i].find("Jack") == 0 || ranks[i].find("Queen") == 0 || 
                ranks[i].find("King") == 0)
            {
                card.set_value(10);
            }
            else if (ranks[i].find("Ace") == 0)
            {
                card.set_value(11);
            }
            deck.push_back(card);
        }
    }
}
// get deck
std::vector<Card> Deck::get_deck()
{
    return deck;
}

// shuffle the deck
void Deck::shuffle_card()
{
    srand((unsigned)time(0));
    shuffle(deck.begin(), deck.end(), std::default_random_engine(rand() % 52));
}
// whenever card pass to hand, deck lost 1 card
void Deck::take_out_card()
{
    deck.erase(deck.begin());
}
#include "Card.h"
#include <iostream>
#include <string>


Card::Card()
{
    rank = { "a" };
    suit = { "a" };
    value = 1;
}

Card::Card(std::string rank_param, std::string suit_param, int value_param)
{
    rank = rank_param;
    suit = suit_param;
    value = value_param;
}
// set rank
void Card::set_rank(std::string rank_param)
{
    rank = rank_param;
}
// set suit
void Card::set_suit(std::string suit_param)
{
    suit = suit_param;
}
// set value
void Card::set_value(int value_param)
{
    value = value_param;
}
int Card::get_value() const
{
    return value;
}

// append 'rank' and 'suit' to 'str_card' string
// to get a string representation for each card
std::string Card::get_str_card()
{
    std::string str_card;
    str_card.append(rank);
    str_card.append(" of ");
    str_card.append(suit);

    return str_card;
}
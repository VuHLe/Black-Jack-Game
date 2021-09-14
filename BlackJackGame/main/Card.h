#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

class Card
{
private:
    std::string rank;
    std::string suit;
    int value;
public:
    Card();
    Card(std::string rank_param, std::string suit_param, int value_param);
    void set_rank(std::string rank_param);
    void set_suit(std::string suit_param);
    void set_value(int value_param);
    int get_value() const;
    std::string get_str_card();
};
#endif

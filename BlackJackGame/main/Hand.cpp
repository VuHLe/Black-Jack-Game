#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include <iostream>
#include <string>
#include <vector>

Hand::Hand(std::vector<Card> hand_param)
{
	hand = hand_param;
}
// set hand
void Hand::set_hand(std::vector<Card> hand_param, int num)
{	
	hand.push_back(hand_param[num]);
}
// operator that add 1 card to hand from deck
Hand Hand::operator+=(Deck& right)
{
    std::vector<Card> temp_deck = right.get_deck();
	set_hand(temp_deck,0);
    right.take_out_card();
	return *this;
}
// set point
void Hand::set_point()
{
    // point equal 0 everytime the function call
    // to prevent stack up previous hand point
    point = 0; 
    for (Card h : hand)
    {
        int temp_value = h.get_value();
        point = point + temp_value;
    }
}
// get point
int Hand::get_point() const
{
    return point;
}

void Hand::deal_hand()
{
    // give each card to the user
    for (Card h : hand)
    {
        std::cout << h.get_str_card() << std::endl;
    }
}


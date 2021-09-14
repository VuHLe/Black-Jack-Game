#ifndef HAND_H
#define HAND_H
#include "Card.h"
#include "Deck.h"
#include <iostream>
#include <string>
#include <vector>

class Hand : public Deck
{
private:
	std::vector<Card> hand;
	int point;
public:
	
	Hand(std::vector<Card> hand_param);
	void set_hand(std::vector<Card> hand_param, int num);
	Hand operator+=(Deck& right);
	void set_point();
	int get_point() const;
	void deal_hand();
};

#endif

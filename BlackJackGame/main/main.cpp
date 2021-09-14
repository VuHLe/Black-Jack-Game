#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <cstdlib>

using namespace std;

// display player and dealer point, and print out appropriate message based on both points
void display_point(int player, int dealer)
{
    cout << "YOUR POINTS: " << player << endl;
    cout << "DEALER’S POINTS: " << dealer << "\n\n";

    // if both hands' points is over 21
    if (player > 21 && dealer > 21)
    {
        cout << "DRAW! Both hands busted!\n\n";
    }
    // if only player hands' points is over 21
    else if (player > 21 && dealer <= 21)
    {
        cout << "AWW! You busted. YOU LOSE!\n\n";
    }
    // if only dealer hands' points is over 21
    else if (dealer > 21 && player <= 21)
    {
        cout << "YAY! The dealer busted. YOU WIN!\n\n";
    }
    // if both hands' points is below or equal 21
    else if (player <= 21 && dealer <= 21)
    {
        if (player > dealer)
        {
            cout << "YAY! You had more points than dealer. YOU WIN!\n\n";
        }

        else if (player < dealer)
        {
            cout << "AWW! Dealer had more points than you. YOU LOSE!\n\n";
        }

        else
        {
            cout << "DRAW! Both hans had a same points!\n\n";
        }
    }
}
// function to countinue the game or not
bool control()
{
    char control;
    cout << "Play again? (y/n): ";
    cin >> control;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
    // if answer no
    if (tolower(control) == 'n')
    {
        cout << "Come back soon!\n";
        return false;
    }
    // if answer is invalid
    else if (tolower(control) != 'y' && tolower(control) != 'n')
    {
        cout << "Invalid answer! Please try again next time!\n";
        return false;
    }

    else
    {
        return true;
    }
}
//---------------------------------------------------------------------------------
int main()
{
    cout << "Blackjack\n\n";
    bool loop = true;
    while (loop == true)
    {
        
        
        Deck deck({ });
        Hand dealer({ });
        Hand player({ });

        deck.set_deck(); // create a deck
        deck.shuffle_card(); // shuffle the deck

        cout << "DEALER’S SHOW CARD: " << endl;
        dealer += deck; // add one card from deck to dealer hand first
        dealer.deal_hand(); // print out dealer hand
        cout << endl;

        // when player hit
        char hs = 'h';
        player += deck;
        while (tolower(hs) == 'h')
        {
            cout << "YOUR CARDS: " << endl;
            player += deck; // add one card from deck to player hand

            player.deal_hand(); // print out player hand
            cout << endl;

            cout << "Hit or stand? (h/s): ";
            cin >> hs;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        player.set_point(); // set player point
        cout << endl;

        // when player stand
        if (tolower(hs) == 's')
        {
            cout << "DEALER’S CARDS: " << endl;
            // get card to dealer until dealer point >= 17
            while (dealer.get_point() < 17)
            {
                dealer += deck; // add one card from deck to dealer hand
                dealer.set_point(); // set dealer point
            }
            dealer.deal_hand(); // print out dealer hand
            cout << endl;
            // display player and dealer point and print out comment
            display_point(player.get_point(),dealer.get_point());
        }

        // when player did not put in 'h' or 's'
        else
        {
            cout << "Invalid Answers!\n\n";
        }
        // Asked to countinue the game or not
        loop = control();
    }
    return EXIT_SUCCESS;
}

#include "nanabi.hpp"

#include <algorithm> // std::random_shuffle
#include <stdio.h>

Nanabi::Nanabi ( int nb_players )
{
    if ( check_arg ( nb_players ) )
        this->nb_players = 5;   // faire une execption
    this->nb_players = nb_players;

    init_game();
}

bool Nanabi::check_arg(int nb_players) const
{
    if ( nb_players < 2 || nb_players > 5 )
        return -1;
    return 0;
}

void Nanabi::init_game()
{
    printf ( "prout\n" );
    nb_clue_tokens = 8;
    nb_fuse_tokens = 3;
    player_turn = 0;

    // create deck
    for ( int i = 0; i < MAX_CARDS; i++ ) {
        Card * c = new Card ( i, i % MAX_COLOR_CARDS, card_repartition[i%MAX_COLOR_CARDS] );
        stack.push_back ( c );
    }
    // shuffle deck
    std::random_shuffle ( stack.begin(), stack.end() );
    // distribuer le jeu
    for ( int i = 0; i < nb_players; i++ ) {
        for ( int j = 0; j < ( nb_players == MAX_PLAYERS? 4:5 ); j++ ) {
            players_hand[i].push_back ( stack.back() );
            stack.pop_back();
        }
    }

    printf ( "joueur 1 cards = %zu, last cards = %zu\n", players_hand[0].size(), stack.size() );
}


bool Nanabi::play ( play_type t, int id, int value, int player )
{
    bool legal_action = false;
    switch ( t ) {
    case play_clue :
        legal_action = do_play_clue(id, value, player);
        break;
    case play_waste :
        legal_action = do_play_waste(id);
        break;
    case play_board :
        legal_action = do_play_board(id);
        break;
    default :
        legal_action = false;
    }
    if ( legal_action )
        increase_turn();
    return legal_action;
}

bool Nanabi::do_play_clue(int action, int value, int player)
{
    if ( player < 0 || player > nb_players )
        return false;
    if ( nb_clue_tokens <= 0)
        return false;

    if ( action == 0 )
    { // color
       if ( value < 1 || value > max_color - 1)
           return false;
       nb_clue_tokens--;
    }
    else if ( action == 1 )
    { // number
       if ( value < 1 || value > 5)
           return false;
       nb_clue_tokens--;
    }
    else
    {
        return false;
    }
    return true;
}

bool Nanabi::do_play_waste(int card_id)
{
    if ( card_in_vect(card_id, &players_hand[player_turn]) )
        return false;
    move_card(card_id, &players_hand[player_turn], &waste);
    return true;
}
bool Nanabi::do_play_board(int card_id)
{
    Card * c = get_card_in_vect(card_id, &players_hand[player_turn]);
    if ( c == NULL )
        return false;
    if ( !check_valid_action(c) ) // check if can play card
    {
        nb_fuse_tokens--;
        move_card(c->get_id(), &players_hand[player_turn], &waste);
    }
        move_card(c->get_id(), &players_hand[player_turn], &board);
    return true;
}

bool Nanabi::card_in_vect(int card_id, std::vector<Card *>* v) const
{
    for(auto const& card: *v)
    {
        if (card->get_id() == card_id )
            return true;
    }
    return false;
}

void Nanabi::increase_turn()
{
    player_turn = (player_turn + 1) % nb_players;
}

bool Nanabi::check_valid_action(Card * c) const
{
    int color = c->get_color();
    int value = c->get_value();
    for(auto const& card: board)
    {
        if(card->get_color() == color)
        {
            if(value > 1)
            {
                if(card->get_value() == value - 1)
                    return false;
            }
            if(card->get_value() == value)
                return false;
        }
    }
    return true;
}

Card * Nanabi::get_card_in_vect(int card_id, std::vector<Card *>* v) const
{
    for(auto const& card: *v)
    {
        if (card->get_id() == card_id )
            return card;
    }
    return NULL;
}

void Nanabi::move_card(int card_id, std::vector<Card *>* src, std::vector<Card *>*)
{
}

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

bool Nanabi::check_arg ( int nb_players )
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
    return legal_action;
}

bool Nanabi::do_play_clue(int action, int value, int player)
{
    if ( action == 0 ) { // color
        // go to function play clue color
    } else if ( action == 1 ) { // number
        // go to function play clue number
    }
    return true;
}
bool Nanabi::do_play_waste(int card_id)
{
    return true;
}
bool Nanabi::do_play_board(int card_id)
{
    return true;
}



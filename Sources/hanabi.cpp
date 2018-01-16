#include "hanabi.hpp"

#include <algorithm> // std::random_shuffle 
#include <stdio.h>

Hanabi::Hanabi(int nb_players)
{
    if(check_arg(nb_players))
        this->nb_players = 5;   // faire une execption
    this->nb_players = nb_players;
    
    init_game();
}

bool Hanabi::check_arg(int nb_players)
{
    if(nb_players < 2 || nb_players > 5)
        return -1;
    return 0;
}

void Hanabi::init_game()
{
    printf("prout\n");
        nb_tokens = 8;
        nb_fuse_tokens = 3;
        
        // create deck
        for(int i = 0; i < MAX_CARDS; i++)
        {
            Card * c = new Card(i, i % MAX_COLOR_CARDS, card_repartition[i%MAX_COLOR_CARDS]);
            stack.push_back(c);
        }
        // shuffle deck
        std::random_shuffle(stack.begin(), stack.end());
        // distribuer le jeu
        for(int i = 0; i < nb_players; i++)
        {
            for(int j = 0; j < (nb_players == MAX_PLAYERS? 4:5); j++)
            {
                players_hand[i].push_back(stack.back());
                stack.pop_back();
            }
        }
        
        printf("joueur 1 cards = %zu, last cards = %zu\n", players_hand[0].size(), stack.size());
}

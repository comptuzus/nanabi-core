#ifndef HANABI_HPP
#define HANABI_HPP

#include <vector>
#include "card.hpp"

#define MAX_PLAYERS 5
#define MAX_CARDS 50
#define MAX_COLOR_CARDS 10

#define COLOR_BLUE 0
#define COLOR_GREEN 1
#define COLOR_RED 2
#define COLOR_WHITE 3
#define COLOR_YELLOW 4

const int card_repartition [] = {1, 1, 1, 2, 2, 3, 3, 4, 4, 5};

class Hanabi
{
public:
    Hanabi(int nb_players);
    ~Hanabi();
    int get_game(int player_id); // if id = 0 the return all game
    int play(); // faire un type pour les trois choses qui peuvent être joué
    
private:
    void init_game();
    bool check_arg(int nb_players);
    
    int nb_players;
    // list of player hand
    std::vector<Card*> players_hand[MAX_PLAYERS];
    // nb clue
    int nb_tokens;
    // nb fuse token
    int nb_fuse_tokens;
    // list of cards in stack
    std::vector<Card*> stack;
    // list of cards strow
    std::vector<Card*> strow;
    // list of cards on board
    std::vector<Card*> board;

};
#endif //HANABI_HPP

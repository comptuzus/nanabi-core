#ifndef HANABI_HPP
#define HANABI_HPP

#include <vector>
#include "card.hpp"

#define MAX_PLAYERS 5
#define MAX_CARDS 50
#define MAX_COLOR_CARDS 10

enum color { blue = 0, green, red, white, yellow, max_color };

const int card_repartition [] = {1, 1, 1, 2, 2, 3, 3, 4, 4, 5};
// play_clue id -> 0 for color, 1 for value
// play_waste id -> id of the card
// play_board id -> id of the card
enum play_type { play_clue, play_waste, play_board };

class Nanabi
{
public:
    Nanabi (int nb_players);
    ~Nanabi();
    const std::vector<Card*> * get_hand(int player_id) const { return &players_hand[player_id]; };
    int get_clue_tokens(void) const { return nb_clue_tokens; };
    int get_fuse_tokens(void) const { return nb_fuse_tokens; };
    int get_player_turn(void) const { return player_turn; };
    const std::vector<Card*> * get_stack(void) const { return &stack; };
    const std::vector<Card*> * get_throw(void) const { return &waste; };
    const std::vector<Card*> * get_board(void) const { return &board; };

    // player is only use for play_clue
    bool play(play_type t, int id, int value, int player);

private:
    void init_game();
    bool check_arg(int nb_players) const;
    bool do_play_clue(int action, int value, int player);
    bool do_play_waste(int card_id);
    bool do_play_board(int card_id);
    bool card_in_vect(int card_id, std::vector<Card*> * v) const;
    void increase_turn(void);

    int nb_players;
    int player_turn;
    // list of player hand
    std::vector<Card*> players_hand[MAX_PLAYERS];
    // nb clue
    int nb_clue_tokens;
    // nb fuse token
    int nb_fuse_tokens;
    // list of cards in stack
    std::vector<Card*> stack;
    // list of cards waste
    std::vector<Card*> waste;
    // list of cards on board
    std::vector<Card*> board;

};
#endif //HANABI_HPP

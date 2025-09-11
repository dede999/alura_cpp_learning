#ifndef GAME_HPP
#define GAME_HPP

#include "game_components.hpp"

class Game {
  public:
    Game(string word);
    ~Game();

    bool is_hung();
    bool has_won();
    void display();
    void check_win();
    void draw_limbs();
    void check_guess();
    bool validate_guess();
    bool check_new_guess();
    void list_attemps(bool is_correct);
  private:
    vector<struct display> text_display;
    map<char, struct game_info> guessed;
    bool is_winner;
    int limbs = 0;
    string secret;
    char guess;
};

#endif

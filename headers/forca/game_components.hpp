#ifndef GAME_COMPONENTS_HPP
#define GAME_COMPONENTS_HPP

#include <vector>
#include <map>
using namespace std;

struct game_info {
  vector<int> occurences;
  bool attempted;
};

struct display {
  char letter;
  bool hit;
};

void draw_ascii_limbs(int limbs);
void show_display(vector<struct display> text_display);
void list_guessed_attempts(map<char, struct game_info> guessed, bool is_correct);

#endif
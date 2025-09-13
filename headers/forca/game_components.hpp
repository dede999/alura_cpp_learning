#ifndef GAME_COMPONENTS_HPP
#define GAME_COMPONENTS_HPP

#include <vector>
#include <map>

struct game_info {
  std::vector<int> occurences;
  bool attempted;
};

struct display {
  char letter;
  bool hit;
};

void draw_ascii_limbs(int limbs);
void show_display(std::vector<struct display> text_display);
void list_guessed_attempts(std::map<char, struct game_info> guessed, bool is_correct);

#endif
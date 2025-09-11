#include "game_components.hpp"
#include <iostream>

using namespace std;

void show_display(vector<struct display> text_display) {
  for (struct display d : text_display) {
    if (d.hit)
      cout << d.letter;
    else
      cout << "_";
  }
  cout << endl;
}

void list_guessed_attempts(map<char, struct game_info> guessed, bool is_correct) {
    if (is_correct) {
        cout << "Letras corretas: ";
    } else {
        cout << "Letras erradas: ";
    }

    for (auto it = guessed.begin(); it != guessed.end(); it++) {
        if (it->second.attempted && it->second.occurences.empty() == !is_correct)
        cout << it->first << " ";
    }
    cout << endl;
}

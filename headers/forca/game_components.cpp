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

void draw_ascii_limbs(int limbs) {
  switch (limbs) {
  case 0:
    cout << "  +---+" << endl;
    cout << "  |   |" << endl;
    cout << "      |" << endl;
    cout << "      |" << endl;
    cout << "      |" << endl;
    cout << "      |" << endl;
    break;
  case 1:
    cout << "  +---+" << endl;
    cout << "  |   |" << endl;
    cout << "  O   |" << endl;
    cout << "      |" << endl;
    cout << "      |" << endl;
    cout << "      |" << endl;
    break;
  case 2:
    cout << "  +---+" << endl;
    cout << "  |   |" << endl;
    cout << "  O   |" << endl;
    cout << "  |   |" << endl;
    cout << "      |" << endl;
    cout << "      |" << endl;
    break;
  case 3:
    cout << "  +---+" << endl;
    cout << "  |   |" << endl;
    cout << "  O   |" << endl;
    cout << " /|   |" << endl;
    cout << "      |" << endl;
    cout << "      |" << endl;
    break;
  case 4:
    cout << "  +---+" << endl;
    cout << "  |   |" << endl;
    cout << "  O   |" << endl;
    cout << " /|\\  |" << endl;
    cout << "      |" << endl;
    cout << "      |" << endl;
    break;
  case 5:
    cout << "  +---+" << endl;
    cout << "  |   |" << endl;
    cout << "  O   |" << endl;
    cout << " /|\\  |" << endl;
    cout << " /    |" << endl;
    cout << "      |" << endl;
    break;
  case 6:
    cout << "  +---+" << endl;
    cout << "  |   |" << endl;
    cout << "  O   |" << endl;
    cout << " /|\\  |" << endl;
    cout << " / \\  |" << endl;
    cout << "      |" << endl;
    break;
  }
  cout << endl;
}

#include "game_components.hpp"
#include <iostream>

void show_display(std::vector<struct display> text_display) {
  for (struct display d : text_display) {
    if (d.hit)
      std::cout << d.letter;
    else
      std::cout << "_";
  }
  std::cout << std::endl;
}

void list_guessed_attempts(std::map<char, struct game_info> guessed, bool is_correct) {
    if (is_correct) {
        std::cout << "Letras corretas: ";
    } else {
        std::cout << "Letras erradas: ";
    }

    for (auto it = guessed.begin(); it != guessed.end(); it++) {
        if (it->second.attempted && it->second.occurences.empty() == !is_correct)
            std::cout << it->first << " ";
    }
    std::cout << std::endl;
}

void draw_ascii_limbs(int limbs) {
  switch (limbs) {
  case 0:
    std::cout << "  +---+" << std::endl;
    std::cout << "  |   |" << std::endl;
    std::cout << "      |" << std::endl;
    std::cout << "      |" << std::endl;
    std::cout << "      |" << std::endl;
    std::cout << "      |" << std::endl;
    break;
  case 1:
    std::cout << "  +---+" << std::endl;
    std::cout << "  |   |" << std::endl;
    std::cout << "  O   |" << std::endl;
    std::cout << "      |" << std::endl;
    std::cout << "      |" << std::endl;
    std::cout << "      |" << std::endl;
    std::cout << "      |" << std::endl;
    break;
  case 2:
    std::cout << "  +---+" << std::endl;
    std::cout << "  |   |" << std::endl;
    std::cout << "  O   |" << std::endl;
    std::cout << "  |   |" << std::endl;
    std::cout << "      |" << std::endl;
    std::cout << "      |" << std::endl;
    std::cout << "      |" << std::endl;
    break;
  case 3:
    std::cout << "  +---+" << std::endl;
    std::cout << "  |   |" << std::endl;
    std::cout << "  O   |" << std::endl;
    std::cout << " /|   |" << std::endl;
    std::cout << "      |" << std::endl;
    std::cout << "      |" << std::endl;
    std::cout << "      |" << std::endl;
    break;
  case 4:
    std::cout << "  +---+" << std::endl;
    std::cout << "  |   |" << std::endl;
    std::cout << "  O   |" << std::endl;
    std::cout << " /|\\  |" << std::endl;
    std::cout << "      |" << std::endl;
    std::cout << "      |" << std::endl;
    std::cout << "      |" << std::endl;
    break;
  case 5:
    std::cout << "  +---+" << std::endl;
    std::cout << "  |   |" << std::endl;
    std::cout << "  O   |" << std::endl;
    std::cout << " /|\\  |" << std::endl;
    std::cout << " /    |" << std::endl;
    std::cout << "      |" << std::endl;
    std::cout << "      |" << std::endl;
    std::cout << "      |" << std::endl;
    break;
  case 6:
    std::cout << "  +---+" << std::endl;
    std::cout << "  |   |" << std::endl;
    std::cout << "  O   |" << std::endl;
    std::cout << " /|\\  |" << std::endl;
    std::cout << " / \\  |" << std::endl;
    std::cout << "      |" << std::endl;
    std::cout << "      |" << std::endl;
    break;
  }
  std::cout << std::endl;
}

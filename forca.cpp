#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "headers/forca/words_feed.cpp"
#include "headers/forca/game_components.cpp"

using namespace std;

class Game {
public:
  int limbs = 0;
  string phrase;
  char guess;
  bool has_won = false;
  map<char, struct game_info> guessed;
  vector<struct display> text_display;

  Game(string phrase) {
    this->phrase = phrase;
    for (char letter = 'A'; letter <= 'Z'; letter++) {
      struct game_info info;
      info.attempted = false;
      guessed[letter] = info;
    }

    for (int i = 0; i < phrase.size(); i++) {
      if (phrase[i] == ' ') {
        struct display d;
        d.letter = ' ';
        d.hit = true;
        text_display.push_back(d);
        continue;
      }
      struct display d;
      d.letter = phrase[i];
      d.hit = false;
      text_display.push_back(d);
      guessed[phrase[i]].occurences.push_back(i);
    }
  }

  void display() { show_display(text_display); }

  bool validate_guess() {
    if (this->guess >= 'a' && this->guess <= 'z')
      this->guess = this->guess - 'a' + 'A';

    if (this->guess < 'A' || this->guess > 'Z') {
      cout << "Letra inválida." << endl;
      return false;
    }

    return true;
  }

  bool check_new_guess() { return !guessed[this->guess].occurences.empty(); }

  void list_attemps(bool is_correct) { list_guessed_attempts(guessed, is_correct); }

  void check_guess() {
    cout << "Digite uma letra: ";
    cout << "Tentativas restantes: " << 6 - this->limbs << endl;
    list_attemps(true);
    list_attemps(false);

    cin >> this->guess;
    if (!validate_guess())
      return;

    if (guessed[this->guess].attempted) {
      cout << "Você já tentou essa letra." << endl;
      return;
    }

    if (check_new_guess()) {
      cout << "Você acertou!" << endl;
      for (int i : guessed[this->guess].occurences) {
        text_display[i].hit = true;
      }
    } else {
      limbs++;
      cout << "Você errou! A letra '" << this->guess << "' não está na palavra."
           << endl;
    }
    guessed[this->guess].attempted = true;
    check_win();
  }

  void draw_ascii_limbs() {
    switch (this->limbs) {
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

  bool is_hung() { return limbs >= 6; }

  void check_win() {
    for (struct display d : text_display) {
      if (!d.hit) {
        has_won = false;
        return;
      }
    }
    has_won = true;
  }
};

int main() {
  // string phrase = "O RATO ROEU A ROUPA DO REI DE ROMA", display;
  vector<string> word_list;
  read_file(&word_list);
  string secret_word = pick_random_word(word_list);
  Game hangman(secret_word);

  while (!hangman.has_won) {
    hangman.display();
    hangman.draw_ascii_limbs();
    hangman.check_guess();
    if (hangman.is_hung()) {
      cout << "Você foi enforcado!" << endl;
      hangman.draw_ascii_limbs();
      cout << "A palavra/frase era: " << secret_word << endl;
      break;
    }
  }

  if (hangman.has_won) {
    cout << "Você ganhou!" << endl;
    cout << "A palavra/frase era: " << secret_word << endl;
  }
}

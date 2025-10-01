#include <iostream>
#include <string>
#include <vector>
#include "headers/forca/words_feed.hpp"
#include "headers/forca/game.hpp"

using namespace std;

int main() {
  // string phrase = "O RATO ROEU A ROUPA DO REI DE ROMA", display;
  vector<string> word_list;
  string secret_word = WordsFeed::pick_random_word();
  Game hangman(secret_word);

  while (!hangman.has_won()) {
    hangman.display();
    hangman.draw_limbs();
    hangman.check_guess();
    if (hangman.is_hung()) {
      cout << "Você foi enforcado!" << endl;
      hangman.draw_limbs();
      cout << "A palavra/frase era: " << secret_word << endl;
      break;
    }
  }

  if (hangman.has_won()) {
    cout << "Você ganhou!" << endl;
    cout << "A palavra/frase era: " << secret_word << endl;
  }
}

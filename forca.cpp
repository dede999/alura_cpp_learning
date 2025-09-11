#include <iostream>
#include <string>
#include <vector>
#include "headers/forca/words_feed.cpp"
#include "headers/forca/game.cpp"

using namespace std;

int main() {
  // string phrase = "O RATO ROEU A ROUPA DO REI DE ROMA", display;
  vector<string> word_list;
  read_file(&word_list);
  string secret_word = pick_random_word(word_list);
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

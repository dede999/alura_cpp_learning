#include <iostream>
#include "game.hpp"

void Game::display() {
  show_display(text_display);
}

void Game::draw_limbs() {
  draw_ascii_limbs(limbs);
}

bool Game::validate_guess() {
  if (this->guess >= 'a' && this->guess <= 'z')
    this->guess = this->guess - 'a' + 'A';

  if (this->guess < 'A' || this->guess > 'Z') {
    cout << "Letra inválida." << endl;
    return false;
  }

  return true;
}

bool Game::check_new_guess() { return !guessed[this->guess].occurences.empty(); }

void Game::list_attemps(bool is_correct) {
  list_guessed_attempts(guessed, is_correct);
}

void Game::check_guess() {
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

bool Game::is_hung() { return limbs >= 6; }

void Game::check_win() {
  for (struct display d : text_display) {
    if (!d.hit) {
      is_winner = false;
      return;
    }
  }
  is_winner = true;
}

bool Game::has_won() { return is_winner; }

Game::Game(string word) {
  struct display d;
  this->secret = word;
  for (char letter = 'A'; letter <= 'Z'; letter++) {
    struct game_info info;
    info.attempted = false;
    guessed[letter] = info;
  }

  for (int i = 0; i < word.size(); i++) {
    if (word[i] == ' ') {
      d.letter = ' ';
      d.hit = true;
      text_display.push_back(d);
      continue;
    }
    d.letter = word[i];
    d.hit = false;
    text_display.push_back(d);
    guessed[word[i]].occurences.push_back(i);
  }
}

Game::~Game() {
  cout << "Fim de jogo!" << endl;
}

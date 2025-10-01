#include <cstddef>
#include <ctime>
#include <ios>
#include <iostream>
#include <ostream>
#include <cstdlib>
using namespace std;

int main() {
  cout << "****************************************************" << endl;
  cout << "* Welcome to the jungle, I mean, the guessing game *" << endl;
  cout << "****************************************************" << endl;

  srand(time(NULL));
  int secret_number = rand() % 1000;
  int guesses, current_guess, difficulty_level = 0, given_gueeses = 0;
  bool guessed = false;
  double score = 1000.0, factor;

  cout << "Chose your difficulty level:" << endl;
  cout << " 1- Easy (50 attempts)\n 2- Medium(30 attempts)\n 3- Hard(15 attempts)\n 4-Logarithmic (8 attempts)" << endl;
  while (true) {
      cout << "Pick a valid level." << endl;
      cin >> difficulty_level;
      if (difficulty_level > 0 && difficulty_level <= 4) break;
  }
  cout << "-------------------------------" << endl;
  int list_of_attempts[] = { 50, 30, 15, 8 };
  guesses = list_of_attempts[difficulty_level - 1];
  factor = list_of_attempts[5 - difficulty_level - 1] / 50.0;
  cout.precision(2);
  cout << fixed;

  while (!guessed) {
	given_gueeses ++;
    cout << "(" << score << " points left) Attemp #" << given_gueeses << "/" << guesses << ": ";
    cin >> current_guess;
    if (current_guess < secret_number) {
        cout << "The secret number is greater than your guess.\nPUT IT UP" << endl;
        score -= (secret_number - current_guess) * factor;
    } else if (current_guess > secret_number) {
        cout << "The secret number is lower than you guess\nPUT IT DOWN" << endl;
        score -= (current_guess - secret_number) * factor;
    } else {
        guessed = true;
        cout << "You've guessed it right" << endl;
        cout << "You've scored " << score << " points" << endl;
    }

    if (given_gueeses == guesses && !guessed) {
        cout << "You've ran out of attempts :'(\nYOU'RE LOST" << endl;
        break;
    }

    if (score <= 0) {
        cout << "Your points are gone. YOU'RE GONE" << endl;
        break;
    }
  }
  if (!guessed) {
      score = 0.0;
      cout << "You could not guess it" << endl;
      cout << "The secret number was " << secret_number << endl;
  }
  return 0;
}

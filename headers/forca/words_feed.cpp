#include "words_feed.hpp"
#include <fstream>
#include <iostream>

void read_file(vector<string>* list) {
  ifstream word_list;
  string word;
  word_list.open("static/word_list.txt");
  if (word_list.is_open()) {
    while (getline(word_list, word)) {
      cout << word << endl;
      list->push_back(word);
    }
    word_list.close();
  }
};

string pick_random_word(vector<string> list) {
  srand(time(NULL));
  int random_index = rand() % list.size();
  return list[random_index];
}

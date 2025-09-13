#include "words_feed.hpp"
#include <fstream>
#include <iostream>

namespace WordsFeed {
  void read_file() {
    std::ifstream word_list_file;
    std::string word;

    word_list_file.open(file_path);
    if (word_list_file.is_open()) {
      while (getline(word_list_file, word)) {
        std::cout << word << std::endl;
        word_list.push_back(word);
      }
      word_list_file.close();
    }
  };

  std::string pick_random_word() {
    std::srand(std::time(NULL));
    int random_index = std::rand() % word_list.size();
    std::string random_word = word_list[random_index];
    return random_word;
  }
}
#ifndef WORDS_FEED_HPP
#define WORDS_FEED_HPP

#include <vector>
#include <cstdlib>
#include <ctime>

namespace WordsFeed {
  static std::vector<std::string> word_list;
  static std::string file_path = "static/word_list.txt";

  void read_file();
  std::string pick_random_word();
}

#endif

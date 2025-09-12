#ifndef WORDS_FEED_HPP
#define WORDS_FEED_HPP

#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void read_file(vector<string>* list);
string pick_random_word(vector<string> list);
#endif

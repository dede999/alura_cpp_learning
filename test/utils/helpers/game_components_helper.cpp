#include "game_components_helper.hpp"
#include "../../../headers/forca/game_components.hpp"

// implementing helper methods
std::vector<struct display> generate_word_display() {
    std::vector<struct display> text_display;
    
    struct display d1;
    d1.letter = 'H';
    d1.hit = true;
    
    struct display d2;
    d2.letter = 'E';
    d2.hit = false;
    
    text_display.push_back(d1);
    text_display.push_back(d2);
    
    return text_display;
}

std::map<char, struct game_info> generate_guessed_map() {
    std::map<char, struct game_info> guessed;
    
    struct game_info info1;
    info1.attempted = true;
    info1.occurences.push_back(0);
    
    struct game_info info2;
    info2.attempted = true;
    
    guessed['H'] = info1;
    guessed['E'] = info2;
    
    return guessed;
}

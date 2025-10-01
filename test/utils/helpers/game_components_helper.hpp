#ifndef GAME_COMPONENTS_HELPER_HPP
#define GAME_COMPONENTS_HELPER_HPP
#include <vector>
#include <map>

// declaring helper methods
std::vector<struct display> generate_word_display();
std::map<char, struct game_info> generate_guessed_map();

struct LimbTestCase {
    int input;
    std::string expected_output() {
        switch(input) {
            case 0: return "  +---+\n  |   |\n      |\n      |\n      |\n      |\n\n";
            case 1: return "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n      |\n\n";
            case 2: return "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n      |\n\n";
            case 3: return "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n      |\n\n";
            case 4: return "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n      |\n\n";
            case 5: return "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n      |\n      |\n\n";
            case 6: return "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n      |\n\n";
            default: return "";
        }
    }
};

#endif

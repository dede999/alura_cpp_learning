#include "../catch.hpp"
#include "../../headers/forca/game_components.hpp"
#include "../utils/helpers/game_components_helper.hpp"
#include "../utils/output_capture.hpp"
#include <vector>
#include <map>

TEST_CASE("Game Components - Display Structure", "[game_components]") {
    SECTION("Display structure initialization") {
        struct display d;
        d.letter = 'A';
        d.hit = false;
        
        REQUIRE(d.letter == 'A');
        REQUIRE(d.hit == false);
    }
    
    SECTION("Display structure with hit") {
        struct display d;
        d.letter = 'B';
        d.hit = true;
        
        REQUIRE(d.letter == 'B');
        REQUIRE(d.hit == true);
    }
}

TEST_CASE("Game Components - Game Info Structure", "[game_components]") {
    SECTION("Game info initialization") {
        struct game_info info;
        info.attempted = false;
        info.occurences.push_back(0);
        info.occurences.push_back(5);
        
        REQUIRE(info.attempted == false);
        REQUIRE(info.occurences.size() == 2);
        REQUIRE(info.occurences[0] == 0);
        REQUIRE(info.occurences[1] == 5);
    }
    
    SECTION("Game info with attempt") {
        struct game_info info;
        info.attempted = true;
        
        REQUIRE(info.attempted == true);
        REQUIRE(info.occurences.empty() == true);
    }
}

TEST_CASE("Game Components - Display Vector", "[game_components]") {
    SECTION("Creating display vector") {
        std::vector<struct display> text_display = GENERATE(generate_word_display());
        
        REQUIRE(text_display.size() == 2);
        REQUIRE(text_display[0].letter == 'H');
        REQUIRE(text_display[0].hit == true);
        REQUIRE(text_display[1].letter == 'E');
        REQUIRE(text_display[1].hit == false);
    }
}

TEST_CASE("Game Components - show_display()", "[game_components]") {
    SECTION("When some letter was not hit") {
        OutputCapture capture;
        std::vector<struct display> text_display = generate_word_display();
        
        show_display(text_display);
        
        REQUIRE(capture.getOutput() == "H_\n");
    }

    SECTION("When all letters were hit") {
        OutputCapture capture;
        std::vector<struct display> text_display = generate_word_display();
        text_display[1].hit = true;
        
        show_display(text_display);
        
        REQUIRE(capture.getOutput() == "HE\n");
    }
}

TEST_CASE("Game Components - list_guessed_attempts()", "[game_components]") {
    SECTION("When listing wrong attempts") {
        OutputCapture capture;
        std::map<char, struct game_info> guessed = generate_guessed_map();
        
        list_guessed_attempts(guessed, false);
        
        REQUIRE(capture.getOutput() == "Letras erradas: E \n");
    }

    SECTION("When listing correct attempts") {
        OutputCapture capture;
        std::map<char, struct game_info> guessed = generate_guessed_map();
        
        list_guessed_attempts(guessed, true);
        
        REQUIRE(capture.getOutput() == "Letras corretas: H \n");
    }
}

TEST_CASE("Game Components - draw_ascii_limbs()", "[game_components]") {
    for (int i = 0; i < 7; i++) {
        LimbTestCase test_case;
        test_case.input = i;
        SECTION("draw_ascii_limbs() with " + std::to_string(test_case.input) + " limbs") {
            OutputCapture capture;
            draw_ascii_limbs(test_case.input);
            
            REQUIRE(capture.getOutput() == test_case.expected_output());
        }
    }
}

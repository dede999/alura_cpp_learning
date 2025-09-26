#include "../catch.hpp"
#include "../../headers/forca/game_components.hpp"
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
        std::vector<struct display> text_display;
        
        struct display d1;
        d1.letter = 'H';
        d1.hit = true;
        
        struct display d2;
        d2.letter = 'E';
        d2.hit = false;
        
        text_display.push_back(d1);
        text_display.push_back(d2);
        
        REQUIRE(text_display.size() == 2);
        REQUIRE(text_display[0].letter == 'H');
        REQUIRE(text_display[0].hit == true);
        REQUIRE(text_display[1].letter == 'E');
        REQUIRE(text_display[1].hit == false);
    }
}
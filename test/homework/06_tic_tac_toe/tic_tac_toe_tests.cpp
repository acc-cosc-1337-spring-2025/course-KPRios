#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify TicTacToe game over when all slots are filled") {
    TicTacToe game;
    game.start_game("X");

    
    int positions[9] = {1, 2, 3, 4, 5, 7, 6, 9, 8};
    
    for (int i = 0; i < 9; ++i) {
        game.mark_board(positions[i]);
        
        if (i == 8) {
            REQUIRE(game.game_over() == true);
        } else {
            REQUIRE(game.game_over() == false);
        }
    }

    
    REQUIRE(game.game_over() == true);
}



#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Test first player set to X")
{
    TicTacToe game;
    game.start_game("X");
    REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test first player set to O")
{
    TicTacToe game;
    game.start_game("O");
    REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test game over if 9 slots selected (Tie)")
{
    TicTacToe game;
    game.start_game("X");

    std::vector<int> moves = {1, 2, 3, 5, 4, 6, 8, 7, 9};
    for (int move : moves)
    {
        game.mark_board(move);
        if (move != 9)
            REQUIRE(game.game_over() == false);
    }

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "C");
}

// Add similar tests for each of the win conditions...


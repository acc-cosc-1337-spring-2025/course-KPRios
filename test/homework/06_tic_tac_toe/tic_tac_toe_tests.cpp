#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "tic_tac_toe_4.h"
TEST_CASE("Test win by first column 4", "[TicTacToe4]") {
    TicTacToe4 game;
    game.start_game("X");
    game.mark_board(1);  // X
    game.mark_board(2);  // O
    game.mark_board(5);  // X
    game.mark_board(3);  // O
    game.mark_board(9);  // X
    game.mark_board(4);  // O
    game.mark_board(13); // X -> Win by column

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by first row 4", "[TicTacToe4]") {
    TicTacToe4 game;
    game.start_game("O");
    game.mark_board(1); // O
    game.mark_board(5); // X
    game.mark_board(2); // O
    game.mark_board(6); // X
    game.mark_board(3); // O
    game.mark_board(7); // X
    game.mark_board(4); // O -> Win by row

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "O");
}

TEST_CASE("Test win by diagonal from top-left 4", "[TicTacToe4]") {
    TicTacToe4 game;
    game.start_game("X");
    game.mark_board(1);   // X
    game.mark_board(2);   // O
    game.mark_board(6);   // X
    game.mark_board(3);   // O
    game.mark_board(11);  // X
    game.mark_board(4);   // O
    game.mark_board(16);  // X -> Win by diagonal

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by diagonal from top-right 4", "[TicTacToe4]") {
    TicTacToe4 game;
    game.start_game("O");
    game.mark_board(4);   // O
    game.mark_board(1);   // X
    game.mark_board(7);   // O
    game.mark_board(2);   // X
    game.mark_board(10);  // O
    game.mark_board(3);   // X
    game.mark_board(13);  // O -> Win by diagonal

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "O");
}

TEST_CASE("Test tie 4", "[TicTacToe4]") {
    TicTacToe4 game;
    game.start_game("X");

    // Fill board to result in a tie
    std::vector<int> moves = {
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12,
        14, 13, 16, 15
    };

    for (int move : moves) {
        game.mark_board(move);
    }

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "C");
}


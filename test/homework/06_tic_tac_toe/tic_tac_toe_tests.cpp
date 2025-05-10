#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include <cassert>
#include <iostream>

void simulate_game(TicTacToe& game, std::string first_player, const std::vector<int>& moves) {
    game.start_game(first_player);
    for (int pos : moves) {
        game.mark_board(pos);
        if (game.game_over()) break;
    }
    std::cout << game;
}

void test_tic_tac_toe_manager() {
    TicTacToeManager manager;

    // Game 1: X wins
    TicTacToe game1;
    simulate_game(game1, "X", {1, 4, 2, 5, 3}); // X wins (top row)
    assert(game1.get_winner() == "X");
    manager.save_game(game1);

    // Game 2: O wins
    TicTacToe game2;
    simulate_game(game2, "O", {1, 4, 2, 5, 7, 6}); // O wins (left column)
    assert(game2.get_winner() == "O");
    manager.save_game(game2);

    // Game 3: Tie
    TicTacToe game3;
    simulate_game(game3, "X", {1, 2, 3, 5, 4, 6, 8, 7, 9}); // Tie
    assert(game3.get_winner() == "C");
    manager.save_game(game3);

    // Check winner totals
    int x = 0, o = 0, t = 0;
    manager.get_winner_total(o, x, t);

    assert(x == 1);
    assert(o == 1);
    assert(t == 1);

    std::cout << "\nAll test cases passed: \nX wins: " << x << ", O wins: " << o << ", Ties: " << t << "\n";
}



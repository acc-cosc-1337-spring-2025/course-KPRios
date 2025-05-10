#include <iostream>
#include <memory>
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"

int main() {
    TicTacToeManager manager;
    std::unique_ptr<TicTacToe> game;
    std::string choice;
    std::string first_player;
    int position;

    std::cout << "Choose game (3 or 4): ";
    std::cin >> choice;

    if (choice == "3") {
        game = std::make_unique<TicTacToe3>();
    } else {
        game = std::make_unique<TicTacToe4>();
    }

    std::cout << "Enter first player (X or O): ";
    std::cin >> first_player;
    game->start_game(first_player);

    while (!game->game_over()) {
        game->display_board();
        std::cout << "Enter position (1-" << game->get_player() << "): ";
        std::cin >> position;
        game->mark_board(position);
    }

    game->display_board();
    std::cout << "Game over. Winner: " << game->get_winner() << "\n";

    manager.save_game(game);
    manager.display_games();

    return 0;
}


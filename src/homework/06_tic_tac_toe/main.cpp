#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include <iostream>

int main() {
    TicTacToeManager manager;
    std::string player;
    char play_again;

    do {
        std::cout << "Enter first player (X or O): ";
        std::cin >> player;

        TicTacToe game;
        game.start_game(player);

        while (!game.game_over()) {
            std::cin >> game;  // overloaded >>
            std::cout << game; // overloaded <<
        }

        std::cout << "Game over. Winner: " << game.get_winner() << "\n";

        manager.save_game(game);

        int o, x, t;
        manager.get_winner_total(o, x, t);
        std::cout << "X wins: " << x << ", O wins: " << o << ", Ties: " << t << "\n";

        std::cout << "Play again? (y/n): ";
        std::cin >> play_again;

    } while (play_again == 'y' || play_again == 'Y');

    return 0;
}

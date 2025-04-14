#include "tic_tac_toe.h"
#include <iostream>

int main()
{
    std::string first_player;
    char choice = 'Y';

    while (toupper(choice) == 'Y')
    {
        TicTacToe game;
        do {
            std::cout << "Enter first player (X or O): ";
            std::cin >> first_player;
        } while (first_player != "X" && first_player != "O");

        game.start_game(first_player);

        int position;
        while (!game.game_over())
        {
            game.display_board();
            std::cout << "Player " << game.get_player() << ", enter a position (1-9): ";
            std::cin >> position;
            while (position < 1 || position > 9)
            {
                std::cout << "Invalid input. Enter position (1-9): ";
                std::cin >> position;
            }

            game.mark_board(position);
        }

        game.display_board();
        std::cout << "Game over!\n";
        std::string winner = game.get_winner();
        if (winner == "C")
        {
            std::cout << "It's a tie!\n";
        }
        else
        {
            std::cout << "Player " << winner << " wins!\n";
        }

        std::cout << "Play again? (Y/N): ";
        std::cin >> choice;
    }

    return 0;
}

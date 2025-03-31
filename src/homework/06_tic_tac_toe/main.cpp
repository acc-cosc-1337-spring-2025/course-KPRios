
#include <iostream>
#include "tic_tac_toe.h"

using namespace std;

int main() {
    TicTacToe game;
    string first_player;
    
    cout << "Enter first player (X or O): ";
    cin >> first_player;
    
    game.start_game(first_player);
    
    while (!game.game_over()) {
        game.display_board();
        int position;
        cout << "Player " << game.get_player() << ", enter a position (1-9): ";
        cin >> position;
        
        try {
            game.mark_board(position);
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
            continue;
        }
    }
    
    game.display_board();
    cout << "Game over! All spots are filled." << endl;
    
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    
    if (choice == 'y' || choice == 'Y') {
        main(); // Restart the game
    } else {
        cout << "Thanks for playing!" << endl;
    }

    return 0;
}

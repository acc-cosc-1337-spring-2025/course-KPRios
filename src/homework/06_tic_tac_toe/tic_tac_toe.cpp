//cpp
#include "tic_tac_toe.h"
#include <iostream>

using namespace std;

bool TicTacToe::game_over() {
    return check_board_full();
}

void TicTacToe::start_game(string first_player) {
    if (first_player != "X" && first_player != "O") {
        throw invalid_argument("First player must be X or O.");
    }
    player = first_player;
    clear_board();
}

void TicTacToe::mark_board(int position) {
    if (position < 1 || position > 9) {
        throw out_of_range("Position must be between 1 and 9.");
    }
    if (pegs[position - 1] != " ") {
        throw invalid_argument("Spot is already taken.");
    }
    pegs[position - 1] = player;
    set_next_player();
}

string TicTacToe::get_player() const {
    return player;
}

void TicTacToe::display_board() const {
    for (int i = 0; i < 3; i++) {
        cout << pegs[i * 3] << "|" << pegs[i * 3 + 1] << "|" << pegs[i * 3 + 2] << endl;
        if (i < 2) cout << "-----\n";
    }
}

void TicTacToe::set_next_player() {
    player = (player == "X") ? "O" : "X";
}

bool TicTacToe::check_board_full() {
    for (const string& peg : pegs) {
        if (peg == " ") {
            return false;
        }
    }
    return true;
}

void TicTacToe::clear_board() {
    fill(pegs.begin(), pegs.end(), " ");
}

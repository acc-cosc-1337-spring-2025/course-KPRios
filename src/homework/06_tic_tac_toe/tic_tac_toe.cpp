// tic_tac_toe.cpp
#include "tic_tac_toe.h"
#include <iostream>
#include <cmath>

TicTacToe::TicTacToe(int size) : pegs(size * size, " ") {}

void TicTacToe::start_game(std::string first_player) {
    player = first_player;
}

void TicTacToe::mark_board(int position) {
    pegs[position - 1] = player;
    if (!game_over()) {
        player = (player == "X") ? "O" : "X";
    }
}

bool TicTacToe::game_over() {
    if (check_column_win() || check_row_win() || check_diagonal_win()) {
        set_winner();
        return true;
    } else if (check_board_full()) {
        winner = "C";
        return true;
    }
    return false;
}

bool TicTacToe::check_board_full() {
    for (const auto& peg : pegs) {
        if (peg == " ") return false;
    }
    return true;
}

void TicTacToe::set_winner() {
    winner = player;
}

std::string TicTacToe::get_winner() const {
    return winner;
}

std::string TicTacToe::get_player() const {
    return player;
}

void TicTacToe::display_board() const {
    int size = std::sqrt(pegs.size());
    for (int i = 0; i < pegs.size(); i++) {
        std::cout << pegs[i];
        if ((i + 1) % size == 0)
            std::cout << "\n";
        else
            std::cout << "|";
    }
}


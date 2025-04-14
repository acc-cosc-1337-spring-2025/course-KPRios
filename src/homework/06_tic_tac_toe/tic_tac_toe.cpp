//cpp
#include "tic_tac_toe.h"
#include <iostream>

void TicTacToe::start_game(std::string first_player)
{
    player = first_player;
    clear_board();
}

void TicTacToe::mark_board(int position)
{
    pegs[position - 1] = player;
    set_next_player();
}

void TicTacToe::display_board() const
{
    for (int i = 0; i < 9; i += 3)
    {
        std::cout << pegs[i] << " | " << pegs[i + 1] << " | " << pegs[i + 2] << "\n";
    }
}

bool TicTacToe::game_over()
{
    if (check_row_win() || check_column_win() || check_diagonal_win())
    {
        set_winner();
        return true;
    }

    if (check_board_full())
    {
        winner = "C"; // C for tie
        return true;
    }

    return false;
}

std::string TicTacToe::get_player() const
{
    return player;
}

std::string TicTacToe::get_winner() const
{
    return winner;
}

void TicTacToe::set_next_player()
{
    player = (player == "X") ? "O" : "X";
}

bool TicTacToe::check_board_full()
{
    for (const auto &peg : pegs)
    {
        if (peg == " ")
            return false;
    }
    return true;
}

void TicTacToe::clear_board()
{
    for (auto &peg : pegs)
    {
        peg = " ";
    }
}

bool TicTacToe::check_row_win()
{
    for (int i = 0; i < 9; i += 3)
    {
        if (pegs[i] != " " && pegs[i] == pegs[i + 1] && pegs[i] == pegs[i + 2])
            return true;
    }
    return false;
}

bool TicTacToe::check_column_win()
{
    for (int i = 0; i < 3; ++i)
    {
        if (pegs[i] != " " && pegs[i] == pegs[i + 3] && pegs[i] == pegs[i + 6])
            return true;
    }
    return false;
}

bool TicTacToe::check_diagonal_win()
{
    return (
        (pegs[0] != " " && pegs[0] == pegs[4] && pegs[0] == pegs[8]) ||
        (pegs[2] != " " && pegs[2] == pegs[4] && pegs[2] == pegs[6]));
}

void TicTacToe::set_winner()
{
    winner = (player == "X") ? "O" : "X";
}

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <vector>
#include <string>
#include <iostream>

class TicTacToe {
public:
    TicTacToe(int size);
    bool game_over();
    void start_game(std::string first_player);
    void mark_board(int position);
    void display_board() const;
    std::string get_winner() const;
    std::string get_player() const;

protected:
    std::vector<std::string> pegs;
    virtual bool check_column_win() { return false; }
    virtual bool check_row_win() { return false; }
    virtual bool check_diagonal_win() { return false; }

private:
    std::string player;
    std::string winner;
    bool check_board_full();
    void set_winner();
};

#endif


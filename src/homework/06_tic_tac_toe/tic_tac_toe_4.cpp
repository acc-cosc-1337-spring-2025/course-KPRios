#include "tic_tac_toe_4.h"

/*
class function check_column_win
Win by column if and return true if (each column index)
0, 1,  2,  3 
4, 5,  6,  7 
8, 9, 10, 11 
12,13,14, 15 
else
false
*/
bool TicTacToe4::check_column_win() {
    for (int col = 0; col < 4; ++col) {
        if (pegs[col] != " " &&
            pegs[col] == pegs[col + 4] &&
            pegs[col] == pegs[col + 8] &&
            pegs[col] == pegs[col + 12]) {
            return true;
        }
    }
    return false;
}



/*
class function check_row_win
Win by row if
0, 1,  2,  3 are equal
4, 5,  6,  7 are equal
8, 9, 10, 11 are equal 
12,13,14, 15 are equal
*/
bool TicTacToe4::check_row_win() {
    for (int row = 0; row < 16; row += 4) {
        if (pegs[row] != " " &&
            pegs[row] == pegs[row + 1] &&
            pegs[row] == pegs[row + 2] &&
            pegs[row] == pegs[row + 3]) {
            return true;
        }
    }
    return false;
}


/*
class function check_diagonal_win
Win diagonally
0, 1,  2,  3
4, 5,  6,  7
8, 9, 10, 11
12,13,14, 15

*/
bool TicTacToe4::check_diagonal_win() {
    return (pegs[0] != " " &&
            pegs[0] == pegs[5] &&
            pegs[0] == pegs[10] &&
            pegs[0] == pegs[15]) ||

           (pegs[3] != " " &&
            pegs[3] == pegs[6] &&
            pegs[3] == pegs[9] &&
            pegs[3] == pegs[12]);
}
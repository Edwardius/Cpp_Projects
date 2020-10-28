#include <cstdlib>
#include <iostream>
#include <fstream>

void fall(int board[7][7], int playerMove, int player) {
    for (int fall = 0; fall < 7; fall++) {
        if (board[fall][playerMove] != 0) {
            board[fall - 1][playerMove] = player;
            break;
        }
        if (fall == 6) {
            board[fall][playerMove] = player;
            break;
        }
    }
    return;
}

void printBoard(int board[7][7]) {
    for (int x = 0; x < 7; x++) {
        for (int y = 0; y < 7; y++) {
            std::cout << board[x][y] << " ";
        }
        std::cout << std::endl;
    }
    return;
}

int main()
{
    std::ifstream gameIN("game_moves.txt");
    if (!gameIN) {
        std::cout << "File not found\n";
        return EXIT_FAILURE;
    }

    int Xcolumn = 0, Ocolumn = 0, board[7][7] = { }, counter = 0;
    bool xWin = false, yWin = false;

    while (gameIN >> Xcolumn) {
        Xcolumn -= 1;
        fall(board, Xcolumn, 1);
        
        if (gameIN >> Ocolumn) {
            Ocolumn -= 1;
            fall(board, Ocolumn, 2);
        }
    }

    printBoard(board);

    for (int row = 0; row < 7; row++) {
        for (int col = 0; col < 7; col++) {
            if (board[row][col] == 1 && col + 3 < 7) {
                for (int hor = col; hor <= col + 3; hor++) {
                    if (board[row][hor] == 1) {
                        xWin = true;
                    }
                    else {
                        xWin = false;
                        break;
                    }
                }
            }
            if (board[row][col] == 1 && row + 3 < 7) {
                for (int ver = row; ver <= row + 3; ver++) {
                    if (board[ver][col] == 1) {
                        xWin = true;
                    }
                    else {
                        xWin = false;
                        break;
                    }
                }
            }
            if (board[row][col] == 2 && col + 3 < 7) {
                for (int hor = col; hor <= col + 3; hor++) {
                    if (board[row][hor] == 2) {
                        yWin = true;
                    }
                    else {
                        yWin = false;
                        break;
                    }
                }
            }
            if (board[row][col] == 2 && row + 3 < 7) {
                for (int ver = row; ver <= row + 3; ver++) {
                    if (board[ver][col] == 2) {
                        yWin = true;
                    }
                    else {
                        yWin = false;
                        break;
                    }
                }
            }
            if (xWin == true) {
                std::cout << "Player X has won.\n";
                break;
            }
            if (yWin == true) {
                std::cout << "Player O has won.\n";
                break;
            }
        }
        if (xWin == true) {
            break;
        }
        if (yWin == true) {
            break;
        }
    }

    if (xWin == false && yWin == false) {
        std::cout << "Neither player has won yet.\n";
    }

    gameIN.close();
}


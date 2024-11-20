#include <iostream>
#include <vector>
using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;

    bool checkWin() {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;
        }

        for (int i = 0; i < 3; i++) {
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true;
        }

        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;

        return false;
    }

    bool isDraw() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') return false;
            }
        }
        return true;
    }

public:
    TicTacToe() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
    }

    void drawBoard() {
        cout << "Current board:\n";
        cout << "Any time you wanna exit game enter -1 -1. \n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            cout << "\n";
            if (i < 2) cout << "--+---+--\n";
        }
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again.\n";
            return false;
        }
        board[row][col] = currentPlayer;
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void playGame() {
        while (true) {
            drawBoard();
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            int row, col;
            cin >> row >> col;

            if (row == -1 && col == -1) {
                cout << "Game exited. Goodbye!\n";
                break;
            }

            if (makeMove(row - 1, col - 1)) {
                if (checkWin()) {
                    drawBoard();
                    cout << "Player " << currentPlayer << " wins!\n";
                    break;
                }
                if (isDraw()) {
                    drawBoard();
                    cout << "It's a draw!\n";
                    break;
                }
                switchPlayer();
            }
        }
    }
};

int main() {
    TicTacToe game;
    game.playGame();

    return 0;
}

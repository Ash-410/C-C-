#include <iostream>
using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char currentPlayer = 'X';

void drawBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool movementOfPlayer(int move) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    if (board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        return true;
    }

    return false;
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return true;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return true;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return true;
    }

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int move;
    bool gameOver = false;

    while (!gameOver) {
        drawBoard();
        cout << "Player " << currentPlayer << ", enter your move: ";
        cin >> move;

        if (move >= 1 && move <= 9) {
            if (movementOfPlayer(move)) {
                if (checkWin()) {
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    gameOver = true;
                } else if (checkDraw()) {
                    cout << "It's a draw!" << endl;
                    gameOver = true;
                } else {
                    if (currentPlayer == 'X') {
                        currentPlayer = 'O';
                    } else {
                        currentPlayer = 'X';
                    }
                }
            } else {
                cout << "That move is not valid. Try again." << endl;
            }
        } else {
            cout << "That move is not valid. Try again." << endl;
        }
    }

    return 0;
}

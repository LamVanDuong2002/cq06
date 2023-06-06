#include <iostream>
using namespace std;

const int SIZE = 3; // K�ch th�?c b?ng c?

char board[SIZE][SIZE]; // Ma tr?n l�u tr?ng th�i b?ng c?

// Kh?i t?o b?ng c?
void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

// V? b?ng c? ra m�n h?nh
void drawBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Ki?m tra xem ng�?i ch�i c� th?ng hay kh�ng
bool checkWin(char player) {
    // Ki?m tra h�ng ngang v� c?t d?c
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    // Ki?m tra hai ��?ng ch�o
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

// Th?c hi?n l�?t �i c?a ng�?i ch�i
void makeMove(char player) {
    int row, col;
    cout << "Ng�?i ch�i " << player << " h?y ch?n h�ng v� c?t (vd: 1 2): ";
    cin >> row >> col;

    // Ki?m tra n�?c �i h?p l?
    while (row < 1 || row > SIZE || col < 1 || col > SIZE || board[row - 1][col - 1] != '-') {
        cout << "N�?c �i kh�ng h?p l?! H?y ch?n l?i: ";
        cin >> row >> col;
    }

    // �?t k? hi?u c?a ng�?i ch�i v�o b?ng c?
    board[row - 1][col - 1] = player;
}
int main() {
    char currentPlayer = 'X'; // Ng�?i ch�i hi?n t?i

    initializeBoard(); // Kh?i t?o b?ng c?

    while (true) {
        drawBoard(); // V? b?ng c?

        makeMove(currentPlayer); // L�?t �i c?a ng�?i ch�i hi?n t?i

        if (checkWin(currentPlayer)) {
            cout << "Ng�?i ch�i " << currentPlayer << " �? th?ng!" << endl;
            break;
        }

        // Chuy?n l�?t �i cho ng�?i ch�i ti?p theo
        if (currentPlayer == 'X')
            currentPlayer = 'O';
        else
            currentPlayer = 'X';
    }

    return 0;
}

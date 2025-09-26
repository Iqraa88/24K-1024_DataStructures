#include <iostream>
using namespace std;
#include <cmath>

int N; 
int board[20];   
int solutions = 0;


bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
      
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}


void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i] == j) cout << "Q ";
            else cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}


void solve(int row, bool &printed) {
    if (row == N) {
        solutions++;
        if (!printed) {  
            cout << "One valid board configuration:\n";
            printBoard();
            printed = true;
        }
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;    
            solve(row + 1, printed);
        }
    }
}

int main() {
    cout << "Enter N: ";
    cin >> N;

    bool printed = false;
    solve(0, printed);

    cout << "Total distinct solutions = " << solutions << endl;
    return 0;
}

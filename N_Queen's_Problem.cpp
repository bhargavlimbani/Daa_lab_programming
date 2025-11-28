#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n = 4;
vector<vector<string>> solutions;

void printSolution(const vector<string> &board) {
    for (auto row : board) {
        cout << row << endl;
    }
    cout << endl;
}

bool is_safe(vector<string> &board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q')
            return false;
    }

    int i = row - 1, j = col - 1;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == 'Q')
            return false;
        i--; j--;
    }

    i = row - 1; j = col + 1;
    while (i >= 0 && j < n) {
        if (board[i][j] == 'Q')
            return false;
        i--; j++;
    }

    return true;
}

void solve(vector<string> &board, int row) {
    if (row == n) {
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (is_safe(board, row, col)) {
            board[row][col] = 'Q';
            solve(board, row + 1);
            board[row][col] = '.'; 
        }
    }
}

int main() {
    vector<string> board(n, string(n, '.'));

    solve(board, 0);

    cout << "Total solutions for 4x4: " << solutions.size() << "\n\n";

    for (auto &sol : solutions) {
        cout << "Solution:\n";
        printSolution(sol);
    }

    return 0;
}

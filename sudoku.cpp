#include <iostream>
using namespace std;

int grid[9][9];
bool rows[9][10];
bool cols[9][10];
bool boxc[9][10];

inline int boxIndex(int r, int c) {
    return (r / 3) * 3 + (c / 3);
}

void printGrid() {
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            cout << grid[r][c] << ' ';
            if (c % 3 == 2 && c != 8) cout << "| ";
        }
        cout << '\n';
        if (r % 3 == 2 && r != 8) cout << "------+-------+------\n";
    }
}

bool findEmpty(int &r, int &c) {
    for (r = 0; r < 9; ++r)
        for (c = 0; c < 9; ++c)
            if (grid[r][c] == 0) return true;
    return false;
}

bool solve() {
    int r, c;
    if (!findEmpty(r, c)) return true;

    int b = boxIndex(r, c);
    for (int num = 1; num <= 9; ++num) {
        if (!rows[r][num] && !cols[c][num] && !boxc[b][num]) {
            grid[r][c] = num;
            rows[r][num] = cols[c][num] = boxc[b][num] = true;

            if (solve()) return true;

            grid[r][c] = 0;
            rows[r][num] = cols[c][num] = boxc[b][num] = false;
        }
    }
    return false;
}

int main() {
    cout << "Enter the Sudoku puzzle row by row (use 0 for empty cells):\n";
    for (int i = 0; i < 9; i++) {
        cout << "Row " << i + 1 << " (9 numbers separated by spaces): ";
        for (int j = 0; j < 9; j++) {
            cin >> grid[i][j];
            if (grid[i][j] != 0) {
                int v = grid[i][j];
                rows[i][v] = true;
                cols[j][v] = true;
                boxc[boxIndex(i, j)][v] = true;
            }
        }
    }

    cout << "\nInput puzzle:\n";
    printGrid();

    if (solve()) {
        cout << "\nSolved puzzle:\n";
        printGrid();
    } else {
        cout << "\nNo solution exists.\n";
    }
    return 0;
}

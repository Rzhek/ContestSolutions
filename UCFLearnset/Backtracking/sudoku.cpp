#include <bits/stdc++.h>
using namespace std;

bool solveBoard(vector<vector<int>> &board, vector<vector<bool>> &rowFrq, vector<vector<bool>> &colFrq, vector<vector<bool>> &blockFrq, vector<int> &zeros, int idx) {
    if (idx >= zeros.size()) return true;
    int row = zeros[idx]/9, col = zeros[idx]%9;
    

    for (int i = 1; i <= board.size(); i++) {
        if (!rowFrq[row][i-1] && !colFrq[col][i-1] && !blockFrq[row/3*3 + col/3][i-1]) {
            board[row][col] = i;

            rowFrq[row][i-1] = true;
            colFrq[col][i-1] = true;
            blockFrq[row/3*3 + col/3][i-1] = true;
            if (solveBoard(board, rowFrq, colFrq, blockFrq, zeros, idx+1)) return true;
            rowFrq[row][i-1] = false;
            colFrq[col][i-1] = false;
            blockFrq[row/3*3 + col/3][i-1] = false;

            board[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int tests; cin >> tests;
    for (int a = 0; a < tests; a++) {

        vector<vector<int>> board(9, vector<int>(9, 0));

        vector<vector<bool>> rowFrq(9, vector<bool>(9, false));
        vector<vector<bool>> colFrq(9, vector<bool>(9, false));
        vector<vector<bool>> blockFrq(9, vector<bool>(9, false));
        vector<int> zeros;

        bool valid = true;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) { 
                cin >> board[i][j];
                if (board[i][j] != 0) {
                    if (rowFrq[i][board[i][j]-1] || colFrq[j][board[i][j]-1] || blockFrq[i/3*3 + j/3][board[i][j]-1]) valid = false;
                    rowFrq[i][board[i][j]-1] = true;
                    colFrq[j][board[i][j]-1] = true;
                    blockFrq[i/3*3 + j/3][board[i][j]-1] = true;
                } else {
                    zeros.push_back(i*9 + j);
                }
            }
        }


        cout << "Test case " << a+1 << ":" << endl;
        if (valid && solveBoard(board, rowFrq, colFrq, blockFrq, zeros, 0)) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) cout << board[i][j] << " ";
                cout << endl;
            }
        } else {
            cout << "No solution possible." << endl;
        }
        cout << endl;
    }
    return 0;
}
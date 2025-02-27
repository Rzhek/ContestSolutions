#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

int main() {
    int n; cin >> n;
    vector<string> board(n);
    for (string &row : board) cin >> row;
    
    vector<vector<int>> memo(n, vector<int>(n, 0));
    memo[0][0] = 1;

    for (int i = 0; i < memo.size(); i++) {
        for (int j = 0; j < memo.size(); j++) {
            if (board[i][j] == '*') continue; //Ignore obsticales
            if (j+1 < n) memo[i][j+1] = (memo[i][j+1]+memo[i][j])%MOD; //Go right
            if (i+1 < n) memo[i+1][j] = (memo[i+1][j]+memo[i][j])%MOD; // Go down

        }
    }
    cout << ((board[n-1][n-1] == '*') ? 0 : memo[n-1][n-1]) << endl;
    return 0;
}
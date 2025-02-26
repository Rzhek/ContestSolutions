#include <bits/stdc++.h>
using namespace std;

string grid_to_string(vector<vector<int>> &grid) {
    string hash = "";
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) hash += grid[i][j];
    return hash;
}

int main() {
    int n; cin >> n;

    map<string, int> visited;
    vector<vector<int>> board(3, vector<int>(3, 0));

    int gridnum = 1;
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) board[i][j] = (gridnum++)%9;

    queue<pair<vector<vector<int>>, int>> q;
    q.push({board, 0});

    int res = 0;
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        auto grid = p.first;
        int ans = p.second;
        string grid_hash = grid_to_string(grid);

        if (visited.find(grid_hash) == visited.end()) visited[grid_hash] = ans;
        else continue;

        pair<int, int> zero_pos = {0, 0};
        for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) if (grid[i][j] == 0) zero_pos = {i, j};
        
        if (zero_pos.first < 2) {
            swap(grid[zero_pos.first][zero_pos.second], grid[zero_pos.first+1][zero_pos.second]);
            q.push({grid, ans+1});
            swap(grid[zero_pos.first][zero_pos.second], grid[zero_pos.first+1][zero_pos.second]);
        } 
        if (zero_pos.first > 0) {
            swap(grid[zero_pos.first][zero_pos.second], grid[zero_pos.first-1][zero_pos.second]);
            q.push({grid, ans+1});
            swap(grid[zero_pos.first][zero_pos.second], grid[zero_pos.first-1][zero_pos.second]);
        }
        if (zero_pos.second < 2) {
            swap(grid[zero_pos.first][zero_pos.second], grid[zero_pos.first][zero_pos.second+1]);
            q.push({grid, ans+1});
            swap(grid[zero_pos.first][zero_pos.second], grid[zero_pos.first][zero_pos.second+1]);
        }
        if (zero_pos.second > 0) {
            swap(grid[zero_pos.first][zero_pos.second], grid[zero_pos.first][zero_pos.second-1]);
            q.push({grid, ans+1});
            swap(grid[zero_pos.first][zero_pos.second], grid[zero_pos.first][zero_pos.second-1]);
        }
    }
    while (n--) {
        vector<vector<int>> grid(3, vector<int>(3, 0));
        for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) cin >> grid[i][j];
        string grid_hash = grid_to_string(grid);
        cout << visited[grid_hash] << endl;
    }
    return 0; 
}
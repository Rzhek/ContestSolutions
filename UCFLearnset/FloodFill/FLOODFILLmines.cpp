#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    int mine[n][n][n] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cin >> mine[i][j][k];
            }
        }
    }
    int simulations; cin >> simulations;
    for (int i = 1; i <= simulations; i++) {
        int mineCopy[n][n][n];
        for (int a = 0; a < n; a++) for (int b = 0; b < n; b++) for (int c = 0; c < n; c++) mineCopy[a][b][c] = mine[a][b][c];

        int x, y, z; cin >> x >> y >> z;

        queue<vector<int>> q;

        int cleared = 0;
        q.push({x, y, z});
        while (!q.empty()) {
            int x = q.front()[0], y = q.front()[1], z = q.front()[2];
            q.pop();

            if (mineCopy[x][y][z] == 0) continue;
            cleared++;
            mineCopy[x][y][z] = 0;

            if (x+1 < n ) q.push({x+1, y, z}); 
            if (x-1 >= 0) q.push({x-1, y, z});
            if (y+1 < n ) q.push({x, y+1, z});
            if (y-1 >= 0) q.push({x, y-1, z});
            if (z+1 < n ) q.push({x, y, z+1});
            if (z-1 >= 0) q.push({x, y, z-1});
        }
        cout << "Simulation #"<<i<<", volume cleared is "<<cleared<<" cubic feet." << endl << endl;
    }
}
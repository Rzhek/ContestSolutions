#include <bits/stdc++.h>
using namespace std;

struct dsu {
    vector<int> par, sz;

    dsu(int n) {
        par = vector<int>(n);
        sz = vector<int>(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int find(int u) {
        if (par[u] != u) return par[u] = find(par[u]);
        return par[u];
    }

    bool join(int u, int v) {
        int a = find(u), b = find(v);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        par[b] = par[a];
        sz[a] += sz[b];
        return true;
    }
};

int main() {
    int n, m, q; cin >> n >> m >> q;
    vector<vector<int>> art(m, vector<int>(n, 0));
    stack<pair<int, int>> colored; //Coords -1 -1 will be placed to indicate a section

    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            for (int j = y1-1; j < y2; j++) {
                if (art[j][x1-1] == 0) colored.push({j, x1-1});
                art[j][x1-1] = 1;
            }
        } else if (y1 == y2) {
            for (int j = x1-1; j < x2; j++) {
                if (art[y1-1][j] == 0) colored.push({y1-1, j});
                art[y1-1][j] = 1;
            }
        }
        colored.push({-1, -1});
    }
    for (int i = 0; i < art.size(); i++) {
        for (int j = 0; j < art[i].size(); j++) {
            if (art[i][j] == 0) colored.push({i, j});
            art[i][j] = 1;
        }
    }

    dsu u(m*n);

    int curRes = 0;
    stack<int> res;
    while (!colored.empty()) {
        pair<int, int> coord = colored.top();
        int y = coord.first, x = coord.second;
        colored.pop();
        if (x == -1 && y == -1) {
            res.push(curRes);
            continue;
        }

        int joins = 0;
        if (x+1 < n && art[y][x+1] == 0) joins += u.join(y*n+x, y*n+(x+1));
        if (x-1 >= 0 && art[y][x-1] == 0) joins += u.join(y*n+x, y*n+(x-1)); 
        if (y+1 < m && art[y+1][x] == 0) joins += u.join(y*n+x, (y+1)*n+x); 
        if (y-1 >= 0 && art[y-1][x] == 0) joins += u.join(y*n+x, (y-1)*n+x); 
        curRes += (1-joins);

        art[y][x] = 0; 
    }

    while(!res.empty()) {
        cout << res.top() << endl;
        res.pop();
    }
    return 0;
}
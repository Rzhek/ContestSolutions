#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &list, int log, int v,  vector<vector<int>> &up, vector<int> &depth, vector<int> &visited) {
    visited[v] = 1;
    for (int i = 0; i < list[v].size(); i++) {
        int u = list[v][i];
        if (visited[u] == 1) continue;
        
        up[u][0] = v;
        depth[u] = depth[v]+1;
        for (int j = 1; j < log; j++) {
            up[u][j] = up[up[u][j-1]][j-1];
        }
        dfs(list, log, u, up, depth, visited);
    }
}

int findLCA(int a, int b, int LOG, vector<vector<int>> &up, vector<int> &depth) {
    if (depth[a] < depth[b]) swap(a, b);
    int k = depth[a]-depth[b];
    for (int i = LOG-1; i >= 0; i--)
        if (k & (1 << i)) a = up[a][i];
    if (a == b) return a;
    for (int i = LOG-1; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> adjList(n+1, vector<int>());
        adjList[0].push_back(1);

        for (int i = 0; i < n-1; i++) {
            int a, b; cin >> a >> b;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }

        int LOG = (int)ceil(log(n+1)/log(2));
        vector<vector<int>> up(n+1, vector<int>(LOG, 0));
        vector<int> depth(n+1);
        depth[0] = 0;

        vector<int> visited(n+1, 0);
        dfs(adjList, LOG, 0, up, depth, visited);

        vector<int> perm(n, 0);
        for (int i = 0; i < n; i++) cin >> perm[i];

        bool pass = true;
        for (int i = 0; i < n-1; i++) {
            int lca = findLCA(perm[i], perm[i+1], LOG, up, depth);
            if ((depth[perm[i]]-depth[lca]) + (depth[perm[i+1]]-depth[lca]) > 3) {
                pass = false;
                break;
            }
        }
        if (pass) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}
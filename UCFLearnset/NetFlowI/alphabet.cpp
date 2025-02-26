#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &graph, int source, int sink, vector<int> &parent, vector<int> &visited) {
    visited[source] = 1;
    for (int i = 0; i < graph[source].size(); i++) {
        if (graph[source][i] > 0 && !visited[i]) {
            if (i == sink) {
                parent[i] = source;
                return true;
            }
            parent[i] = source;
            if (dfs(graph, i, sink, parent, visited)) return true;
        }
    }

    return false;
}
 

int ff(vector<vector<int>> graph, int source, int sink) {

    int u, v;
    int max_flow = 0;

    vector<int> parent(graph.size(), 0);

    vector<int> visited(graph.size(), 0);
    while(dfs(graph, source, sink, parent, visited)) {
        int path_flow = INT_MAX;
        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, graph[u][v]);
        }
 
        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            graph[u][v] -= path_flow;
            graph[v][u] += path_flow;
        }

        max_flow += path_flow;
        visited = vector<int>(graph.size(), 0);
    }

    return max_flow;
}

int main() {
    int n; cin >> n;
    while (n--) {
        string redLetters, greenLetters; cin >> redLetters >> greenLetters;
        int graphSize = redLetters.size()+greenLetters.size()+2;

        int source = 0;
        int redLetterStart = source+1;
        int greenLetterStart = redLetterStart+redLetters.size();
        int sink = greenLetterStart+greenLetters.size();


        vector<vector<int>> graph(graphSize, vector<int>(graphSize, 0));

        for (int i = 0; i < redLetters.size(); i++) graph[source][i+redLetterStart] = 1; //Make edges for source

        for (int i = 0; i < redLetters.size(); i++) { //Make edges between redLetters and greenLetters
            for (int j = 0; j < greenLetters.size(); j++) {
                if (abs(greenLetters[j]-redLetters[i]) >= 3) graph[redLetterStart+i][greenLetterStart+j] = 1;
            }
        }

        for (int i = 0; i < greenLetters.size(); i++) graph[i+greenLetterStart][sink] = 1; //Make edges between green letters and sink


        cout << ff(graph, source, sink) << endl;
    }
    return 0;
}
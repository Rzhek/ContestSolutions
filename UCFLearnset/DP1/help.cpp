#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int solve(vector<pair<int, int>> &problems, int idx, int time) {
    if (idx >= problems.size() || time == 0) return 0;
    
    if (dp[idx][time] != -1) return dp[idx][time];
    if (problems[idx].first <= time) {
        return dp[idx][time] = max(problems[idx].second+solve(problems, idx+1, time-problems[idx].first), solve(problems, idx+1, time));
    } else {
        return dp[idx][time] = solve(problems, idx+1, time);
    }
}

int main() {
    int d; cin >> d;
    for (int i = 0; i < d; i++) {
        int n, t; cin >> n >> t;
        vector<pair<int, int>> problems(n, {0, 0}); //Holds time to answer question and value of question respectively
        for (int j = 0; j < n; j++) {
            cin >> problems[j].first;
            cin >> problems[j].second;
        }
        dp = vector<vector<int>>(n+1, vector<int>(t+1, -1));
        cout << "Day #"<<(i+1)<<": "<<solve(problems, 0, t)<<endl;
    }

    return 0;
}
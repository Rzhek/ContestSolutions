#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> memo;

long long solve(string s1, string s2, int idxS1, int idxS2) {
    if (idxS2 >= s2.size()) return 1;
    if (idxS1 >= s1.size()) return 0;

    if (memo[idxS1][idxS2] != -1) return memo[idxS1][idxS2];

    if (s1[idxS1] == s2[idxS2]) 
        return memo[idxS1][idxS2] = solve(s1, s2, idxS1+1, idxS2+1)+solve(s1, s2, idxS1+1, idxS2);
    else 
        return memo[idxS1][idxS2] = solve(s1, s2, idxS1+1, idxS2);
}

int main() {
    int n; cin >> n;
    while (n--) {
        string s1, s2; cin >> s1 >> s2;
        memo = vector<vector<long long>>(s1.size(), vector<long long>(s2.size(), -1));
        cout << solve(s1, s2, 0, 0) << endl;
    }
    return 0;
}
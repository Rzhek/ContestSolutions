#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> mat[i][j];
    
    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        string s; cin >> s;

        int res = 0;
        for (int j = 0; j < s.size()-1; j++) res += mat[s[j]-'A'][s[j+1]-'A'];
        cout << res << endl;
    }
    return 0;
}
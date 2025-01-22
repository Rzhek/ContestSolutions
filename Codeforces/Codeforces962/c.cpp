#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        string a, b; cin >> a >> b;

        vector<vector<int>> prefix;
        prefix.push_back(vector<int>(26, 0));

        for (int i = 0; i < n; i++) {
            int Apos = a[i]-'a', Bpos = b[i]-'a';
            vector<int> alphabet(26, 0);
            for (int j = 0; j < 26; j++) alphabet[j] = prefix[i][j];

            alphabet[Apos]--;
            alphabet[Bpos]++;
            prefix.push_back(alphabet);
        }

        for (int i = 0; i < q; i++) {
            int l, r; cin >> l >> r;

            int change = 0;
            for (int j = 0; j < 26; j++) change += abs(prefix[r][j]-prefix[l-1][j]);
            cout << change/2 << endl;
            
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    while (n--) {
        int k; cin >> k;
        vector<vector<int>> vals(k, vector<int>(3, 0));
        for (int i = 0; i < k; i++) {
            cin >> vals[i][0];
            cin >> vals[i][1];
            cin >> vals[i][2];
        }
        sort(vals.begin(), vals.end(), [](auto a, auto b) {
            return a[0] < b[0];
        });
        for (int i = 0; i < k; i++) {
            int max = 0;
            for (int j = 0; j < i; j++) if (vals[i][0]-vals[j][2] >= vals[j][0] && vals[j][1] > max) max = vals[j][1];
            vals[i][1] += max;
        }
        int res = 0;
        for (int i = 0; i < k; i++) res = max(res, vals[i][1]);
        cout << res << endl;
    }
    return 0;
}
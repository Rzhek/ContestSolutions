#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    for (int a = 0; a < n; a++) {
        int k; cin >> k;
        vector<int> neighbors(k+2, 0);
        vector<pair<int, vector<int>>> dp(k+2, {0, vector<int>()});
        for (int i = 0; i < k; i++) {
            cin >> neighbors[i+2];

            int combo1 = neighbors[i+2]+dp[i].first, combo2 = dp[i+1].first;
            if (combo1 > combo2) {
                dp[i+2].first = combo1;
                dp[i+2].second = dp[i].second;
                dp[i+2].second.push_back(i);
            } else if (combo2 > combo1) {
                dp[i+2].first = combo2;
                dp[i+2].second = dp[i+1].second;
            } else {
                dp[i+2].first = combo1;

                int val1 = 1e9, val2 = 1e9;
                if (dp[i].second.size() != 0) val1 = dp[i].second[0];
                if (dp[i+1].second.size() != 0) val2 = dp[i+1].second[0];

                if (val1 < val2) {
                    dp[i+2].second = dp[i].second;
                    dp[i+2].second.push_back(i);
                } else {
                    dp[i+2].second = dp[i+1].second;
                }
            }
        }

        int max = dp[k+1].first;
        cout << "Case #" << (a+1) << ": " << max << " : ";

        for (int i = 0; i < dp[k+1].second.size(); i++) cout << dp[k+1].second[i] << " ";
        cout << endl;
    }

    return 0;
}
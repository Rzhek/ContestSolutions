#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD (ll)(1e9+7)

vector<vector<ll>> memo;

ll solve(vector<int> coins, int idx, int change) {
    if (change == 0) return 1;
    if (idx >= coins.size() || change < 0) return 0;

    if (memo[idx][change] != -1) return memo[idx][change];
    return memo[idx][change] = (solve(coins, idx, change-coins[idx]) + solve(coins, idx+1, change)) % MOD;
}

int main() {
    int n; cin >> n;
    while (n--) {
        int change, ac; cin >> change >> ac;
        vector<int> coins(ac);
        for (int i = 0; i < ac; i++) cin >> coins[i];
        memo = vector<vector<ll>>(ac, vector<ll>(change+1, -1));
        cout << solve(coins, 0, change) << endl;
    }
    return 0;
}
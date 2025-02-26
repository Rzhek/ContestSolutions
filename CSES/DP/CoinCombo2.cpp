#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

int main() {
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for (int &coin: coins) cin >> coin;

    vector<int> count_distinct(x+1);
    count_distinct[0] = 1;
    for (int i = 0; i < coins.size(); i++) {
        int coin = coins[i];
        for (int j = coin; j < count_distinct.size(); j++) {
            int jump = j-coin;
            count_distinct[j] += count_distinct[jump];
            count_distinct[j] %= MOD;
        }
    }
    cout << count_distinct[x] << endl;
    return 0;
}
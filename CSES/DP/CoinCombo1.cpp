#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

int main() {
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for (int &coin : coins) cin >> coin;

    vector<int> count(x+1);
    count[0] = 1;
    for (int i = 0; i < count.size(); i++) {
        for (int j = 0; j < coins.size(); j++) {
            int jump = i-coins[j];
            if (jump >= 0) {
                count[i] += count[jump];
                count[i] %= MOD;  
            }
        }
    }
    cout << count[x] << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for (int &coin : coins) cin >> coin;

    vector<int> val(x+1, 1e9);
    val[0] = 0;
    for (int i = 0; i < val.size(); i++) {
        for (int j = 0; j < coins.size(); j++) {
            int jump = i+coins[j];
            if (jump < val.size()) {
                val[jump] = min(val[i]+1, val[jump]);
            }
        }
    }
    if (val[x] == 1e9) cout << -1 << endl;
    else cout << val[x] << endl;
    
    return 0;
}
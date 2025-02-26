#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

int main() {
    int n; cin >> n;
    vector<ll> vec(n+1, 0);
    for (int i = 0; i < n+1; i++) {
        for (int j = i+1; j <= min(i+6, n); j++) 
            vec[j] = (vec[j]+max(vec[i],1ll))%MOD;
    }
    cout << vec[n] << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    int t; cin >> t;
    while (t--) {
        ll res = 0;
        ll n, x; cin >> n >> x;
        for (ll a = 1; (a <= x-2) && (2*a <= n); a++) {
            for (ll b = 1; (a*b+a+b <= n) && (a+b <= x-1); b++) {
                res += min(x-(a+b), (n-(a*b))/(a+b));
            }
        }
        cout << res << endl;
    }
}
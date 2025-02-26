#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    for (int tests = 1; tests <= t; tests++) {
        int n; cin >> n;
        long res = 0, adder = 1;
        for (int i = 1; i <= n; i++) {
            adder += (i+1);
            res += i*adder;
        }
        cout << tests << " " << n << " " << res << endl;
    }
    return 0;
}
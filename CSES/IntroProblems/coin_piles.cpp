#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;

        if ((a+b) % 3 == 0) cout << (b > 2*a ? "NO" : a > 2*b ? "NO" : "YES") << endl;   
        else cout << "NO" << endl;
    }
    return 0;   
}
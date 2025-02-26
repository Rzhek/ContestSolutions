#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;
    long long expected = n*(n+1)/2;
    long long actual = 0;

    for (int i = 0; i < n-1; i++) {
        int tmp; cin >> tmp;
        actual += tmp;
    }

    cout << expected-actual << endl;
    return 0;
}
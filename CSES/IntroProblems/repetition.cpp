#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int mx = 0;

    int tmp = 0;
    char prev = ' ';
    for (char c : s) {
        if (c != prev) {
            tmp = 0;
            prev = c;
        }
        tmp++;
        mx = max(mx, tmp);
    }
    cout << mx << endl;
    return 0;
}
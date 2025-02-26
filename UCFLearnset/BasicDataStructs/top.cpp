#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    vector<string> list1(n), list2(n);
    for (int i = 0; i < n; i++) cin >> list1[i];
    for (int i = 0; i < n; i++) cin >> list2[i];

    map<string, int> mp;

    int bal = 0, prev = -1;
    for (int i = 0; i < n; i++) {
        if (++mp[list1[i]] == 1) bal += 1;
        else bal -= 1;

        if (++mp[list2[i]] == 1) bal += 1;
        else bal -= 1;

        if (bal == 0) {
            cout << (i - prev) << endl;
            prev = i;
        } 
    }
    return 0;
}
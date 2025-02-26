#include <bits/stdc++.h>
using namespace std;

set<string> res;
void solve(string &s, int idx) {
    if (idx >= s.size()) {
        res.insert(s);
        return;
    }

    for (int i = idx; i < s.size(); i++) {
        swap(s[idx], s[i]);
        solve(s, idx+1);
        swap(s[idx], s[i]);
    }
}

int main() {
    string s; cin >> s;
    solve(s, 0);
    cout << res.size() << endl;
    for (auto str : res) {
        cout << str << endl;
    }
    return 0;
}
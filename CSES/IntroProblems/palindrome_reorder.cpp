#include <bits/stdc++.h>
using namespace std;


string rev(string s) {
    reverse(s.begin(), s.end());
    return s;
}

string solve(map<char, int> &mp) {
    string tmp = "";
    string res = "";
    for (auto [k, v] : mp) {
        int letters = v/2;
        for (int i = 0; i < letters; i++) res += k;
        if (v%2 == 1) {
            if (tmp != "") return "NO SOLUTION";
            tmp = k;
        }
    }
    res = res + tmp + rev(res);
    return res;
}
int main() {
    string s; cin >> s;
    map<char, int> mp;
    for (char c : s) mp[c] += 1;

    cout << solve(mp) << endl;
    return 0;
}
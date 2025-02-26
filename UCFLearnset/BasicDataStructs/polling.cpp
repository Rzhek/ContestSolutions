#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    map<string, int> mp;

    int max = 0;
    vector<string> winners;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int votes = ++mp[s];
        if (votes > max) {
            winners.clear();
            max = votes;
            winners.push_back(s);
        } else if (votes == max) {
            winners.push_back(s);
        }
    }
    sort(winners.begin(), winners.end());
    for (int i = 0; i < winners.size(); i++) cout << winners[i] << endl;

    return 0;
}
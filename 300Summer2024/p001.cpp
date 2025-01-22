#include <bits/stdc++.h>
using namespace std;

int total = 0, totalMax = 0;
vector<string> res;

void addPermutation(string ans, int k, int n) {
    if (n == 0) {
        res.push_back(ans);
        total++;
        return;
    }

    int startPos = ans.size() == 0 ? 0 : ans[ans.size()-1]-'a'+k+1;
    for (int i = startPos; i < 26; i++) {
        if (total < totalMax) addPermutation(ans+(char)(i+'a'), k, n-1);
        else break;
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int k, n, r; cin >> k >> n >> r;
        total = 0;
        totalMax = r;
        res = vector<string>();
        addPermutation("", k, n);
        cout << res[r-1] << endl;
    }
    return 0;
}
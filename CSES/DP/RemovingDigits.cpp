#include <bits/stdc++.h>
using namespace std;

vector<int> find_digits(int n) {
    vector<int> res;
    while (n != 0) {
        res.push_back(n%10);
        n /= 10;
    }
    return res;
}
int main() {
    int n; cin >> n;
    vector<int> memo(n+1, 1e9);
    memo[n] = 0;
    for (int i = memo.size()-1; i >= 0; i--) {
        if (memo[i] != 1e9) {
            vector<int> digits = find_digits(i);
            for (int digit : digits) {
                int jump = i-digit;
                if (jump >= 0) memo[jump] = min(memo[i]+1, memo[jump]);
            }
        }
    }
    cout << memo[0] << endl;
    return 0;
}
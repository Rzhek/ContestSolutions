#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int tests; cin >> tests;
    while (tests--) {
        int n; cin >> n;

        priority_queue<int, vector<int>, greater<int>> minq;
        for (int i = 0; i < n; i++) {
            int val; cin >> val;
            minq.push(val);
        }
        long long res = 0;

        int num = 0;
        while(!minq.empty()) {
            if (num == 0) {
                num = minq.top();
            } else {
                num += minq.top();
                res += num;
                minq.push(num);
                num = 0;
            }
            minq.pop();
        }
        cout << res << endl;
    }   
    return 0;
}
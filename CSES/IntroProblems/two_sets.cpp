#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    vector<stack<int>> nums = {{}, {}};
    vector<ll> totals = {0, 0};

    int n; cin >> n;
    for (int i = n; i > 0; i--) {
        int lower_idx = 0;
        if (totals[lower_idx+1] < totals[lower_idx]) lower_idx += 1;

        totals[lower_idx] += i;
        nums[lower_idx].push(i);
    }

    if (totals[0] == totals[1]) {
        cout << "YES" << endl;
        
        int gli = 0;
        if (nums[gli+1].size() > nums[gli].size()) gli += 1;

        cout << nums[gli].size() << endl;
        while (!nums[gli].empty()) {
            cout << nums[gli].top() << " ";
            nums[gli].pop();
        }
        cout << endl;

        int oi = (gli+1)%2;
        cout << nums[oi].size() << endl;
        while (!nums[oi].empty()) {
            cout << nums[oi].top() << " ";
            nums[oi].pop();
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int tests; cin >> tests;
    for (int a = 1; a <= tests; a++) {
        int n; cin >> n;

        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            string throwAway; cin >> throwAway;
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());
        cout << "Case #" << a << ": " << nums[n-1] << " " << nums[0] << " " << ((n%2 == 1)?(nums[(n-1)/2]):(nums[(n-1)/2]+nums[(n-1)/2+1])/2.0) << endl;
    }
    return 0;
}
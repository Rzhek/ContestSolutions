#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;

        vector<int> nums(k);
        int cur = 0, fruit = 0;
        for (int j = 0; j < k; j++) {
            int f; cin >> f;
            nums[j] = f;
            cur += f;
            fruit = max(fruit, (int)ceil(cur/(double)(j+1)));
        }
        
        int extra = 0, maxExtra = 0;
        for (int j = 0; j < k; j++) {
            extra += fruit-nums[j];
            maxExtra = max(maxExtra, extra);
        }
        cout << fruit << " " << maxExtra << endl;
    }
    return 0;
}
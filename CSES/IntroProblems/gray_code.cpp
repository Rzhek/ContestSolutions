#include <bits/stdc++.h>
using namespace std;

string to_bin(int n, int min_len) {
    string res = "";
    while (n != 0) {
        res = to_string(n%2)+res;
        n /= 2;
    }
    while (res.size() < min_len) res = "0"+res;
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    
    vector<int> nums = {0, 1};
    int add_pow = 1;
    while (add_pow != n) {
        int add = pow(2, add_pow);
        for (int i = nums.size()-1; i >= 0; i--) nums.push_back(nums[i]+add);
        add_pow++;
    }
    for (int num : nums) cout << to_bin(num, n) << "\n";
    return 0;
}
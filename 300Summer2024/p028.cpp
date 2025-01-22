#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<int> res(nums[0], -1);
    int counter = 0;

    for (int i = 1; i < n; i++) {
        int in = i+1;
        int ourAns = in*res.size();
        for (int j = 0; j < res.size(); j++) {
            if (res[j] == -1) break;
            ourAns -= (in - (in%res[j]));
        }
        while (ourAns != nums[i]) {
            res[counter++] = in;
            ourAns -= in;
        }
    }

    cout << res.size();
    for (int i = 0; i < res.size(); i++) cout << " " << res[i];
    cout << endl;

    return 0;   
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    while (n != 0) {
        vector<int> arr(n+1, 0);

        int max = -1e9;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            arr[i] += arr[i-1];
            if (arr[i] > max) max = arr[i];
            if (arr[i] < 0) arr[i] = 0;
        }
        cout << max << endl;

        cin >> n;
    }
    return 0;
}
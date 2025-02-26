#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << fixed << setprecision(2);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int steps;
        double stepDistance;
        cin >> steps >> stepDistance;

        double res = 0;
        for (int j = 0; j < steps; j++) {
            double tmp; cin >> tmp;
            res += stepDistance/tmp;
        }
        cout << res << endl;
    }
    return 0;
}
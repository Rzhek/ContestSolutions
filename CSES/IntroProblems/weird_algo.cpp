#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EVEN(n) (n%2==0)

int main() {
    ll n; cin >> n;
    while (n != 1) {
        cout << n << " ";
        n = EVEN(n) ? n/2 : n*3+1; 
    }
    cout << n << endl;
    return 0;
}
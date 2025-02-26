#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n) {
    switch(n) {
        case 1: return 0;
        case 2: return 6;
        case 3: return 28;
        default:
            ll total = (n*n)*(n*n-1)/2; //Arithmatic Series on all squares the 2nd knight can be placed
            total -= 4*(n*n); //Assume all knights will take 4 spots forward and remove them

            //Add back the spots where knights don't actually block 4 spots

            //(2(n-2)*2) + (2(n-2)) + ((n-4)*2) + (n*4) + (4*3) 
            //4n - 8 + 2n - 4 + 2n - 8 + 4n + 12
            //12n - 8
            total += 12*n - 8;
            return total;
    }
}

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cout << solve((ll)i) << endl;
    return 0;
}
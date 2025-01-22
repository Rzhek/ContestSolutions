#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll x, ll y) {
    //Formula for spiral bound 
    //1  2  X  10
    //4  3  X  11
    //X  X  X  12
    //16 15 14 13

    //Given x and y => n-1 is the max(x-1, y-1)
    //2 + (3 + 5 + 7... + K_(n-1)) : formula for finding start of bound
    //(n-1) is odd means start bound is on top otherwise it's left
    
    ll n = max(x-1, y-1);
    if (n == 0) return 1;

    ll start_bound = 2 + (n == 1 ? 0 : n == 2 ? 3 : (n-1)*(2*n-1 + 3)/2);
    ll bound_coords[2] = {0}; //New X, Y
    //N is odd, x (0) is n, y (1) is 0
    //N is even, x (0) is 0, y (1) is n 
    bound_coords[n%2] = 1; 
    bound_coords[1-n%2] = n+1;

    return start_bound+abs(x-bound_coords[0])+abs(y-bound_coords[1]);
}

int main() {
    int t; cin >> t;
    while (t--) {
        ll x, y;
        cin >> y >> x;
        cout << solve(x, y) << endl;
    }
    return 0;
}
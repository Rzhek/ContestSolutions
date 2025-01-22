#include <bits/stdc++.h>
using namespace std;

int main() {
    long long m, n; cin >> m >> n;
    long long total = (((ceil(n/2.0)*m*6)-(ceil(n/2.0)*(m-1))) + ((floor(n/2.0)*(m-1)*6)-(floor(n/2.0)*(m-2)))) - ((n-1)*((m-1)*2));

    vector<int> pattern;
    if (m%2 == 0) {
        pattern.push_back(m/2); //Even
        pattern.push_back(ceil((m-1)/2.0)); //Odd
        pattern.push_back(ceil((m-1)/2.0)); //Even -> Odd
        pattern.push_back((m-2)/2); //Odd -> Even
    } else {
        pattern.push_back(ceil(m/2.0)); //Odd
        pattern.push_back(ceil((m-2)/2.0)); //Even -> Odd
        pattern.push_back((m-1)/2); //Odd -> Even
        pattern.push_back((m-1)/2); //Even
    }
    long long totalSub = 0;
    for (int i = 0; i < pattern.size(); i++) {
        totalSub += n%pattern.size() > i ? ((n/pattern.size())+1)*pattern[i] : (n/pattern.size())*pattern[i];
    }

    cout << total-totalSub+1 << endl;
    return 0;
}
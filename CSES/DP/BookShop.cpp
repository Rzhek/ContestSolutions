#include <bits/stdc++.h>
using namespace std;
struct book {
    int cost;
    int pages;
};

int main() {
    int n, x; cin >> n >> x;
    vector<int> memo(x+1, 0);

    vector<book> books(n);
    for (int i = 0; i < n; i++) cin >> books[i].cost;
    for (int i = 0; i < n; i++) cin >> books[i].pages;

    int res = 0;
    for (int i = 0; i < books.size(); i++) {
        book b = books[i];
        for (int j = b.cost; j <= x; j++) {
            int jump = j-b.cost;
            memo[jump] = max(memo[jump], b.pages+memo[j]);
            res = max(memo[jump], res);
        }
    }
    cout << res << endl;
    return 0;
}
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

typedef long long ll;

vector<vector<ll>> matMult(vector<vector<ll>> &mat1, vector<vector<ll>> &mat2, ll mod);
vector<vector<ll>> fastMatPow(vector<vector<ll>> &mat, ll p, ll mod);

void printMat(vector<vector<ll>> mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<ll>> mat({{0, 1, 1, 0, 1}, {1, 0, 0, 0, 0}, {0, 1, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 1, 0}});
    int t; cin >> t;
    while (t--) {
        ll n, mod; cin >> n >> mod;
        cout << fastMatPow(mat, n, mod)[0][0] << endl;
    }
    return 0;
}

vector<vector<ll>> fastMatPow(vector<vector<ll>> &mat, ll p, ll mod) {
    if (p == 1) return mat;
    vector<vector<ll>> res = fastMatPow(mat, p/2, mod);
    res = matMult(res, res, mod);

    if (p%2 == 1) res = matMult(res, mat, mod);
    return res;
}

vector<vector<ll>> matMult(vector<vector<ll>> &mat1, vector<vector<ll>> &mat2, ll mod) {
    assert(mat1[0].size() == mat2.size());

    vector<vector<ll>> res(mat1.size(), vector<ll>(mat2[0].size()));
    for (int i = 0; i < mat1.size(); i++) {
        for (int j = 0; j < mat2[0].size(); j++) {
            int tmp = 0;
            for (int k = 0; k < mat1[i].size(); k++) tmp += mat1[i][k]*mat2[k][j] % mod;
            res[i][j] = tmp % mod;
        }
    }
    return res;
}
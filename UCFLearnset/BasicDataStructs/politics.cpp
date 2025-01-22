#include <bits/stdc++.h>
using namespace std;

int main() {
    int can, sup; cin >> can >> sup;

    while (can != 0 && sup != 0) {
        map<string, int> mp;
        for (int i = 0; i < can; i++) {
            string s; cin >> s;
            mp[s] = i+1;
        }

        vector<vector<string>> list(can, vector<string>());
        for (int i = 0; i < sup; i++) {
            string supName, supCan; cin >> supName >> supCan;
            if (mp[supCan] == 0) {
                list.push_back(vector<string>());
                list[can].push_back(supName);
                mp[supCan] = can+1;
                can++;
            } else {
                list[mp[supCan]-1].push_back(supName);
            }
        }
        for (int i = 0; i < list.size(); i++)
            for (int j = 0; j < list[i].size(); j++) 
                cout << list[i][j] << endl;
        cin >> can >> sup;
    }
    return 0;
}
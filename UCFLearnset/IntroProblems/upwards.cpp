#include <bits/stdc++.h>
using namespace std;

int main() {
  int cases; cin >> cases;
  while (cases--) {
    bool res = true;
    
    string s; cin >> s;
    int letters[26] = {0};
    for (int i = 0; i < s.size(); i++) if (letters[s[i]-'a']++ == 1) res = false;
    
        
    string sCpy = s.c_str();
    sort(s.begin(), s.end());
    if (sCpy != s) res = false;
    cout << (res ? "YES" : "NO") << endl;
  }
  return 0;
}
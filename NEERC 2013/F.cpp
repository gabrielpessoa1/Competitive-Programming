#include <bits/stdc++.h>
using namespace std;
 
main() {
  cin.tie(0); ios::sync_with_stdio(0);
  #ifdef ONLINE_JUDGE
  freopen("fraud.in", "r", stdin);
  freopen("fraud.out", "w", stdout);
  #endif
  string s;
  int n;
  vector<string> ans;
  cin >> s >> n;
  while(n--) {
    string t;
    cin >> t;
    bool valid = true;
    for(int i = 0; i < 9; i++) {
      if(s[i] != '*' && s[i] != t[i]) valid = false;
    }
    if(valid) ans.push_back(t);
  }
  cout << ans.size() << '\n';
  for(string &k : ans) cout << k << '\n';
}
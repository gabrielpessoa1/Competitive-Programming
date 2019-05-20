#include <bits/stdc++.h>
using namespace std;

const int ms = 1e5+5;

string s[3];

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    for(int i = 0; i < 3; i++) cin >> s[i];
    int ans = 0;
    for(int i = 0; i < n; i++) {
      int cur = 0;
      for(int j = 0; j < 3; j++) {
        for(int k = 0; k < 3; k++) {
          if(s[j][i*3+k] == '*') cur += 4;
        }
      }
      ans = max(ans, cur);
    }
    cout << ans << '\n';
  }
}
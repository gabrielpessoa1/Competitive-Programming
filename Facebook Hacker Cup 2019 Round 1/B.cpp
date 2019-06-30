#include <bits/stdc++.h>
using namespace std;

const int ms = 1e6+5;

int mod = 1e9+7;
int cost[ms];

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int t;
  cin >> t;
  for(int T = 1; T <= t; T++) {
    cout << "Case #" << T << ": ";
    int n, k;
    string s;
    cin >> n >> k >> s;
    int cur = 0;
    int ans = 0;
    cost[0] = 2;
    for(int i = 1; i < n; i++) {
      cost[i] = (cost[i-1] + cost[i-1]) % mod;
    }
    for(int i = n-1; i >= 0; i--) {
      cur = max(cur, 0);
      if(s[i] == 'A') cur--;
      else cur++;
      if(cur > k) {
        cur -= 2;
        ans = (ans + cost[i]) % mod;
      }
    }
    cout << ans << '\n';
  }
}
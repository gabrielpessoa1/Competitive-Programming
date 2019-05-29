#include <bits/stdc++.h>
using namespace std;

const int ms = 1e5+5;

int t[ms];

main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int m;
  cin >> m;
  for(int T = 1; T <= m; T++) {
    int n, sum = 0, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
      cin >> t[i];
    }
    sort(t, t+n);
    for(int i = 0; i < n; i++) {
      if(sum <= t[i]) {
        sum += t[i];
        ans++;
      }
    }
    cout << "Case #" << T << ": " << ans << '\n';
  }
}
#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;

main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int d;
  cin >> d;
  for(int T = 1; T <= d; T++) {
    int n, s;
    cin >> n >> s;
    int ans = -inf;
    for(int i = 0; i < n; i++) {
      int f, t;
      cin >> f >> t;
      ans = max(ans, t <= s ? f : f - (t - s));
    }
    cout << "Case #" << T << ": " << ans << '\n';
  }
}
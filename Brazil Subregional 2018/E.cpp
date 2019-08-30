#include <bits/stdc++.h>
using namespace std;

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  string a, b;
  cin >> a >> b;
  int n = a.size(), m = b.size();
  int ans = 0;
  for(int i = 0; i <= n-m; i++) {
    int poss = 1;
    for(int j = 0; j < m; j++) {
      poss = poss && (a[i+j] != b[j]);
    }
    ans += poss;
  }
  cout << ans << '\n';
}
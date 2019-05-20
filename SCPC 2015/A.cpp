#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 1e5+5;
const int inf = 0x3f3f3f3f3f3f3f3fll;

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int lo = 0, hi = inf;
    int cur = 0;
    for(int i = 0; i < n; i++) {
      int a;
      string s;
      cin >> a >> s;
      a += 25;
      if(s[0] == '-') {
        hi = min(hi, cur+a);
      } else {
        lo = max(lo, cur+a);
        cur += a;
      }
    }
    cout << max(0ll, hi - lo) << '\n';
  }
}
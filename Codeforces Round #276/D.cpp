#include <bits/stdc++.h>
using namespace std;

#define int long long

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n;
  cin >> n;
  int lo, hi, ans = 0;
  cin >> lo;
  hi = lo;
  for(int i = 1; i < n; i++) {
    int x;
    cin >> x;
    if(x < lo) {
      ans += lo - x;
      lo = x;
    } else if(x > hi) {
      ans += x - hi;
      hi = x;
    } else {
      lo = x;
      hi = x;
    }
  }
  cout << ans << '\n';
}
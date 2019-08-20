#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 105;

int solve(int rh, int rv, int sh, int sv, int ah, int av, int bh, int bv, int p) {
  int mh = max((rh-1+ah)/ah, (sh-1+bh)/bh);
  int mv = max((rv-1+av)/av, (sv-1+bv)/bv);
  return mh * mv * p;
}

main() {
  #ifdef ONLINE_JUDGE
  freopen("giant.in", "r", stdin);
  freopen("giant.out", "w", stdout);
  #endif
  int rh, rv, sh, sv;
  cin >> rh >> rv >> sh >> sv;
  int ans = 0x3f3f3f3f3f3f3f3f;
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int ah, av, bh, bv, p;
    cin >> ah >> av >> bh >> bv >> p;
    ans = min(ans, solve(rh, rv, sh, sv, ah, av, bh, bv, p));
    ans = min(ans, solve(rh, rv, sh, sv, av, ah, bv, bh, p));
  }
  cout << ans << '\n';
}
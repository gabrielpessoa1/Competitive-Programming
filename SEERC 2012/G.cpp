#include <bits/stdc++.h>
using namespace std;

const int ms = 1e4+5;
const int inf = 0x3f3f3f3f;

int n;
pair<int, int> t[2*ms];
int ans[ms];

void build() {
  for(int i = n - 1; i > 0; --i) t[i] = min(t[i<<1], t[i<<1|1]);
}

int query(int l, int r) {
  pair<int, int> res = {inf, inf};
  for(l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
    if(l&1) res = min(res, t[l++]);
    if(r&1) res = min(res, t[--r]);
  }
  return -res.second;
}

main() {
  #ifdef ONLINE_JUDGE
  freopen("g.in", "r", stdin);
  #endif
  cin.tie(0); ios::sync_with_stdio(0);
  while(cin >> n) {
    int h, b, e;
    cin >> h >> b >> e;
    memset(ans, 0, sizeof ans);
    for(int i = 0; i < n; i++) {
      cin >> t[i+n].first;
      t[i+n].second = -(i+1);
    }
    build();
    for(int i = 0; i < n; i++) {
      ans[query(max(0, i-h+1), i)]++;
    }
    for(int i = b; i <= e; i++) {
      cout << ans[i];
      if(i < e) cout << (char) 9;
      else cout << '\n';
    }
  }
}
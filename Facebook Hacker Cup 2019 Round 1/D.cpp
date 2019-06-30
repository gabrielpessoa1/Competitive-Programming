#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 8e5+5;
const int inf = 0x3f3f3f3f3f3f3f3fll;

int x[ms], y[ms];
pair<int, int> xy[ms];
pair<int, int> yx[ms];

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int t;
  cin >> t;
  for(int T = 1; T <= t; T++) {
    cout << "Case #" << T << ": ";
    int n, h, v;
    cin >> n >> h >> v;
    int ax, bx, cx, dx, ay, by, cy, dy;
    cin >> x[0] >> x[1] >> ax >> bx >> cx >> dx;
    cin >> y[0] >> y[1] >> ay >> by >> cy >> dy;
    if(h + v < n) {
      cout << -1 << '\n';
      continue;
    }
    for(int i = 2; i < n; i++) {
      x[i] = (ax * x[i-2] + bx * x[i-1] + cx) % dx + 1;
      y[i] = (ay * y[i-2] + by * y[i-1] + cy) % dy + 1;
    }
    for(int i = 0; i < n; i++) {
      xy[i+1] = {x[i], y[i]};
      yx[i+1] = {y[i], x[i]};
    }
    sort(xy, xy+n+1); sort(yx, yx+n+1);
    int loX = 0, loY = 0;
    int needX = max(0ll, n-v), needY = max(0ll, n-h);
    loX = xy[needX].first;
    loY = yx[needY].first;
    int ans = inf;
    for(int i = n; i >= 0; i--) {
      int curX = max(loX, xy[i].first);
      ans = min(ans, curX + loY);
      loY = max(loY, xy[i].second);
    }
    cout << ans << '\n';
  }
}
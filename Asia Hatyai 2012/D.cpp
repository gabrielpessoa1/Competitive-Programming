#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;

const int ms = 250005;

int k = 14000;
int bit[ms];
vector<ii> pts;
int x[ms], y[ms];
vector<int> pts1, pts2;
pair<int, int> r[ms];
int ans[ms];
pair<ii, int> sl[ms];

void update(int idx, int v) {
  while(idx <= k) {
    bit[idx] += v;
    idx += idx & -idx;
  }
}

int query(int idx) {
  int ans = 0;
  while(idx > 0) {
    ans += bit[idx];
    idx -= idx & -idx;
  }
  return ans;
}

int calcRoot(int x) {
  int lo = 1, hi = k;
  while(lo < hi) {
    int mi = (lo + hi) / 2;
    if(mi * mi < x) lo = mi + 1;
    else hi = mi; 
  }
  return lo;
}

main () {
  int n;
  int T = 0;
  while(scanf("%lld", &n), n) {
     ++T;
     printf("Case %lld:\n", T);
     pts.resize(n);
     pts1.resize(n); pts2.resize(n);
     for(int i = 0; i < n; i++) {
      scanf("%lld%lld", &x[i], &y[i]);
     }
     int ax, ay, bx, by, q;
     scanf("%lld%lld%lld%lld%lld", &ax, &ay, &bx, &by, &q);
     for(int i = 0; i < n; i++) {
      pts[i] = {(x[i] - ax) * (x[i] - ax) + (y[i] - ay) * (y[i] - ay), (x[i] - bx) * (x[i] - bx) + (y[i] - by) * (y[i] - by)};
      pts[i].first = calcRoot(pts[i].first); pts[i].second = calcRoot(pts[i].second);
      pts1[i] = pts[i].first;
      pts2[i] = pts[i].second;
      sl[i] = {pts[i], -1};
     }
     sort(pts1.begin(), pts1.end());
     sort(pts2.begin(), pts2.end());
     for(int i = 0; i < q; i++) {
      scanf("%lld%lld", &r[i].first, &r[i].second);
      sl[i+n] = {r[i], i};
     }
     memset(bit, 0, sizeof bit);
     sort(sl, sl + n + q);
     for(int i = 0; i < n+q; i++) {
      if(sl[i].second == -1) {
        update(sl[i].first.second, 1);
      } else {
        int q1 = upper_bound(pts1.begin(), pts1.end(), sl[i].first.first) - pts1.begin();
        int q2 = upper_bound(pts2.begin(), pts2.end(), sl[i].first.second) - pts2.begin();
        int qinter = query(sl[i].first.second);
        ans[sl[i].second] = max(0ll, n - (q1 + q2 - qinter) - qinter);
      }
     }
     for(int i = 0; i < q; i++) {
      printf("%lld\n", ans[i]);
     }
  }
}
#include <bits/stdc++.h>
using namespace std;

const int ms = 2e5+5;
const int n = 360*100;

pair<pair<int, int>, int> sl[ms];
int arr[ms], seg[ms], lazy[ms];

void update(int L, int R, int V, int idx = 0, int l = 0, int r = n-1) {
  int mid = (l+r)/2;
  if(lazy[idx]) {
    seg[idx] += lazy[idx];
    if(l < r) {
      lazy[2*idx+1] += lazy[idx];
      lazy[2*idx+2] += lazy[idx];
    }
    lazy[idx] = 0;
  }
  if(l > R || r < L) return;
  if(L <= l && r <= R) {
    seg[idx] += V;
    if(l < r) {
      lazy[2*idx+1] += V;
      lazy[2*idx+2] += V;
    }
    return;
  }
  update(L, R, V, 2*idx+1, l, mid); update(L, R, V, 2*idx+2, mid+1, r);
  seg[idx] = max(seg[2*idx+1], seg[2*idx+2]);
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int m, d, a;
  double alpha;
  cin >> m >> d >> alpha;
  a = round(alpha * 100);
  for(int i = 0; i < m; i++) {
    int r;
    double w;
    cin >> r >> w;
    sl[i] = {{r, -1}, round(w*100)};
    sl[i+m] = {{r+d, 1}, round(w*100)};
  }
  sort(sl, sl+m+m);
  int ans = 0;
  for(int i = 0; i < m + m; i++) {
    int buff = -sl[i].first.second;;
    int start = sl[i].second;
    if(start + a < n) {
      update(start, start + a, buff);
    } else {
      update(start, n - 1, buff);
      update(0, start + a - n, buff);
    }
    ans = max(ans, seg[0]);
  }
  cout << ans << '\n';
}
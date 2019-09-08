#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 1e5+5;
const int inf = 0x3f3f3f3f3f3f3f3f;

int h[ms], seg[4*ms], lo[4*ms], sz[4*ms], lazy[4*ms], n;

void build(int idx = 0, int l = 0, int r = n-1) {
  int mid = (l+r)/2;
  lazy[idx] = 0;
  sz[idx] = r-l+1;
  if(l == r) {
    seg[idx] = h[l];
    lo[idx] = h[l];
    return;
  }
  build(2*idx+1, l, mid); build(2*idx+2, mid+1, r);
  seg[idx] = seg[2*idx+1] + seg[2*idx+2];
  lo[idx] = min(lo[2*idx+1], lo[2*idx+2]);
}

void apply(int idx, int l, int r) {
  int mid = (l+r)/2;
  if(lazy[idx]) {
    if(l < r) {
      lazy[2*idx+1] += lazy[idx];
      lazy[2*idx+2] += lazy[idx];
    }
    if(lo[idx] > lazy[idx]) {
      lo[idx] -= lazy[idx];
      seg[idx] -= lazy[idx] * sz[idx];
    } else if(l == r) {
      lo[idx] = inf;
      seg[idx] = 0;
      sz[idx] = 0;
    } else {
      apply(2*idx+1, l, mid); apply(2*idx+2, mid+1, r);
      seg[idx] = seg[2*idx+1] + seg[2*idx+2];
      lo[idx] = min(lo[2*idx+1], lo[2*idx+2]);
      sz[idx] = sz[2*idx+1] + sz[2*idx+2];
    }
  }
  lazy[idx] = 0;
}

int query(int L, int R, int idx = 0, int l = 0, int r = n-1) {
  int mid = (l+r)/2;
  apply(idx, l, r);
  if(l > R || r < L) return 0;
  if(L <= l && r <= R) return seg[idx];
  return query(L, R, 2*idx+1, l, mid) + query(L, R, 2*idx+2, mid+1, r);
}

void update(int L, int R, int V, int idx = 0, int l = 0, int r = n-1) {
  int mid = (l+r)/2;
  apply(idx, l, r);
  if(l > R || r < L) return;
  if(L <= l && r <= R) {
    lazy[idx] = V;
    apply(idx, l, r);
    return;
  }
  update(L, R, V, 2*idx+1, l, mid); update(L, R, V, 2*idx+2, mid+1, r);
  seg[idx] = seg[2*idx+1] + seg[2*idx+2];
  lo[idx] = min(lo[2*idx+1], lo[2*idx+2]);
  sz[idx] = sz[2*idx+1] + sz[2*idx+2];
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int q;
  cin >> n >> q;
  for(int i = 0; i < n; i++) {
    cin >> h[i];
  }
  build();
  for(int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if(t == 1) {
      int a, b;
      cin >> a >> b;
      a--; b--;
      if(a <= b) cout << query(a, b) << '\n';
      else cout << query(a, n-1) + query(0, b) << '\n';
    } else {
      int a, b, s;
      cin >> a >> b >> s;
      a--; b--;
      if(a <= b) update(a, b, s);
      else {
        update(a, n-1, s);
        update(0, b, s);
      }
    }
  }
}
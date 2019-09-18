#include <bits/stdc++.h>
using namespace std;

#define int long long


const int ms = 4e5+5;
const int N = 1e5+1;
const int inf = 0x3f3f3f3f;

typedef pair<int, int> ii;
typedef pair<ii, ii> i4;

int X1, Y1, X2, Y2;
int x1[ms], yy1[ms], x2[ms], yy2[ms];
i4 eve[ms];

ii seg[ms];
int lazy[ms];

ii merge(ii a, ii b) {
  if(a.first == b.first) {
    return {a.first, a.second + b.second};
  } else {
    return min(a, b);
  }
}

void build(int idx = 0, int l = 0, int r = N-1) {
  int mid = (l+r)/2;
  lazy[idx] = 0;
  if(l == r) {
    if(l >= Y1 && r < Y2) seg[idx] = {0, 1};
    else seg[idx] = {inf, 0};
    return;
  }
  build(2*idx+1, l, mid); build(2*idx+2, mid+1, r);
  seg[idx] = merge(seg[2*idx+1], seg[2*idx+2]);
}

void apply(int idx, int l, int r) {
  int mid = (l+r)/2;
  if(lazy[idx]) {
    if(l < r) {
      lazy[2*idx+1] += lazy[idx];
      lazy[2*idx+2] += lazy[idx];
    }
    seg[idx].first += lazy[idx];
  }
  lazy[idx] = 0;
}

void update(int L, int R, int V, int idx = 0, int l = 0, int r = N-1) {
  int mid = (l+r)/2;
  apply(idx, l, r);
  if(l > R || r < L) return;
  if(L <= l && r <= R) {
    lazy[idx] = V;
    apply(idx, l, r);
    return;
  }
  update(L, R, V, 2*idx+1, l, mid); update(L, R, V, 2*idx+2, mid+1, r);
  seg[idx] = merge(seg[2*idx+1], seg[2*idx+2]);
}

int n, p;

int can(int r) {
  for(int i = 0; i < n; i++) {
    eve[i] = {{max(X1, min(x1[i], x2[i]) - r), 1}, {max(Y1, min(yy1[i], yy2[i])-r), min(Y2, max(yy1[i], yy2[i])+r)}};
    eve[i+n] = {{min(X2, max(x1[i], x2[i]) + r), -1}, {max(Y1, min(yy1[i], yy2[i])-r), min(Y2, max(yy1[i], yy2[i])+r)}};
  }
  eve[n+n] = {{X1, 0}, {Y1, Y2}};
  eve[n+n+1] = {{X2, 0}, {Y1, Y2}};
  sort(eve, eve+n+n+2);
  build();
  int ans = (X2-X1)*(Y2-Y1);
  for(int i = 1; i < n+n+2; i++) {
    if(seg[0].first == 0) {
      ans -= (eve[i].first.first - eve[i-1].first.first) * seg[0].second;
    }
    update(eve[i].second.first, eve[i].second.second-1, eve[i].first.second);
  }
  return ans * 100 >= p * (X2-X1)*(Y2-Y1);
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> x1[i] >> yy1[i] >> x2[i] >> yy2[i];
  }
  cin >> p >> X1 >> Y1 >> X2 >> Y2;
  int lo = 1, hi = 2e5+5;
  while(lo < hi) {
    int mi = (lo+hi)/2;
    if(can(mi)) hi = mi;
    else lo = mi+1;
  }
  cout << lo << '\n';
}
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 100100;
const int mod = 1e9 + 7;

int n, q;
int tree[4 * N][2], lazy[4 * N][2];

int fexp(int base, int e) {
  int ans = 1;
  if (e == -1) {
    e = mod - 2;
  }
  while (e > 0) {
    if (e & 1) {
      ans = ans * base % mod;
    }
    e >>= 1;
    base = base * base % mod;
  }
  return ans;
}

void put(int v, int v2, int x) {
  lazy[x][0] = (lazy[x][0] + 2*v*lazy[x][1] + v2) % mod;
  lazy[x][1] = (lazy[x][1] + v) % mod;
}

void prop(int x, int l, int r) {
  if (lazy[x][0] == 0 && lazy[x][1] == 0) {
    return;
  }
  tree[x][0] = (tree[x][0] + 2 * lazy[x][1] * tree[x][1] % mod + (r - l + 1) * lazy[x][0] % mod) % mod;
  tree[x][1] = (tree[x][1] + (r - l + 1) * lazy[x][1] % mod) % mod;
  if (l != r) {
    put(lazy[x][1], lazy[x][0], x+x);
    put(lazy[x][1], lazy[x][0], x+x+1);
  }
  lazy[x][0] = 0;
  lazy[x][1] = 0;
}

void update(int x, int l, int r, int a, int b, int v, int v2) {
  prop(x, l, r);
  if (l > b || r < a) {
    return;
  }
  if (a <= l && r <= b) {
    put(v, v2, x);
    prop(x, l, r);
    return;
  }
  int mid = (l + r) >> 1;
  update(x + x, l, mid, a, b, v, v2);
  update(x + x + 1, mid + 1, r, a, b, v, v2);
  tree[x][0] = (tree[x + x][0] + tree[x + x + 1][0]) % mod;
  tree[x][1] = (tree[x + x][1] + tree[x + x + 1][1]) % mod;
}

int get(int x, int l, int r, int a, int b) {
  prop(x, l, r);
  if (l > b || r < a) {
    return 0;
  }
  if (a <= l && r <= b) {
    return tree[x][0];
  }
  int mid = (l + r) >> 1;
  return get(x + x, l, mid, a, b) + get(x + x + 1, mid + 1, r, a, b);
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  cin >> n >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      cin >> x >> y;
      int v = fexp(y - x + 1, -1);
      update(1, 1, n, x, y, v, v);
    } else {
      cout << get(1, 1, n, 1, n) << endl;
    }
  }
}
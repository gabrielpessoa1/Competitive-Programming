#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 1e5+5;

int bit[ms], n = 1e5;
pair<int, int> a[ms];

void update(int idx) {
  while(idx <= n) {
    bit[idx]++;
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

int solve(int n) {
  memset(bit, 0, sizeof bit);
  map<int, int> dic;
  for(int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    dic[a[i].second] = 0;
  }
  int idx = 0;
  for(auto &p : dic) {
    p.second = ++idx;
  }
  sort(a, a+n);
  int ans = 0;
  for(int i = n-1; i >= 0; i--) {
    ans += query(dic[a[i].second]);
    update(dic[a[i].second]);
  }
  return ans;
}
main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int x, y;
  cin >> x >> y;
  int h, v;
  cin >> h >> v;
  int hor = solve(h);
  int ver = solve(v);
  cout << (h+1)*(v+1) + hor + ver << '\n';
}
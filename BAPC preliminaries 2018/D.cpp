// Benelux Algorithm Programming Contest preliminaries 2018
// D - Daily Division
// https://open.kattis.com/problems/dailydivision

#include <bits/stdc++.h>

#define int long long

using namespace std;

const int ms = 1e5+5;
const int inf = 0x3f3f3f3f3f3f3f3f;

int bit[ms], arr[ms], n, q, sum;

void update(int idx, int v) {
  v -= arr[idx];
  arr[idx] += v;
  sum += v;
  while(idx <= n) {
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

pair<int, int> calc(int i) {
  if(i < 1 || i > n) return {inf, i};
  int l = query(i-1);
  int r = sum - l - arr[i];
  int mid = arr[i];
  if(r < l) swap(l, r);
  l += arr[i] & 1;
  return {abs(r-l), i};
}

main() {
	cin.tie(0); ios::sync_with_stdio(0);
  cin >> n >> q;
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    update(i, x);
  }
  while(q--) {
    int i, x;
    cin >> i >> x;
    update(i+1, x);
    int lo = 1, hi = n;
    while(lo < hi) {
      int mi = (lo+hi)/2;
      if(query(mi) <= sum/2) lo = mi + 1;
      else hi = mi;
    }
    pair<int, int> ans = {inf, 0};
    for(int i = -1; i <= 1; i++) ans = min(ans, calc(lo+i));
    cout << ans.second - 1 << endl;
  }
}

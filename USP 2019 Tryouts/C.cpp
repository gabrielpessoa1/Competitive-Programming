#include <bits/stdc++.h>
using namespace std;

const int ms = 1e5+5;
const int inf = 0x3f3f3f3f;

map<int, int> w;

set<pair<int, int>> s;

int solve(int hi) {
  auto k1 = *s.begin();
  int ans = 1;
  int totalW = k1.first;
  s.erase(k1);
  if(k1.first != hi) {
    while(totalW <= hi) {
      auto k2 = s.lower_bound({totalW, -1});
      ans++;
      if(k2->first + totalW > hi) {
        totalW += hi;
      } else {
        totalW += k2->first;
      }
    }
  }
  while(1) {
    auto k = s.lower_bound({totalW, -1});
    if(k == s.end()) {
      break;
    }
    ans++;
    totalW += k->first;
  }
  s.insert(k1);
  return ans;
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    w[i] = x;
    s.insert({x, i});
  }
  for(int i = 0; i < q; i++) {
    string str;
    cin >> str;
    if(str == "+") {
      int x, y;
      cin >> x >> y;
      w[y] = x;
      s.insert({x, y});
    } else if(str == "-") {
      int x;
      cin >> x;
      s.erase({w[x], x});
    } else {
      int x;
      cin >> x;
      cout << solve(w[x]) << '\n';
    }
  }
}
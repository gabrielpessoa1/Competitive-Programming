#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 1e5+5;

typedef pair<int, int> ii;

set<int> s;
ii a[ms], d[ms], h[ms]; 

main() {
  int n, k;
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> a[i].first >> d[i].first >> h[i].first;
    a[i].second = d[i].second = h[i].second = i;
  }
  sort(a, a+n); sort(d, d+n); sort(h, h+n);
  for(int i = 0; i < k; i++) {
    s.insert(a[n-1-i].second);
    s.insert(d[n-1-i].second);
    s.insert(h[n-1-i].second);
  }
  cout << s.size() << '\n';
}
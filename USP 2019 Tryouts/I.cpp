#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 1e5+5;

pair<int, int> a[ms];
int ans[ms];

main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i].second >> a[i].first;
  }
  sort(a, a+n);
  ans[n-1] = a[n-1].second - a[n-1].first;
  for(int i = n - 2; i >= 0; i--) {
    ans[i] = a[i].second + max(-a[i].first, ans[i+1]);
  }
  cout << ans[0] << '\n';
}
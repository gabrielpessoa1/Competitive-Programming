#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 5e5+5;

int a[ms];

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a +n);
  int ans = 1;
  for(int i = 0; i < n; i++) {
    if(a[i] <= ans) {
      ans += a[i];
    } else {
      break;
    }
  }
  cout << ans << '\n';
}
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 1e5+5;
int a[ms];
int n, t, c;

int can (int x) {
  int k = 0, l = 0;
  for (int i = 1; i <= n; i++) {
      int time = (a[i]-a[l]);
      if(time > t * x) return 0;
      if(i < n && a[i+1] - a[l] > t * x) {
          l = i;
          k++;
          if(k == c) return 0;
      }
  }
  return 1;
}

main () {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> c >> t;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i-1];
  }
  int lo = 0, hi = 2e9;
  while (lo < hi) {
    int m = (lo+hi)>>1;
    if(can(m)) hi = m;
    else lo = m+1;
  }
  cout << lo << endl;
}
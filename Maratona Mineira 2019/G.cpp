#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int k, n;
  cin >> k >> n;
  k = (1ll << k);
  n *= 2;
  n %= 9*k;
  ii x, y;
  if(n <= 6*k) {
    int cnt = n/6;
    n %= 6;
    x = {cnt*2, k*2};
    y = {cnt*4, k*4};
    if(n <= 4) {
      y.first += n;
    } else {
      y.first += 4;
      x.first += n-4;
    }
  } else {
    n -= 6*k;
    int cnt = n/3;
    n %= 3;
    x = {k*2 - cnt*2, k*2};
    y = {k - cnt, k};
    x.first -= n;
  }
  while(x.first % 2 == 0 && x.second > 1) {
    x.first /= 2;
    x.second /= 2;
  }
  while(y.first % 2 == 0 && y.second > 1) {
    y.first /= 2;
    y.second /= 2;
  }
  cout << x.first;
  if(x.second != 1) cout << '/' << x.second;
  cout << ' ' << y.first;
  if(y.second != 1) cout << '/' << y.second;
  cout << '\n';
}
#include <bits/stdc++.h>
using namespace std;

main() {
  int n;
  string old, young;
  int lo = 0x3f3f3f3f, hi = -1;
  cin >> n;
  while(n--) {
    string s;
    int d, m, y, x;
    cin >> s >> d >> m >> y;
    x = d + m * 100 + y * 10000;
    if(x < lo) {
      lo = x;
      old = s;
    }
    if(x > hi) {
      hi = x;
      young = s;
    }
  }
  cout << young << '\n' << old << '\n';
}
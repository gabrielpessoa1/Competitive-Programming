// Seletiva UnB 2019
// L - Almoço em Manhattan
// https://codeforces.com/group/btcK4I5D5f/contest/244688/problem/L

#include <bits/stdc++.h>
using namespace std;

const int ms = 1e5+5;

int arr[ms];

main() {
  int n, xc, yc;
  cin >> n >> xc >> yc;
  int ansP = 0, ans = 0x3f3f3f3f;
  for(int i = 1; i <= n; i++) {
    int x, y, p;
    cin >> x >> y >> p;
    int c = 2*(abs(x-xc) + abs(y-yc)) + p;
    if(c < ans) {
      ans = c;
      ansP = i;
    }
  }
  cout << ans << ' ' << ansP << endl;
}
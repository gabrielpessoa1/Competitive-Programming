// La Salle-Pui Ching Programming Challenge 培正喇沙編程挑戰賽 2018
// H - Handicap
// https://codeforces.com/gym/101807/problem/H

#include <bits/stdc++.h>
using namespace std;

const int ms = 1e5+5;

int d[ms];

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n;
  cin >> n;
  d[0] = 0;
  for(int i = 1; i <= n; i++) {
   cin >> d[i];
  }
  d[n+1] = 0x3f3f3f3f;
  int q;
  cin >> q;
  for(int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    int dif = y - x;
    int k = lower_bound(d, d + n + 2, dif) - d;
    if(k == 0) {
      cout << 0 << '\n';
    } else if(y - d[k] < 1) {
      cout << k - 1 << '\n';
    } else if(abs(dif - d[k-1]) <= abs(dif - d[k])) {
      cout << k - 1 << '\n';
    } else {
      cout << k << '\n';
    }
  }
}
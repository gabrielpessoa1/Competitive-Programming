#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const ld pi = acos(-1.0);

ld f(ld O, ld a, ld b) {
  a = - a * a / (2 * O * O);
  b = - b * b / (2 * O * O);
  return exp(a) - exp(b);
}

int main () {
  cout << fixed << setprecision(10);
  vector<ld> r(6);
  for (int i = 0; i < 6; i++) {
    cin >> r[i];
  }
  int on = 0;
  ld O, ans = 0;
  cin >> O;
  ans += f(O, 0, r[0]) * 50;
  ans += f(O, r[0], r[1]) * 25;
  ans += f(O, r[1], r[2]) * 210.0 / 20.0;
  ans += f(O, r[2], r[3]) * 210 * 3 / 20.0;
  ans += f(O, r[3], r[4]) * 210.0 / 20.0;
  ans += f(O, r[4], r[5]) * 210.0 * 2 / 20.0;
  cout << ans << endl;
}
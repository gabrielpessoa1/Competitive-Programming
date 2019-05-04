// North America Qualifier 2018
// H - Longest Life 
// https://open.kattis.com/problems/longestlife

#include <bits/stdc++.h>
using namespace std;

const int ms = 2e5+2;

struct line {
    double a, b;
    double eval(double x) { return b * x + a; }
    double intersectX(line l) { return 1.0 * (a - l.a) / (l.b - b); }
};

deque<line> dq;

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  long long n;
  int p, c;
  cin >> n >> p >> c;
  double ans = n;
  dq.push_front({1.0 * n, -1});
  double last = 1.0;
  for(int i = 0; i < p; i++) {
    long long t; int x, y;
    cin >> t >> x >> y;
    double prop = 1.0*y/x;
    if(prop >= last) {
      continue;
    }
    last = prop;
    while(dq.size() >= 2 && dq.back().eval(t) <= dq[dq.size() - 2].eval(t)) dq.pop_back();
    double newAns = dq.back().eval(t) - c;
    ans = max(ans, t + newAns/prop);
    line cur = {newAns + prop*t, -prop};
    while(dq.size() >= 2 && cur.intersectX(dq[0]) <= dq[0].intersectX(dq[1])) dq.pop_front();
    dq.push_front(cur);
  }
  cout << fixed << setprecision(10) << ans << '\n';
}
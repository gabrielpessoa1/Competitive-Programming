#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;

string s;
int idx = 0;

int readInt() {
  int cur = 0;
  while(s[idx] >= '0' && s[idx] <= '9') {
    cur = cur * 10 + s[idx++] - '0';
  }
  return cur;
}

ii reduce(ii cur) {
  if(cur.second < 0) {
    cur.first = -cur.first;
    cur.second = -cur.second;
  }
  if(cur.first == 0) cur.second = 1;
  else {
    int gc = __gcd(abs(cur.first), cur.second);
    cur.first /= gc;
    cur.second /= gc;
  }
  return cur;
}

ii read() {
  ii get;
  get.first = readInt();
  idx++;
  get.second = readInt();
  return reduce(get);
}

ii op(ii a, ii b, int lastOp) {
  b.first *= lastOp;
  ii ans;
  int lcm = a.second / __gcd(a.second, b.second) * b.second;
  ans.first = lcm / a.second * a.first + lcm / b.second * b.first; 
  ans.second = lcm;
  return reduce(ans);
}

ii solve() {
  ii cur = {0, 1};
  int lastOp = 1;
  while(idx < s.size() && s[idx] != ')') {
    if(s[idx] == '(') {
      idx++;
      cur = op(cur, solve(), lastOp);
      idx++;
    } else if(s[idx] == '+') {
      idx++;
      lastOp = 1;
    } else if(s[idx] == '-') {
      idx++;
      lastOp = -1;
    } else {
      cur = op(cur, read(), lastOp);
    }
  }
  return cur;
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  while(cin >> s) {
    idx = 0;
    ii ans = solve();
    cout << ans.first << '/' << ans.second << endl;
  }
}
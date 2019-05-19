// Seletiva UnB 2019
// F - Espetinho do Barbosinha
// https://codeforces.com/group/btcK4I5D5f/contest/244688/problem/F

#include <bits/stdc++.h>
using namespace std;

const int ms = 2e5+5;

pair<int, int> events[ms];

int get(string &s, int p) {
  return (s[p]-'0')*10 + s[p+1] - '0';
}

int convert(string &s) {
  return get(s, 0)*60*60 + get(s, 3)*60 + get(s, 6);
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    string a, b;
    cin >> a >> b;
    events[i*2] = {convert(a), -1};
    events[i*2+1] = {convert(b), 1};
  }
  sort(events, events + n + n);
  int cur = 0, ans = 0;
  for(int i = 0; i < n+n; i++) {
    cur -= events[i].second;
    ans = max(cur, ans);
  }
  cout << ans << endl;
}
// Seletiva UnB 2019
// A - Radares
// https://codeforces.com/group/btcK4I5D5f/contest/244688/problem/A

#include <bits/stdc++.h>
using namespace std;

const int ms = 2e6+5;

typedef pair<int, int> ii;

int add[ms];
int rem[ms];
ii events[ms];
int z = 0;

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n, q, l;
  cin >> n >> q >> l;
  for(int i = 0; i < q; i++) {
    int a, b, m;
    cin >> a >> b >> m;
    if(m > l) {
      add[a]++;
      rem[b+1]++;
    }
  }
  int lastAdd = 0;
  int cur = 0;
  ii ans = {1, -1};
  for(int i = 1; i <= n+1; i++) {
    ans = max(ans, ii(cur, (i - lastAdd)));
    if(add[i] > rem[i]) {
      lastAdd = i;
    }
    cur += add[i] - rem[i];
  }
  cout << ans.second << endl;
}
// Seletiva UnB 2019
// G - Propagação de Worms
// https://codeforces.com/group/btcK4I5D5f/contest/244688/problem/G

#include <bits/stdc++.h>
using namespace std;

const int ms = 18;

map<string, int> dic;
string iDic[ms];
int mark[ms];

vector<int> g[ms];

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> iDic[i];
    dic[iDic[i]] = i;
  }
  for(int i = 0; i < m; i++) {
    string a, b;
    cin >> a >> b;
    int x = dic[a], y = dic[b];
    g[x].push_back(y); g[y].push_back(x);
  }
  int bestMask = 0;
  int ans = 20;

  for(int i = 0; i < (1 << n); i++) {
    memset(mark, 0, sizeof mark);
    int cur = 0;
    int marked = 0;
    for(int j = 0; j < n; j++) {
      if(i & (1 << j)) {
        cur++;
        marked += !mark[j];
        mark[j] = 1;
        for(int k : g[j]) {
          marked += !mark[k];
          mark[k] = 1;
        }
      }
    }
    if(marked == n && cur < ans) {
      ans = cur;
      bestMask = i;
    }
  }
  cout << ans << endl;
  bool first = true;
  for(int i = 0; i < n; i++) {
    if(bestMask & (1 << i)) {
      if(!first) cout << " ";
      first = false;
      cout << iDic[i];
    }
  }
  cout << endl;
}
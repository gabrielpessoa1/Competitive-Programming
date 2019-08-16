#include <bits/stdc++.h>
using namespace std;

const int ms = 1e6+5;

int balance[ms];
int paint[ms];
vector<int> g[ms];
int ans = 0;

void dfs(int u) {
  if(paint[u]) return;
  paint[u] = 1;
  ans++;
  for(int v : g[u]) {
    if(!paint[v]) {
      balance[u]++;
      balance[v]++;
    } else {
      balance[u]--;
      balance[v]--;
    }
    if(balance[v] > 1) dfs(v);
  }
  //cout << u << ' ' << balance[u] << endl;
  for(int i = 0; i < g[u].size(); i++) {
    for(int j = i+1; j < g[u].size(); j++) {
      for(int k : g[g[u][i]]) {
        if(g[u][j] == k) {
          dfs(k);
        }
      }
      vector<int> a = g[g[u][i]];
      vector<int> b = g[g[u][j]];
      if(a.size() == 3 && a == b) {
        dfs(g[u][i]);
      }
    }
  }
  //cout << u << ' ' << balance[u] << endl;
  for(int v : g[u]) {
    if(balance[u] > 1) dfs(v);
  }
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for(int i = 1; i <= n; i++) {
    sort(g[i].begin(), g[i].end());
  }
  dfs(1);
  if(ans == n) {
    cout << 0 << '\n';
  } else {
    cout << 1 << '\n';
    cout << n - ans << '\n';
    bool found1 = false;
    for(int i = 1; i <= n; i++) {
      if(!paint[i]) {
        if(found1) cout << ' ';
        found1 = true;
        cout << i;
      }
    }
    cout << '\n';
    cout << ans << '\n';
    bool found2 = false;
    for(int i = 1; i <= n; i++) {
      if(paint[i]) {
        if(found2) cout << ' ';
        found2 = true;
        cout << i;
      }
    }
    cout << '\n';
  }
}
#include <bits/stdc++.h>
using namespace std;

const int ms = 5e5+5;

int p[ms];
int par[ms][31];
int ans[ms][31];
int ds[ms];
int lvl[ms];
vector<int> g[ms];
pair<int, pair<int, int>> query[ms];

int find(int a) {
  if(ds[a] != a) ds[a] = find(ds[a]);
  return ds[a];
}

void unite(int a, int b) {
  ds[b] = find(a);
}

void dfs(int v, int l = 0) {
  if(par[v][0] == -1) par[v][0] = v;
  lvl[v] = l;
  //cout << "lvl de " << v << " = " << l << endl;
  ans[v][0] = min(p[v], p[par[v][0]]);
  for(int k = 1; k <= 30; k++) {
    par[v][k] = par[par[v][k-1]][k-1];
    ans[v][k] = min(ans[v][k-1], ans[par[v][k-1]][k-1]);
  }
  for(int u : g[v]) {
    if(u != par[v][0]) dfs(u, l+1);
  }
}

int solve(int a, int b) {
  //cout << a << ' ' << b << endl;
  //cout << lvl[a] << ' ' << lvl[b] << endl;
  int res = p[a];
  for(int i = 30; i >= 0; i--) {
    if(lvl[a] - (1 << i) >= lvl[b]) {
      res = min(res, ans[a][i]);
      a = par[a][i];
    }
  }
  return res;
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    cin >> p[i];
    ds[i] = i;
  }
  memset(par, -1, sizeof par);
  for(int i = 0; i < m; i++) {
    string s;
    cin >> s;
    if(s == "+") {
      int x, y;
      cin >> x >> y;
      query[i] = {0, {x, y}};
      par[y][0] = x;
      g[x].push_back(y);
    } else {
      int x;
      cin >> x;
      query[i] = {1, {x, 0}};
    }
  }
  for(int i = 1; i <= n; i++) {
    if(par[i][0] == -1) dfs(i);
  }
  for(int i = 0; i < m; i++) {
    if(query[i].first == 0) {
      unite(query[i].second.first, query[i].second.second);
    } else {
      cout << solve(query[i].second.first, find(query[i].second.first)) << '\n';
    }
  }
}
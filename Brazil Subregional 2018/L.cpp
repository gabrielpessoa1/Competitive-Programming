#include <bits/stdc++.h>
using namespace std;

const int ms = 1e5+5;

int par[ms][30], lvl[ms];
vector<int> g[ms];

void dfs(int v, int p, int l = 0) { // chamar como dfs(root, root)
  lvl[v] = l;
  par[v][0] = p;
  for(int k = 1; k <= 20; k++) {
    par[v][k] = par[par[v][k-1]][k-1];
  }
  for(int u : g[v]) {
    if(u != p) dfs(u, v, l + 1);
  }
}

int lca(int a, int b) {
  if(lvl[b] > lvl[a]) swap(a, b);
  for(int i = 20; i >= 0; i--) {
    if(lvl[a] - (1 << i) >= lvl[b]) a = par[a][i];
  }
  if(a == b) return a;
  for(int i = 20; i >= 0; i--) {
    if(par[a][i] != par[b][i]) a = par[a][i], b = par[b][i];
  }
  return par[a][0];
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(5, 5);
  while(q--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int u = lca(a, b);
    int v = lca(c, d);
    if(u == v) {
      int ac = lca(a, c), ad = lca(a, d), bc = lca(b, c), bd = lca(b, d);
      cout << lvl[ac] - lvl[v] + lvl[ad] - lvl[v] + lvl[bc] - lvl[v] + lvl[bd] - lvl[v] + 1 << '\n';
    } else {
      if(lvl[u] > lvl[v]) {
        swap(u, v);
        swap(a, c);
        swap(b, d);
      }
      int ac = lca(a, c), ad = lca(a, d), bc = lca(b, c), bd = lca(b, d); 
      int ansA = lvl[ac] - lvl[v] + lvl[ad] - lvl[v] + 1;
      int ansB = lvl[bc] - lvl[v] + lvl[bd] - lvl[v] + 1;
      cout << max(max(ansA, ansB), 0) << '\n';
    }
  }
}
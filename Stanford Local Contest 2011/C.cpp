#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int ms = 1e5+5;
 
int ds[ms];
 
int dsFind(int a) {
  if(a != ds[a]) ds[a] = dsFind(ds[a]);
  return ds[a];
}
 
void dsUnion(int a, int b) {
  a = dsFind(a); b = dsFind(b);
  ds[a] = b;
}
 
int par[ms][20], lvl[ms], acc[ms][20];
vector<pair<int, int>> g[ms];
pair<int, pair<int, int>> ed[ms];
 
void dfs(int v, int p, int w = 0, int l = 0) {
  lvl[v] = l;
  par[v][0] = p;
  acc[v][0] = w;
  for(int k = 1; k < 20; k++) {
    par[v][k] = par[par[v][k-1]][k-1];
    acc[v][k] = acc[v][k-1] + acc[par[v][k-1]][k-1];
  }
  for(auto e : g[v]) {
    int u = e.first;
    if(u != p) dfs(u, v, e.second, l+1);
  }
}
 
int lca(int a, int b) {
  if(lvl[b] > lvl[a]) swap(a, b);
  int ans = 0;
  for(int i = 19; i >= 0; i--) {
    if(lvl[a] - (1 << i) >= lvl[b]) {
      ans += acc[a][i];
      a = par[a][i];
    }
  }
  if(a == b) return ans;
  for(int i = 19; i >= 0; i--) {
    if(par[a][i] != par[b][i]) {
      ans += acc[a][i] + acc[b][i];
      a = par[a][i];
      b = par[b][i];
    }
  }
  return ans + acc[a][0] + acc[b][0];
}
 
main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n;
  while(cin >> n, n) {
    for(int i = 0; i < n; i++) {
      cin >> ed[i].second.first >> ed[i].second.second >> ed[i].first;
      ds[i] = i;
      g[i].clear();
    }
    sort(ed, ed+n);
    int a, b, k;
    for(int i = 0; i < n; i++) {
      int u = ed[i].second.first, v = ed[i].second.second, w = ed[i].first;
      if(dsFind(u) != dsFind(v)) {
        dsUnion(u, v);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
      } else {
        a = u; b = v; k = w;
      }
    }
    dfs(0, 0);
    int q;
    cin >> q;
    while(q--) {
      int u, v;
      cin >> u >> v;
      cout << min(lca(u, v), min(lca(u, a) + lca(v, b), lca(u, b) + lca(v, a)) + k) << '\n';
    }
  }
}
// BSUIR Semifinal 2016-2017
// E - Kth subtree
// https://codeforces.com/gym/102134/problem/E

#include <bits/stdc++.h>
using namespace std;

const int ms = 1e5+5;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

typedef pair<int, int> ii;

typedef tree<ii, null_type, less<ii>, rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

ordered_set X;

vector<int> g[ms];
int sz[ms];
int vis[ms];
vector<ii> query[ms];
int qsz[ms];
int ans[ms];

int dfs1(int u) {
  if(vis[u]) return 0;
  vis[u] = 1;
  sz[u] = 1;
  for(int v : g[u]) {
    sz[u] += dfs1(v);
  }
  X.insert({sz[u], u});
  return sz[u];
}

void dfs2(int u) {
  if(vis[u]) return;
  vis[u] = 1;
  for(auto q : query[u]) {
    ans[q.second] = X.find_by_order(q.first-1)->first;
  }
  for(auto v : g[u]) {
    int curU = sz[u];
    int curV = sz[v];
    sz[u] = curU - curV;
    sz[v] = curU;
    
    X.erase({curU, u});
    X.erase({curV, v});
    X.insert({sz[u], u});
    X.insert({sz[v], v});

    dfs2(v);

    X.erase({sz[u], u});
    X.erase({sz[v], v});
    X.insert({curU, u});
    X.insert({curV, v});

    sz[u] = curU;
    sz[v] = curV;
  }
}

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for(int i = 0; i < q; i++) {
    int v, k;
    cin >> v >> k;
    query[v].emplace_back(k, i);
  }
  
  dfs1(1);
  memset(vis, 0, sizeof vis);
  dfs2(1);
  for(int i = 0; i < q; i++) {
    cout << ans[i] << '\n';
  }
}
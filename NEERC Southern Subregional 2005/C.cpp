#include <bits/stdc++.h>
using namespace std;
 
const int ms = 100005;
const int lim = 10000;
 
int x[ms], y[ms], c[ms];
vector<int> g[ms];
 
int idx[ms], low[ms], z, comp[ms], ncomp;
stack<int> st;
 
int dfs(int u) {
  if(~idx[u]) return idx[u] ? idx[u] : z;
  low[u] = idx[u] = z++;
  st.push(u);
  for(int v : g[u]) {
    low[u] = min(low[u], dfs(v));
  }
  if(low[u] == idx[u]) {
    while(st.top() != u) {
      int v = st.top();
      idx[v] = 0;
      low[v] = low[u];
      comp[v] = ncomp;
      st.pop();
    }
    idx[st.top()] = 0;
    st.pop();
    comp[u] = ncomp++;
  }
  return low[u];
}
 
vector<pair<int, int>> compg[ms];
vector<pair<int, int>> compig[ms];
vector<int> topo;
queue<int> q;
int val[ms];
int deg[ms];
 
main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
	  scanf("%d%d%d", &x[i], &y[i], &c[i]);
	  if(c[i] == 0) g[x[i]].push_back(y[i]);
  }
  memset(idx, -1, sizeof idx);
  z = 1; ncomp = 0;
  for(int i = 1; i <= n; i++) dfs(i);
  for(int i = 0; i < m; i++) {
    if(comp[x[i]] == comp[y[i]]) {
      if(c[i] == 0) continue;
      else {
        cout << -1 << endl;
        return 0;
      }
    }
    compg[comp[x[i]]].emplace_back(comp[y[i]], c[i]);
    compig[comp[y[i]]].emplace_back(comp[x[i]], c[i]);
    deg[comp[y[i]]]++;
  }
  for(int i = 0; i < ncomp; i++) {
    if(deg[i] == 0) q.push(i);
  }
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(auto e : compg[u]) {
      if(--deg[e.first] == 0) q.push(e.first);
    }
    topo.push_back(u);
  }
  if(topo.size() != ncomp) {
    cout << -1 << endl;
    return 0;
  }
  for(int i = 0; i < ncomp; i++) {
    int u = topo[i];
    val[u] = lim;
    for(auto e : compig[u]) {
      val[u] = min(val[u], val[e.first] - e.second);
    }
    if(val[u] < -lim) {
      cout << -1 << endl;
      return 0;
    }
  }
  for(int i = ncomp - 1; i >= 0; i--) {
    int u = topo[i];
    if(u == comp[1]) continue;
    val[u] = -lim;
    for(auto e : compg[u]) {
      val[u] = max(val[u], val[e.first] + e.second);
    }
  }
  for(int i = 1; i <= n; i++) {
    cout << val[comp[i]];
    if(i < n) cout << ' ';
    else cout << '\n';
  }
}
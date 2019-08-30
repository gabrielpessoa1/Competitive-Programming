#include <bits/stdc++.h>
using namespace std;

const int ms = 2005;
const int me = 1e5;

int adj[ms], to[me], ant[me], wt[me], z;
int copy_adj[ms], fila[ms], level[ms];
int dist[me], real_wt[me];

void add(int u, int v, int k, int d) {
  to[z] = v;
  ant[z] = adj[u];
  real_wt[z] = k;
  dist[z] = d;
  adj[u] = z++;
  swap(u, v);
  to[z] = v;
  ant[z] = adj[u];
  real_wt[z] = 0;
  dist[z] = d;
  adj[u] = z++;
}

int bfs(int source, int sink, int d) {
  memset(level, -1, sizeof level);
  level[source] = 0;
  int front = 0, size = 0, v;
  fila[size++] = source;
  while(front < size) {
    v = fila[front++];
    for(int i = adj[v]; i != -1; i = ant[i]) {
      if(wt[i] && dist[i] <= d && level[to[i]] == -1) {
        level[to[i]] = level[v] + 1;
        fila[size++] = to[i];
      }
    }
  }
  return level[sink] != -1;
}

int dfs(int v, int sink, int flow, int d) {
  if(v == sink) return flow;
  int f;
  for(int &i = copy_adj[v]; i != -1; i = ant[i]) {
    if(wt[i] && dist[i] <= d && level[to[i]] == level[v] + 1 && 
      (f = dfs(to[i], sink, min(flow, wt[i]), d))) {
      wt[i] -= f;
      wt[i ^ 1] += f;
      return f;
    }
  }
  return 0;
}

int maxflow(int source, int sink, int d) {
  memcpy(wt, real_wt, sizeof wt);
  int ret = 0, flow;
  while(bfs(source, sink, d)) {
    memcpy(copy_adj, adj, sizeof adj);
    while((flow = dfs(source, sink, 1 << 30, d))) {
      ret += flow;
    }
  }
  return ret;
}

main() {
  memset(adj, -1, sizeof adj);
  z = 0;
  int p, r, c;
  cin >> p >> r >> c;
  int src = 2003, snk = 2004;
  int need = 0;
  for(int i = 1; i <= p; i++) {
    int x;
    cin >> x;
    need += x;
    add(i, snk, x, 0);
  }
  for(int i = 1; i <= r; i++) {
    int x;
    cin >> x;
    add(src, i+1001, x, 0);
  }
  for(int i = 1; i <= c; i++) {
    int u, v, t;
    cin >> u >> v >> t;
    add(v+1001, u, 0x3f3f3f3f, t);
  }
  int lo = 1, hi = 1e6+1;
  while(lo < hi) {
    int mi = (lo+hi)/2;
    if(maxflow(src, snk, mi) == need) hi = mi;
    else lo = mi+1;
  }
  if(lo > 1e6) cout << -1 << '\n';
  else cout << lo << '\n';
}
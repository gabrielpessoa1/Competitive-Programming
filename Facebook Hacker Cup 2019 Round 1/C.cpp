#include <bits/stdc++.h>
using namespace std;

const int ms = 1e3;
const int me = 1e5;
const int inf = 0x3f3f3f3f;

int adj[ms], to[me], ant[me], wt[me], z, n;
int copy_adj[ms], fila[ms], level[ms];

void clear() {
  memset(adj, -1, sizeof adj);
  z = 0;
}

void add(int u, int v, int k) {
  to[z] = v;
  ant[z] = adj[u];
  wt[z] = k;
  adj[u] = z++;
  swap(u, v);
  to[z] = v;
  ant[z] = adj[u];
  wt[z] = k;
  adj[u] = z++;
}

int bfs(int source, int sink) {
  memset(level, -1, sizeof level);
  level[source] = 0;
  int front = 0, size = 0, v;
  fila[size++] = source;
  while(front < size) {
  v = fila[front++];
  for(int i = adj[v]; i != -1; i = ant[i]) {
    if(wt[i] && level[to[i]] == -1) {
    level[to[i]] = level[v] + 1;
    fila[size++] = to[i];
    }
  }
  }
  return level[sink] != -1;
}

int dfs(int v, int sink, int flow) {
  if(v == sink) return flow;
  int f;
  for(int &i = copy_adj[v]; i != -1; i = ant[i]) {
  if(wt[i] && level[to[i]] == level[v] + 1 && 
    (f = dfs(to[i], sink, min(flow, wt[i])))) {
    wt[i] -= f;
    wt[i ^ 1] += f;
    return f;
  }
  }
  return 0;
}

int maxflow(int source, int sink) {
  int ret = 0, flow;
  while(bfs(source, sink)) {
  memcpy(copy_adj, adj, sizeof adj);
  while((flow = dfs(source, sink, 1 << 30))) {
    ret += flow;
  }
  }
  return ret;
}

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

iii ladder[ms];
int grid[51][1000005];

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int t;
  cin >> t;
  for(int T = 1; T <= t; T++) {
    cout << "Case #" << T << ": ";
    clear();
    int n, h;
    cin >> n >> h;
    int src = n+1, snk = n+2;
    for(int i = 0; i < n; i++) {
      cin >> ladder[i].first >> ladder[i].second.first >> ladder[i].second.second;
    }
    sort(ladder, ladder+n);
    bool possible = true;
    for(int i = 0; i < n; i++) {
      if(ladder[i].second.first == 0) add(src, i, inf);
      if(ladder[i].second.second == h) add(i, snk, inf);
      if(ladder[i].second.first == 0 && ladder[i].second.second == h) possible = false;
      for(int j = 0; j < h; j++) grid[i][j] = 0;
      for(int j = ladder[i].second.first; j < ladder[i].second.second; j++) grid[i][j] = 1;
    }
    if(!possible) cout << -1 << '\n';
    else {
      for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
          int x = max(ladder[i].second.first, ladder[j].second.first);
          int y = min(ladder[i].second.second, ladder[j].second.second);
          int w = 0;
          for(int k = x; k < y; k++) {
            if(grid[i][k]) {
              grid[i][k] = 0;
              w++;
            }
          }
          if(w > 0) add(i, j, w);
        }
      }
      cout << maxflow(src, snk) << '\n';  
    }
  }
}
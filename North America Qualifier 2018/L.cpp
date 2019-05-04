// North America Qualifier 2018
// L - Superdoku
// https://open.kattis.com/problems/superdoku

#include <bits/stdc++.h>
using namespace std;

const int ms = 305;
const int me = 1e5+5;

int inCol[ms][ms];
int inRow[ms][ms];
int ans[ms][ms];

int adj[ms], to[me], ant[me], wt[me], z, n;
int copy_adj[ms], fila[ms], level[ms];

void clear() {
  memset(adj, -1, sizeof adj);
  z = 0;
}

void add(int u, int v, int k = 1) {
  to[z] = v;
  ant[z] = adj[u];
  wt[z] = k;
  adj[u] = z++;
  swap(u, v);
  to[z] = v;
  ant[z] = adj[u];
  wt[z] = 0;
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

void print() {
  cout << "yes\n";
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cout << ans[i][j];
      if(j == n - 1) cout << "\n";
      else cout << " ";
    }
  }
  exit(0);
}

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int k;
  cin >> n >> k;
  for(int i = 0; i < k; i++) {
    for(int j = 0; j < n; j++) {
      int x;
      cin >> x;
      ans[i][j] = x;
      if(inRow[i][x] || inCol[j][x]) {
        cout << "no\n";
        exit(0);
      }
      inCol[j][x] = 1;
      inRow[i][x] = 1;
    }
  }
  int src = 250, snk = 251;
  for(int i = k; i < n; i++) {
    clear();
    for(int j = 0; j < n; j++) {
      add(src, j);
      add(j+1+n, snk);
      for(int q = 1; q <= n; q++) {
        if(!inCol[j][q]) add(j, q+n);
      }
    }
    if(maxflow(src, snk) != n) {
      cout << "no\n";
      return 0;
    }
    for(int j = 0; j < n; j++) {
      for(int e = adj[j]; ~e; e = ant[e]) {
        int x = to[e] - n;
        if(!wt[e]) {
          inCol[j][x] = 1;
          ans[i][j] = x;
        }
      }
    }
  }
  print();
}
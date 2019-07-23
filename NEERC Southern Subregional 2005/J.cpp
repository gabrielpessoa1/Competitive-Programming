#include <bits/stdc++.h>
using namespace std;
 
const int ms = 1e5;
const int me = 5e5;
 
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
  wt[z] = 0;
  adj[u] = z++;
}
 
int bfs(int source, int sink) {
  memset(level, -1, sizeof level);
  level[source] = 0;;
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
    if(wt[i] && level[to[i]] == level[v] + 1 && (f = dfs(to[i], sink, min(flow, wt[i])))) {
      wt[i] -= f;
      wt[i^1] += f;
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
 
map<int, int> dic;
int iDic[ms];
int used[ms];
int ans[ms];
 
main() {
  clear();
  int n, m;
  cin >> n >> m;
  int src = n+1, snk = n+2;
  int amt = n+3;
  for(int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    if(a > 0 && b <= 0) {
      b = b + a*((a - b)/a);
    }
    if(a < 0 && b > m) {
      b = b + a*((b - m - a - 1)/(-a));
    }
    //cout << a << ' ' << b << endl;
    add(src, i, 1);
    for(int j = 0; j < 300; j++) {
      if(b <= m && b > 0) {
        if(dic.count(b)) add(i, dic[b], 1);
        else {
          dic[b] = amt;
          iDic[amt] = b;
          add(amt, snk, 1);
          add(i, amt, 1);
          amt++;
        }
      } else {
        break;
      }
      if(a == 0) break;
      b += a;
    }
  }
  maxflow(src, snk);
  for(int i = 1; i <= n; i++) {
    for(int e = adj[i]; e != -1; e = ant[e]) {
      if(wt[e] == 0) {
        if(to[e] != src) {
          ans[i] = iDic[to[e]];
          if(ans[i] > 0 && ans[i] <= 300) used[ans[i]] = 1;
        } else {
          ans[i] = -1;
        }
      }
    }
  }
  for(int i = 1; i <= n; i++) {
   if(ans[i] == -1) {
    for(int j = 1; j <= m; j++) {
      if(!used[j]) {
        ans[i] = j;
        used[j] = 1;
        break;
      }
    }
   }
  }
  for(int i = 1; i <= n; i++) {
    cout << ans[i];
    if(i < n) cout << ' ';
    else cout << '\n';
  }
}
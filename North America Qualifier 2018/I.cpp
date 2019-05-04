// North America Qualifier 2018
// I - Monitoring Ski Paths 
// https://open.kattis.com/problems/monitoringskipaths

#include <bits/stdc++.h>
using namespace std;

const int ms = 3e5+2;

typedef pair<int, int> ii;

vector<int> g[ms];
ii rota[ms];
int vis[ms];
int mark[ms];
int routMark[ms];
vector<int> start[ms], finish[ms];
vector<int> topo;

void dfs(int u) {
  if(vis[u]) return;
  vis[u] = 1;
  for(int v:  g[u]) dfs(v);
  topo.push_back(u);
}

void dfsMark(int u) {
  if(mark[u]) return;
  mark[u] = 1;
  for(int v : finish[u]) routMark[v] = 1;
  for(int v : g[u]) dfsMark(v);
}

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n, k, m;
  cin >> n >> k >> m;
  for(int i = 0; i < k; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
  }
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    rota[i] = {u, v};
    start[u].push_back(i);
    finish[v].push_back(i);
  }
  for(int i = 1; i <= n; i++) {
    dfs(i);
  }
  int ans = 0;
  for(int u : topo) {
    bool need = false;
    for(int v : start[u]) {
      if(!routMark[v]) need = true;
    }
    if(need) {
      dfsMark(u);
      ans++;
    }
  }
  cout << ans << '\n';
}
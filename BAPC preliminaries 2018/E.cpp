// Benelux Algorithm Programming Contest preliminaries 2018
// E - Eating Everything Efficiently
// https://open.kattis.com/problems/eatingeverything

#include <bits/stdc++.h>
using namespace std;

const int ms = 5e5+5;

vector<int> g[ms];
double c[ms];
int vis[ms];
double ans[ms];

double dfs(int u) {
  if(vis[u]) return ans[u];
  vis[u] = 1;
  for(int v : g[u]) {
    ans[u] = max(ans[u], dfs(v));
  }
  return ans[u] = max(ans[u], ans[u]/2+c[u]);
}

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
  }
  cout << dfs(0) << endl;
}
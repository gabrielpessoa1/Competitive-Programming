#include <bits/stdc++.h>
using namespace std;

const int ms = 1e5+5;

pair<int, int> hi[ms];
priority_queue<pair<int, int>> pq;
int par[ms];
int vis[ms];
vector<int> g[ms];

pair<int, int> dfs(int x) {
  pair<int, int> ans = {1, x};
  for(int y : g[x]) {
    pair<int, int> temp = dfs(y);
    temp.first++;
    ans = max(ans, temp);
  }
  return hi[x] = ans;
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  for(int i = 2; i <= n; i++) {
    cin >> par[i];
    g[par[i]].push_back(i);
  }
  vis[0] = 1;
  dfs(1);
  int ans = 0;
  pq.push(hi[1]);
  while(ans < n && k--) {
    int x = pq.top().second;
    pq.pop();
    while(!vis[x]) {
      for(int y : g[x]) if(!vis[y]) pq.push(hi[y]);
      vis[x] = 1;
      ans++;
      x = par[x];
    }
  }
  cout << ans << endl;
}
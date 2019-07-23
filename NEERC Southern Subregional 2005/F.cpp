#include <bits/stdc++.h>
using namespace std;
 
const int ms = 2005;
 
typedef pair<int, int> ii;
 
vector<pair<int, int>> g[ms];
vector<int> gg[ms];
int distX[ms], distY[ms];
int goodVertex[ms];
priority_queue<ii, vector<ii>, greater<ii>> pq;
 
void dijkstra(int src, int dist[]) {
  memset(dist, 63, sizeof distX);
  dist[src] = 0;
  pq.push({0, src});
  while(!pq.empty()) {
    int d = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if(d != dist[u]) continue;
    for(auto e : g[u]) {
      if(d + e.second < dist[e.first]) {
        dist[e.first] = d + e.second;
        pq.push({dist[e.first], e.first}); 
      }
    }
  }
}
 
main() {
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
	  int u, v, w;
	  scanf("%d%d%d", &u, &v, &w);
	  g[u].emplace_back(v, w);
	  g[v].emplace_back(u, w);
  }
  dijkstra(x, distX); dijkstra(y, distY);
  for(int i = 1; i <= n; i++) {
    goodVertex[i] = (distX[i] + distY[i] == distX[y]);
    if(!goodVertex[i]) continue;
    for(auto e : g[i]) {
      if(distX[i] + e.second + distY[e.first] == distX[y]) gg[i].push_back(distX[i] + e.second);
    }
    sort(gg[i].begin(), gg[i].end());
  }
  for(int i = 1; i <= n; i++) {
    if(!goodVertex[i]) {
      cout << 0;
    } else {
      int ans = 0;
      for(int j = 1; j <= n; j++) {
        if(!goodVertex[j]) continue;
        if(distX[j] == distX[i]) ans++;
        else if(distX[j] < distX[i]){
          ans += gg[j].size() - (upper_bound(gg[j].begin(), gg[j].end(), distX[i]) - gg[j].begin());
        }
      }
      cout << ans;
    }
    if(i < n) cout << ' ';
    else cout << '\n';
  }
}
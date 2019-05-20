// ICPC Live Archive
// 3661 - Animal Run
// https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=1662

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int ms = 2e6+5;
const int inf = 0x3f3f3f3f;

priority_queue<ii, vector<ii>, greater<ii>> pq;
vector<ii> g[ms];
int d[ms];

void add(int a, int b) {
  int k;
  cin >> k;
  g[a].push_back(ii(b, k));
  g[b].push_back(ii(a, k));
}

main() {
  int n, m, T = 0;
  while(cin >> n >> m, n || m) {
    n--; m--;
    for(int i = 0; i < n * m * 2+2; i++) {
      g[i].clear();
      d[i] = inf;
    }
    int src = n*m*2, snk = n*m*2+1;
    for(int i = 0; i < m; i++) {
      add(src, i*2+1);
    }
    for(int i = 0; i < n-1; i++) {
      for(int j = 0; j < m; j++) {
        add((i*m+j)*2, ((i+1)*m+j)*2+1);
      }
    }
    for(int i = 0; i < m; i++) {
      add(snk, ((n-1)*m+i)*2);
    }
    for(int i = 0; i < n; i++) {
      add(snk, (i*m)*2);
      for(int j = 0; j < m-1; j++) {
        add((i*m + j)*2+1, (i*m + j + 1)*2);
      }
      add(src, (i*m + m - 1)*2+1);
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        add((i*m + j)*2, (i*m + j)*2 + 1);
      }
    }
    d[src] = 0;
    pq.push({0, src});
    while(!pq.empty()) {
      int u = pq.top().second;
      int k = pq.top().first;
      pq.pop();
      if(k != d[u]) continue;
      for(auto e : g[u]) {
        int v = e.first, w = e.second;
        if(d[u] + w < d[v]) {
          d[v] = d[u] + w;
          pq.push({d[v], v});
        }
      }
    }
    cout << "Case " << ++T << ": Minimum = " << d[snk] << '\n';
  }
}
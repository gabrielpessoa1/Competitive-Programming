#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> ii;
typedef pair<int, string> is;
 
const int ms = 100;
 
int g[ms][ms];
 
template <class T = int>
class MCMF {
public:
  struct Edge {
    Edge(int a, T b, T c) : to(a), cap(b), cost(c) {}
    int to;
    T cap, cost;
  };
  
  MCMF(int size) {
    n = size;
    edges.resize(n);
    pot.assign(n, 0);
    dist.resize(n);
    visit.assign(n, false);
  }
  
  pair<T, T> mcmf(int src, int sink) {
    pair<T, T> ans(0, 0);
    if(!SPFA(src, sink)) return ans;
    fixPot();
    while(SPFA(src, sink)) {
      auto flow = augment(src, sink);
      ans.first += flow.first;
      ans.second += flow.first * flow.second;
      fixPot();
    }
    return ans;
  }
  
  void addEdge(int from, int to, T cap, T cost) {
    edges[from].push_back(list.size());
    list.push_back(Edge(to, cap, cost));
    edges[to].push_back(list.size());
    list.push_back(Edge(from, 0, -cost));
  }
  
  int n;
  vector<vector<int>> edges;
  vector<Edge> list;
  vector<int> from;
  vector<T> dist, pot;
  vector<bool> visit;
  
  pair<T, T> augment(int src, int sink) {
    pair<T, T> flow = {list[from[sink]].cap, 0};
    for(int v = sink; v != src; v = list[from[v]^1].to) {
      flow.first = min(flow.first, list[from[v]].cap);
      flow.second += list[from[v]].cost;
    }
    for(int v = sink; v != src; v = list[from[v]^1].to) {
      list[from[v]].cap -= flow.first;
      list[from[v]^1].cap += flow.first;
    }
    return flow;
  }
  
  queue<int> q;
  
  bool SPFA(int src, int sink) {
    //cout << "SPFA " << src << ' ' << sink << endl;
    T INF = numeric_limits<T>::max();
    dist.assign(n, INF);
    from.assign(n, -1);
    q.push(src);
    dist[src] = 0;
    while(!q.empty()) {
      int on = q.front();
      q.pop();
      visit[on] = false;
      for(auto e : edges[on]) {
        auto ed = list[e];
        if(ed.cap == 0) continue;
        T toDist = dist[on] + ed.cost + pot[on] - pot[ed.to];
        if(toDist < dist[ed.to]) {
          dist[ed.to] = toDist;
          from[ed.to] = e;
          if(!visit[ed.to]) {
            visit[ed.to] = true;
            q.push(ed.to);
          } 
        }
      }
    }
    //cout << dist[sink] << " fim " << endl;
    return dist[sink] < INF;
  }
  
  void fixPot() {
    T INF = numeric_limits<T>::max();
    for(int i = 0; i < n; i++) {
      if(dist[i] < INF) pot[i] += dist[i];
    }
  }
};
 
main () {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int TT;
  cin >> TT;
  for(int T = 1; T <= TT; T++) {
    cout << "Case " << T << ": ";
    int m, n;
    cin >> m >> n;
    string s;
    int src = m+n, snk = m+n+1;
    int ans = 0x3f3f3f3f;
    int shift = 0;
    for(int i = 0; i < m; i++) {
      cin >> s;
      for(int j = 0; j < n; j++) {
        if(s[j] == '1') {
          g[i][j] = -1;
          shift++;
        } else {
          g[i][j] = 1; 
        }
      }
    }
    for(int r = 0; r <= n; r++) {
      if(r*m % n != 0) continue;
      MCMF<> mf(m+n+2);
      int c = r*m / n;
      for(int i = 0; i < m; i++) {
        mf.addEdge(src, i, r, 0);
      }
      for(int i = 0; i < n; i++) {
        mf.addEdge(i+m, snk, c, 0);
      }
      for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
          mf.addEdge(i, j+m, 1, g[i][j]);
        }
      }
      //cout << "MCMF de " << r << ' ' << c << endl;
      ans = min(ans, mf.mcmf(src, snk).second);
      //cout << " deu " << ans << endl;
    }
    cout << ans + shift << '\n';
  }
}
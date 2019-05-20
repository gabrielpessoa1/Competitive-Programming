#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int ms = 1e5+5;
const int inf = 0x3f3f3f3f;

double p[30];
vector<int> g[ms];
int sz[ms], goTo[ms], sndSz[ms];
int par[ms];
int realSz[ms];
int vis[ms];
int st[ms];
int stSz = -1;
pair<double, double> val[30];

inline void dfs(int k) {
  st[++stSz] = k;
  while(stSz > -1) {
    int u = st[stSz];
    //cout << stSz << ' ' << u << ' ' << vis[u] << endl;
    if(vis[u] == 2) stSz--;
    else if(vis[u] == 1) {
      sz[u] = 0;
      sndSz[u] = 0;
      for(auto v : g[u]) {
        if(vis[v] == 2) {
          if(sz[v] + 1 > sz[u]) {
            sndSz[u] = sz[u];
            sz[u] = sz[v] + 1;
            goTo[u] = v;
          } else if(sz[v] + 1 > sndSz[u]) {
            sndSz[u] = sz[v] + 1;
          }
        }
      }
      vis[u] = 2;
      //cout << e << ' ' << u << ' ' << sz[e] << endl;
      stSz--;
    } else {
      for(auto v : g[u]) {
        if(!vis[v]) {
          par[v] = u;
          st[++stSz] = v;
        }
      }
      vis[u] = 1;
    }
  }


  //

  
  st[++stSz] = k;
  while(stSz > -1) {
    int u = st[stSz];
    //cout << stSz << ' ' << u << ' ' << vis[u] << endl;
    stSz--;
    int szPar = goTo[par[u]] == u ? sndSz[par[u]] + 1 : sz[par[u]] + 1;
    if(szPar > sz[u]) {
      sndSz[u] = sz[u];
      sz[u] = szPar;
      goTo[u] = par[u];
    } else if(szPar > sndSz[u]) {
      sndSz[u] = szPar;
    }
    //cout << sz[u] << ' ' << u << endl;
    for(auto v : g[u]) {
      if(v != par[u]) st[++stSz] = v;
    }
  }
}

main() {
  int t;
  scanf("%d", &t);
  sz[0] = -1;
  while(t--) {
    int c, k;
    scanf("%d%d", &c, &k);
    for(int tree = 0; tree < c; tree++) {
      int n;
      scanf("%d", &n);
      for(int i = 1; i <= n; i++) {
        g[i].clear();
        vis[i] = 0;
      }
      for(int i = 2; i <= n; i++) {
        int a;
        scanf("%d", &a);
        g[a].emplace_back(i);
        g[i].emplace_back(a);
      }
      dfs(1);
      int ans = 0;
      for(int i = 1; i <= n; i++) {
        if(sz[i] <= k) ans++;
      }
      p[tree] = 1.0*ans/n;
      //cout << "Arvore " << tree << " tem prob " << ans << "/" << n << " de funcionar " << endl;
      // ans = nao causa overflow
    }
    val[c] = {0, 0};
    for(int i = c - 1; i >= 0; i--) {
      double x = p[i];
      double y = 1 - p[i];
      val[i] = {1+3*y+val[i+1].first*x, y + val[i+1].second*x};
    }
    double ans = val[0].first/(1 - val[0].second);
    printf("%.4f\n", ans);
  }
}
#include <bits/stdc++.h>
using namespace std;

const int ms = 1e5+5;
const int inf = 0x3f3f3f3f;

double x[ms], h[ms];
int leafs;
int k[ms];
int l[ms], r[ms];
int notRoot[ms];

void dfs(int u, int v) {
  h[u] = v;
  if(k[u] == 0) {
    x[u] = leafs++;
  } else {
    dfs(l[u], v+1); dfs(r[u], v+1);
    x[u] = (x[l[u]] + x[r[u]])/2;
  }
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  cout << fixed << setprecision(4);
  int t;
  cin >> t;
  while(t--) {
    int n, q;
    cin >> n >> q;
    int root = -1;
    memset(notRoot, 0, sizeof notRoot);
    for(int i = 1; i <= n; i++) {
      cin >> k[i];
      if(k[i] == 2){
        cin >> l[i] >> r[i];
        notRoot[l[i]] = 1;
        notRoot[r[i]] = 1;
      }
    }
    for(int i = 1; i <= n; i++) {
      if(!notRoot[i]) root = i;
    }
    leafs = 0;
    dfs(root, 0);
    for(int i = 0; i < q; i++) {
      double R, V, H; int u;
      cin >> R >> V >> H >> u;
      cout << (2*R + H)*(x[u]-x[root]) << ' ' << -(V+2*R)*h[u] << '\n';
    }
  }
}
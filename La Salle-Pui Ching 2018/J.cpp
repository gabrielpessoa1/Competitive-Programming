// La Salle-Pui Ching Programming Challenge 培正喇沙編程挑戰賽 2018
// J - Jakanda Forever
// https://codeforces.com/gym/101807/problem/J

#include <bits/stdc++.h>
using namespace std;

const int ms = 5e5+5;

typedef pair<int, int> ii;
typedef pair<int, ii> iii; 

vector<iii> g[ms]; // { To, {Weight, Idx} }

int n;
int w[ms];
int edgeToVertex[ms];
int sz[ms], par[ms], h[ms];
int t, in[ms], out[ms], rin[ms], nxt[ms];
int seg[2*ms];

void build() {
  for(int i = 0; i < n; i++) {
    seg[in[i]+n] = w[i];
  }
  for(int i = n - 1; i > 0; --i) seg[i] = seg[i<<1] + seg[i<<1|1];
}

void update(int p, int value) {
  p = in[edgeToVertex[p]];
  for(seg[p += n] = value; p > 1; p >>= 1) seg[p>>1] = seg[p] + seg[p^1];
}

int query(int l, int r) {
  int ans = 0;
  for(l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
    if(l&1) ans += seg[l++];
    if(r&1) ans += seg[--r];
  }
  return ans;
}

void dfs_sz(int v = 0, int p = -1) {
  sz[v] = 1;
  for(int i = 0; i < g[v].size(); i++) {
    auto &e = g[v][i];
    int u = e.first;
    if(u == p) continue;
    h[u] = h[v] + 1, par[u] = v;
    edgeToVertex[e.second.second] = u;
    w[u] = e.second.first;
    dfs_sz(u, v);
    sz[v] += sz[u];
    if(g[v][0].first == p || sz[u] > sz[g[v][0].first]) {
      swap(e, g[v][0]);
    }
  }
}

void dfs_hld(int v = 0, int p = -1) {
  in[v] = t++;
  rin[in[v]] = v;
  for(int i = 0; i < g[v].size(); i++) {
    auto &e = g[v][i];
    int u = e.first;
    if(u == p) continue;
    nxt[u] = u == g[v][0].first ? nxt[v] : u;
    dfs_hld(u, v);  
  }
  out[v] = t;
}

int up(int v) {
  return (nxt[v] != v) ? nxt[v] : (~par[v] ? par[v] : v);
}

int getLCA(int a, int b) {
  while(nxt[a] != nxt[b]) {
    if(h[a] == 0 || h[up(a)] < h[up(b)]) swap(a, b);
    a = up(a);
  }
  return h[a] < h[b] ? a : b;
}

int queryUp(int a, int p = 0) {
  int ans = 0;
  while(nxt[a] != nxt[p]) {
    ans += query(in[nxt[a]], in[a]);
    a = par[nxt[a]];
  }
  ans += query(in[p]+1, in[a]);
  return ans;
}

bool queryPath(int u, int v) {
  int lca = getLCA(u, v);
  int qu = queryUp(u, lca);
  int qv = queryUp(v, lca); 
  return (qu + qv) % 2 == 0;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  cin >> n;
  for(int i = 1; i < n; i++) {
   int u, v, l;
   cin >> u >> v >> l;
   u--; v--;
   l %= 2;
   g[u].push_back({v, {l, i-1}});
   g[v].push_back({u, {l, i-1}});
  }
  dfs_sz();
  dfs_hld();
  build();
  int q;
  cin >> q;
  for(int i = 0; i < q; i++) {
   int type;
   cin >> type;
   if(type == 1) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    if(queryPath(u, v)) cout << "JAKANDA FOREVER\n";
    else cout << "WE NEED BLACK PANDA\n";
   } else {
    int u, l;
    cin >> u >> l;
    u--; l %= 2;
    update(u, l);
   }
  }
}
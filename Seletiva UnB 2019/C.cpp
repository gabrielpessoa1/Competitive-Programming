// Seletiva UnB 2019
// C - Boca de Urna
// https://codeforces.com/group/btcK4I5D5f/contest/244688/problem/C

#include <bits/stdc++.h>
using namespace std;

const int ms = 1e5+5;

int ds[ms], sz[ms], n;

void dsBuild() {
  for(int i = 1; i <= n; i++) {
    ds[i] = i;
    sz[i] = 1;
  }
}

int dsFind(int i) {
  if(ds[i] != i) ds[i] = dsFind(ds[i]);
  return ds[i];
}

void dsUnion(int a, int b) {
  a = dsFind(a); 
  b = dsFind(b);
  if(a == b) return;
  if(sz[a] < sz[b]) swap(a, b);
  sz[a] += sz[b];
  ds[b] = a;
}

main() {
  int q;
  cin >> n >> q;
  dsBuild();
  while(q--) {
    int a, b;
    cin >> a >> b;
    dsUnion(a, b);
  }
  int m;
  cin >> m;
  while(m--) {
    int e;
    cin >> e;
    sz[dsFind(e)] = 0;
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    if(ds[i] == i && sz[i]) ans++;
  }
  cout << ans << endl;
}
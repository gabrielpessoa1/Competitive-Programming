#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 130;

int m, n;
int x[ms], y[ms], z[ms];
int ds[ms];
int dsMask[ms];
int par[ms];

int build() {
  for(int i = 0; i < n; i++) ds[i] = i;
  for(int i = 0; i < n; i++) dsMask[i] = (1ll << i);
}

int dsFind(int u) {
  if(ds[u] != u) ds[u] = dsFind(ds[u]);
  return ds[u];
}

void dsUnion(int u, int v) {
  u = dsFind(u); v = dsFind(v);
  ds[u] = v;
  dsMask[v] |= dsMask[u];
}

bool solve(int mask, int p) {
  //cout << mask << ' ' << p+1 << endl;
  for(int i = 0; i < n; i++) {
    if(mask & (1ll << i)) {
      build();
      for(int j = 0; j < m; j++) {
        if(i != z[j] && (mask & (1ll << z[j]))) {
          dsUnion(x[j], y[j]);
          dsUnion(y[j], z[j]);
        }
      }
      bool possible = true;
      for(int j = 0; j < m; j++) {
        if(i == z[j] && dsFind(x[j]) == dsFind(y[j])) {
          possible = false;
        }
      }
      if(dsMask[dsFind(i)] != (1ll << i)) possible = false;
      if(possible) {
        par[i] = p;
        vector<int> masksToCall;
        for(int j = 0; j < n; j++) {
          if((mask & (1ll << j)) && ds[j] == j && j != i) {
            masksToCall.push_back(dsMask[j]);
          }
        }
        for(int m : masksToCall) {
          if(!solve(m, i)) return false;
        }
        return true;
      }
    }
  }
  return false;
}

main() {
  int t;
  cin >> t;
  for(int T = 1; T <= t; T++) {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
      cin >> x[i] >> y[i] >> z[i];
      x[i]--; y[i]--; z[i]--;
    }
    cout << "Case #" << T << ":";
    if(solve((1ll << n) - 1, -1)) {
      for(int i = 0; i < n; i++) {
        cout << " " << par[i]+1;
      }
      cout << '\n';
    } else {
      cout << " Impossible\n";
    }
  }
}
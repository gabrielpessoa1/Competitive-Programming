#include <bits/stdc++.h>
using namespace std;

const int ms = 1005;
const int inf = 0x3f3f3f3f;

int g[ms][ms];
int x[ms], y[ms], z[ms];

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int t;
  cin >> t;
  for(int T = 1; T <= t; T++) {
    cout << "Case #" << T << ": ";
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(i == j) g[i][j] = 0;
        else g[i][j] = inf;
      }
    }
    for(int i = 0; i < m; i++) {
      cin >> x[i] >> y[i] >> z[i];
      x[i]--; y[i]--;
      g[x[i]][y[i]] = z[i];
      g[y[i]][x[i]] = z[i];
    }
    for(int k = 0; k < n; k++) {
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
          g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        }
      }
    }
    bool possible = true;
    for(int i = 0; i < m; i++) {
      if(g[x[i]][y[i]] != z[i]) possible = false;
    }
    if(possible) {
      cout << m << '\n';
      for(int i = 0; i < m; i++) {
        cout << x[i]+1 << ' ' << y[i]+1 << ' ' << z[i] << '\n';
      }
    } else {
      cout << "Impossible\n";
    }
  }
}
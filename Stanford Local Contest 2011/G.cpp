#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int ms = 100005;
 
int a[ms], A[ms], b[ms], B[ms];
int d[ms];
int u[ms], v[ms], w[ms], z;
 
void add(int i, int j, int k) {
  u[z] = i; v[z] = j; w[z] = k;
  z++;
}
 
main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n, m, q;
  while(cin >> n >> m >> q, n || m || q) {
    z = 0;
    for(int i = 0; i < n; i++) {
      a[i] = i;
      A[i] = i + n;
    }
    for(int i = 0; i < m; i++) {
      b[i] = i + n + n;
      B[i] = i + n + n + m;
    }
    for(int i = 0; i < q; i++) {
      int x, y, k;
      string s;
      cin >> x >> y >> s >> k;
      x--; y--;
      if(s[0] == '<') {
        add(a[x], B[y], k);
        add(b[y], A[x], k);
      } else {
        add(A[x], b[y], -k);
        add(B[y], a[x], -k);
      }
    }
    bool change = false;
    for(int i = 0; i < 2005; i++) {
      change = false;
      for(int j = 0; j < z; j++) {
        if(d[u[j]] + w[j] < d[v[j]]) {
          d[v[j]] = d[u[j]] + w[j];
          change = true;
        }
      }
    }
    if(change) cout << "Impossible\n";
    else cout << "Possible\n";
  }
}
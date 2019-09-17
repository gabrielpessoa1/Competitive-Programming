#include <bits/stdc++.h>
using namespace std;

const int ms = 1010;

int ds[ms];
int x[ms], y[ms], s[ms];

int find(int x) {
  if(ds[x] != x) ds[x] = find(ds[x]);
  return ds[x];
}

void unite(int i, int j) {
  i = find(i); j = find(j); ds[i] = j;
}

main () {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m, n, k;
  cin >> m >> n >> k;
  for(int i = 0; i < k; i++) {
    ds[i] = i;
    cin >> x[i] >> y[i] >> s[i];
  }
  for(int i = 0; i < 4; i++) {
    ds[i+k] = i+k;
  }
  int x0 = k, xm = k+1, y0 = k+2, yn = k+3;
  for(int i = 0; i < k; i++) {
    for(int j = 0; j < i; j++) {
      if((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) <= (s[i] + s[j]) * (s[i] + s[j])) {
        unite(i, j);
      }
    }
    if(x[i] <= s[i]) unite(i, x0);
    if(m - x[i] <= s[i]) unite(i, xm);
    if(y[i] <= s[i]) unite(i, y0);
    if(n - y[i] <= s[i]) unite(i, yn);
  }
  unite(x0, yn); unite(y0, xm);
  if(find(x0) == find(y0)) cout << "N\n";
  else cout << "S\n";
}
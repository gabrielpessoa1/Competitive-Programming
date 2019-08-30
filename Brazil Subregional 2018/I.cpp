#include <bits/stdc++.h>
using namespace std;

const int ms = 1005;

int a[ms];
int b[ms][ms];
int k[ms];

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  int l;
  cin >> l;
  for(int i = 0; i < l; i++) {
    int x;
    cin >> x;
    a[x] = 1;
  }
  for(int i = 0; i < n; i++) {
    cin >> k[i];
    for(int j = 0; j < k[i]; j++) {
      cin >> b[i][j];
    }
  }
  for(int i = 0; i < n+n; i++) {
    for(int j = 0; j < k[i%n]; j++) {
      if(a[b[i%n][j]]) {
        l--;
      } else {
        l++;
      }
      a[b[i%n][j]] = !a[b[i%n][j]];
    }
    if(!l) {
      cout << i+1 << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
}
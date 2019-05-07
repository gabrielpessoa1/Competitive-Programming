#include <bits/stdc++.h>
using namespace std;

const int ms = 1005;

int n = 1000;
int bit[ms][ms];

void update(int i, int jj, int v) {
  while(i <= n) {
    int j = jj;
    while(j <= n) {
      bit[i][j] = max(bit[i][j], v);
      j += j & -j;
    }
    i += i & -i;
  }
}

int query(int i, int jj) {
  int ans = 0;
  while(i > 0) {
    int j = jj;
    while(j > 0) {
      ans = max(ans, bit[i][j]);
      j -= j & -j;
    }
    i -= i & -i;
  }
  return ans;
}


int main() {
  int t;
  cin >> t;
  while(t--) {
    memset(bit, 0, sizeof bit);
    int m;
    cin >> m;
    while(m--) {
      int x, y;
      cin >> x >> y;
      int ans = 1 + query(x, y);
      update(x, y, ans);
    }
    cout << query(n, n) << '\n';
  }
}
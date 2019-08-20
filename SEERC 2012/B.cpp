#include <bits/stdc++.h>
using namespace std;

const int ms = 2e5+5;

int bit[ms];
int a[ms];
int n;

int query(int i) {
  int ans = 0;
  while(i > 0) {
    ans += bit[i];
    i -= i & -i;
  }
  return ans;
}

void update(int i) {
  while(i <= n+n) {
    bit[i]++;
    i += i & -i;
  }
}

main() {
  #ifdef ONLINE_JUDGE
  freopen("b.in", "r", stdin);
  #endif
  cin.tie(0); ios::sync_with_stdio(0);
  cin >> n;
  int ans = 0;
  int q = 0;
  for(int i = 1; i <= n+n; i++) {
    int x;
    cin >> x;
    if(a[x]) {
      ans += (i - 1 - q) - (a[x] - query(a[x]));
      q += 2;
      update(a[x]); update(i);
    } else {
      a[x] = i;
    }
  }
  cout << ans << '\n';
}
#include <bits/stdc++.h>
using namespace std;

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n;
  cin >> n;
  int ans = 0;
  while(n--) {
    int x;
    cin >> x;
    if(x != 1) ans++;
  }
  cout << ans << '\n';
}
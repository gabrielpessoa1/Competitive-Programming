#include <bits/stdc++.h>
using namespace std;

main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int x, y;
    cin >> x >> y;
    if(x == y) cout << "YES\n";
    else cout << "NO\n";
  }
}
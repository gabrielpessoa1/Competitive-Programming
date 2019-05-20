#include <bits/stdc++.h>
using namespace std;

main() {
  int t;
  cin >> t;
  while(t--) {
    int x, y;
    cin >> x >> y;
    cout << max(x, y) * max(x, y) << endl;
  }
}
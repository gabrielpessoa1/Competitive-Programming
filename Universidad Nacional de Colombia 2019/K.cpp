#include <bits/stdc++.h>
using namespace std;

const int ms = 2e5+5;

int ans[ms];

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int t;
  cin >> t;
  ans[1] = 0;
  ans[2] = 0;
  ans[3] = 2;
  for(int i = 4; i < ms; i++) {
    ans[i] = ans[i-1] + (i % 3 == 0 || i % 3 == 1);
  }
  while(t--) {
    int n;
    cin >> n;
    cout << ans[n] << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;

#define int long long

main() {
  int n;
  cin >> n;
  int ans = 1;
  for(int i = 0; i < 62; i++) {
    if(n & (1ll << i)) ans *= 2;
  }
  cout << ans << endl;
}
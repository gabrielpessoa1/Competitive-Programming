#include <bits/stdc++.h>
using namespace std;

main() {
  int n;
  cin >> n;
  int ans = n+1 + (n+1)*n/2;
  if(n % 2 == 1) {
    cout << ans - (n/2) << endl;
  } else {
    cout << ans << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int ms = 2005;
const int mod = 1e9+7;
 
int fat[ms];
int ifat[ms];
int sol[ms];
 
int fexp(int a, int b) {
  int ans = 1;
  while(b) {
    if(b&1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
 
main() {
  sol[0] = 1;
  fat[0] = 1;
  ifat[0] = 1;
  for(int i = 1; i <= 2000; i++) {
    sol[i] = sol[i-1]*2*(i+i-1)%mod;
    fat[i] = fat[i-1]*i%mod;
    ifat[i] = fexp(fat[i], mod-2);
  }
  int n;
  while(cin >> n, n) {
    int ans = 0;
    for(int i = 0; i < n; i++) {
      int b = n-i-1;
      int a = i;
      ans = (sol[a]*sol[b]*2%mod*fat[n+n-1]%mod*ifat[a+a]%mod*ifat[b+b]%mod + ans) % mod;
    }
    cout << ans << '\n';
  }
}
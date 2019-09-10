#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 1005;
const int mod = 1e9+7;

int dp[ms][ms];
int ans[ms];

int fexp(int a, int b) {
  int ans = 1;
  while(b) {
    if(b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n;
  cin >> n;
  dp[0][0] = 1;
  for(int i = 1; i <= n; i++) {
    cout << 1 << ' ' << 1 << ' ' << i << endl;
    int k, s;
    cin >> k >> s;
    ans[i] = (s + mod - dp[i-1][k]) % mod * fexp(dp[i-1][k-1], mod-2) % mod;
    dp[i][0] = 1;
    for(int j = 1; j <= i; j++) {
      dp[i][j] = (dp[i-1][j] + dp[i-1][j-1] * ans[i]) % mod;
    }
  }
  cout << 2;
  for(int i = 1; i <= n; i++) {
    cout << ' ' << ans[i];
  }
  cout << endl;
}
#include <bits/stdc++.h>
using namespace std;

const int ms = 1e5+5;
const int mod = 1e9+7;

int n, e, k;
int dp[2005][1 << 9];
int imp[2005][2005];

int solve(int i, int m) {
  if(i == n) return 1;
  int &ans = dp[i][m];
  if(~ans) return ans;
  ans = 0;
  for(int j = 0; j <= 2*e; j++) {
    if(!(m & (1 << j)) && j+i-e < n && !imp[i][j+i-e]) {
      ans = (ans + solve(i+1, (m | (1 << j)) >> 1)) % mod;
    }
  }
  return ans;
}

main() {
  ios::sync_with_stdio(0); cin.tie(0);
  memset(dp, -1, sizeof dp);
  cin >> n >> e >> k;
  for(int i = 0; i < k; i++) {
    int u, v;
    cin >> u >> v;
    imp[u-1][v-1] = 1;
  }
  int mask = 0;
  for(int i = 0; i < e; i++) mask |= (1 << i);
  cout << solve(0, mask) << '\n';
}
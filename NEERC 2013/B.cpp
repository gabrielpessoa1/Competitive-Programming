#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int ms = 3005;
 
int n, a, b;
int vis[ms][ms];
double dp[ms][ms];
 
double solve(int i, int j, int q) {
  if(i > a || j > b) return 0;
  if(i+j == n) return 0;
  if(vis[i][j] == q) return dp[i][j];
  vis[i][j] = q;
  int qnt = (a - i) * 2 + (b - j) + q;
  return dp[i][j] = (q + solve(i+1, j, q) * (a-i)*2 + solve(i, j+1, q) * (b-j))/qnt;
}
 
main() {
  cin.tie(0); ios::sync_with_stdio(0);
  #ifdef ONLINE_JUDGE
  freopen("bonus.in", "r", stdin);
  freopen("bonus.out", "w", stdout);
  #endif
  cin >> n >> a >> b;
  cout << fixed << setprecision(15) << solve(0, 0, 2) << '\n' << solve(0, 0, 1) << '\n';
}
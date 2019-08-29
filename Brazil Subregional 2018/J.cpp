#include <bits/stdc++.h>
using namespace std;

const int ms = 101;
double x[ms], y[ms];
double dp[1<<10][ms];
double dist[ms][ms];

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n, c;
  cin >> n >> c;
  for(int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      dist[i][j] = hypot(x[j]-x[i], y[j]-y[i]);
    }
  }
  for(int i = 0; i < (1 << c); i++) {
    for(int j = c; j < n; j++) {
      dp[i][j] = 1e100;
    }
    for(int j = c; j < n; j++) {
      for(int k = 0; k < c; k++) {
        if(i == (1 << k)) {
          dp[i][j] =  dist[j][k];
        }
        for(int k = i; k > 0; k = (k-1)&i) {
          dp[i][j] = min(dp[i][j], dp[k][j] + dp[i^k][j]);
        }
        for(int k = c; k < n; k++) {
          dp[i][k] = min(dp[i][k], dp[i][j] + dist[j][k]);
        }
      }
    }
  }
  double ans = 1e100;
  for(int i = c; i < n; i++) {
    ans = min(ans, dp[(1 << c) - 1][i]);
  }
  cout << fixed << setprecision(5) << ans << '\n'; 
}
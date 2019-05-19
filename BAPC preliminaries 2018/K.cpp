// Benelux Algorithm Programming Contest preliminaries 2018
// K - KALLAX Construction
// https://open.kattis.com/problems/kallaxconstruction

#include <bits/stdc++.h>
 
using namespace std;

typedef pair<int, int> ii;

const int MAXN = 1e3 + 7;
const int inf = 0x3f3f3f3f;

int sz[MAXN];
int a[MAXN][MAXN];
int realVal[MAXN][MAXN];
ii dp[MAXN][MAXN];
 
void solve(int idx) {
  for(int j = 1; j < MAXN; j++) {
    dp[0][j] = {inf, inf};
  }
  for (int i = 1; i <= sz[idx]; i++) {
    for (int j = 1; j < MAXN; j++) {
      dp[i][j] = {inf, inf};
      if(j > a[idx][i]) {
        dp[i][j] = dp[i][j-a[idx][i]];
        dp[i][j].second += realVal[idx][i];
      } else {
        dp[i][j] = {a[idx][i] - j, realVal[idx][i]};
      }
      dp[i][j] = min(dp[i][j], dp[i-1][j]);
    }
  }
}
 
int main() {
  int b;
  cin >> b;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> sz[i];
    for (int j = 1; j <= sz[i]; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    if(i == 0) {
      for(int j = 1; j <= sz[i]; j++) {
        realVal[i][j] = a[i][j];
      }
    } else {
      solve(i-1);
      for(int j = 1; j <= sz[i]; j++) {
        realVal[i][j] = dp[sz[i-1]][a[i][j]].second;
      }
    }
  }
  int ans = inf;
  for(int i = 0; i < n; i++) {
    for(int j = 1; j <= sz[i]; j++) {
      if(realVal[i][j] >= b) {
        ans = min(ans, a[i][j]);
      }
    }
  }
  if(ans == inf) cout << "impossible\n";
  else cout << ans << endl;
  return 0;
}
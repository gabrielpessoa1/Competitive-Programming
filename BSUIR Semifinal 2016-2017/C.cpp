#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];
int nxt[1005][1005];
string s;
int n, k;

int main() {
  cin >> n >> k >> s;
  dp[n][0] = 1;
  for(int i = n-1; i >= 0; i--) {
    for(int j = 0; j < k; j++) {
      if(s[i] != '?') {
        if(s[0] == '0' && n > 1) {
          cout << -1 << '\n';
          return 0;
        }
        dp[i][j] = dp[i+1][(j*10 + s[i] - '0') % k];
        nxt[i][j] = s[i] - '0';
      } else {
        for(int d = 0; d < 10 && !dp[i][j]; d++) {
          if(d == 0 && i == 0 && n > 1) continue;
          if(dp[i+1][(j*10 + d) % k]) {
            dp[i][j] = 1;
            nxt[i][j] = d;
          }
        }
      }
    }
  }
  if(dp[0][0]) {
    int i = 0, j = 0;
    while(i < n) {
      int d = nxt[i][j];
      j = (j*10 + d) % k;
      i++;
      cout << d;
    }
    cout << '\n';
  } else {
    cout << -1 << '\n';
  }
}
#include <bits/stdc++.h>
using namespace std;

const int ms = 1e5+5;

int m[ms], f[ms];
int isEmpty[ms];

int dp[3005][3005][2][2];

main() {
  int n;
  cin >> n;
  int qntM = 0;
  for(int i = 0; i < n; i++) {
    cin >> m[i] >> f[i];
    qntM += m[i];
  }
  if(qntM == 0) {
    cout << 0 << '\n';
    return 0;
  }
  int empt = 0;
  for(int i = 0; i < n; i++) {
    if(m[i] == 0 && f[i] == 0) {
      isEmpty[i] = 1;
      empt++;
    }
  }
  for(int i = 0; i < n; i++) {
    if(isEmpty[i]) continue;
    f[i] = f[i] - 1;
  }
  memset(dp, 63, sizeof dp);
  for(int j = 0; j <= empt; j++) {
    dp[n][j][1][1] = 0;
  }
  for(int i = n-1; i >= 0; i--) {
    for(int j = 0; j <= empt; j++) {
      for(int hasSo = 0; hasSo < 2; hasSo++) {
        for(int hasUm = 0; hasUm < 2; hasUm++) {
          int &ans = dp[i][j][hasSo][hasUm];
          ans = dp[i+1][j][hasSo][1] + m[i] + f[i];
          if(isEmpty[i] && j > 0) {
            ans = min(ans, dp[i+1][j-1][1][hasUm]);
          }
          if(!isEmpty[i]) {
            int k = min(j, m[i]); 
            ans = min(ans, dp[i+1][j-k][1][hasUm] + m[i] + m[i] - k);
          }
        }
      }
    }
  }
  cout << dp[0][empt][0][0] << endl;
}
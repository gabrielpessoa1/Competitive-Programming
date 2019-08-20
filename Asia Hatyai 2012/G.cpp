#include <bits/stdc++.h>
using namespace std;
  
const int ms = 1005;
  
int dp[ms][ms];
int d[ms][ms];
int w[ms][ms];
int go[ms][ms];
int seq[ms];
  
int main () {
  cin.tie(0); ios::sync_with_stdio(0);
  int n, h;
  cin >> n >> h;
  for(int i = 0; i <  n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> d[i][j];
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < h; j++) {
      cin >> w[i][j];
    }
  }
  string s;
  int k;
  while(getline(cin, s)) {
    stringstream ss(s);
    k = 0;
    int x;
    while(ss >> x) {
      seq[k++] = x;
    }
    if(k == 0) continue;
    for(int i = 1; i < n; i++) {
      dp[k][i] = d[i][0];
    }
    for(int i = k - 1; i >= 0; i--) {
      for(int j = 0; j < n; j++) {
        dp[i][j] = 0x3f3f3f3f;
        for(int l = 1; l < n; l++) {
          int cur = dp[i+1][l] + d[j][l] + w[l][seq[i]];
          if(cur < dp[i][j]) {
            dp[i][j] = cur;
            go[i][j] = l;
          }
        }
      }
    }
    cout << dp[0][0] << '\n';
    int i = 0, j = 0;
    while(i < k) {
      cout << go[i][j];
      j = go[i][j];
      i++;
      if(i < k) cout << ' ';
    }
    cout << '\n';
  }
}
#include <bits/stdc++.h>
using namespace std;

const int ms = 1005;
const int mod = 1e9+7;

int n, t;
int a[ms];
int dp[ms][ms];

main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  while(getline(cin, s) && s != "0") {
    stringstream ss(s);
    ss >> t >> n;
    for(int i = 0; i < n; i++) {
      ss >> a[i];
    }
    for(int j = 0; j <= t; j++) dp[n][j] = 0;
    for(int i = n-1; i >= 0; i--) {
      for(int j = 0; j <= t; j++) {
        if(a[i] > j) dp[i][j] = dp[i+1][j];
        else dp[i][j] = max(dp[i+1][j], a[i] + dp[i+1][j-a[i]]);
      }
    }
    for(int i = 0, j = t; i < n; i++) {
      if(a[i] <= j && a[i] + dp[i+1][j-a[i]] >= dp[i+1][j]) {
        cout << a[i] << ' ';
        j -= a[i];
      } 
    }
    cout << dp[0][t] << '\n';
  }
}
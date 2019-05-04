// North America Qualifier 2018
// C - Ebony and Ivory
// https://open.kattis.com/problems/ebonyandivory

#include <bits/stdc++.h>
using namespace std;

const int ms = 1e4+5;

int table[2][2][6][6][13];
int exists[2][2][6][6];
int sz[2][2];
int isBlack[90];
int dp[ms][6];
int note[ms];

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      cin >> sz[i][j];
    }
  }
  int n;
  cin >> n;
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      for(int k = 0; k < sz[i][j]; k++) {
        int lo, hi;
        cin >> lo >> hi;
        exists[i][j][lo][hi] = 1;
        for(int l = 1; l <= 12; l++) {
          cin >> table[i][j][lo][hi][l];
        }
      }
    }
  }
  for(int i = 1; i <= 88; i++) {
    int k = i % 12;
    isBlack[i] = k == 0 || k == 2 || k == 5 || k == 7 || k == 10;
  }
  for(int i = 0; i < n; i++) {
    cin >> note[i];
  }
  for(int i = 1; i < n; i++) {
    for(int j = 1; j <= 5; j++) {
      if(note[i] == note[i-1]) dp[i][j] = dp[i-1][j];
      else {
        int lo = min(note[i], note[i-1]);
        int hi = max(note[i], note[i-1]);
        int clo = isBlack[lo];
        int chi = isBlack[hi];
        dp[i][j] = 0x3f3f3f3f;
        for(int k = 1; k <= 5; k++) {
          int loFing = (note[i] == lo) ? j : k;
          int hiFing = (note[i] == lo) ? k : j;
          if(exists[clo][chi][loFing][hiFing]) {
            dp[i][j] = min(dp[i][j], dp[i-1][k] + table[clo][chi][loFing][hiFing][hi-lo]);
          }
        }
      }
    }
  }
  int ans = 0x3f3f3f3f;
  for(int j = 1; j <= 5; j++) {
    ans = min(ans, dp[n-1][j]);
  }
  cout << ans << "\n";
}
#include <bits/stdc++.h>
using namespace std;

const int ms = 305;
const int inf = 0x3f3f3f3f;

string s[ms];
int arr[ms];
int dp[ms][ms][ms][2];
int n, m, k;

int solve(int i, int j, int ava, int curP) {
  if(ava < 0) return inf;
  if(j == m) return 0;
  int &ans = dp[i][j][ava][curP];
  if(~ans) return ans;
  if(curP + 'A' == s[i][j]) {
    return ans = solve(i, j+1, ava, curP);
  } else {
    return ans = min(solve(i, j+1, ava, curP) + 1, solve(i, j+1, ava-1, !curP));
  }
}


main() {
  int tsz;
  cin >> tsz;
  for(int T = 1; T <= tsz; T++) {
    cout << "Case #" << T << ":";
    cin >> m >> n >> k;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++) {
      s[i].resize(m);
    }
    for(int i = 0; i < m; i++) {
      string tempS;
      cin >> tempS;
      for(int j = 0; j < n; j++) {
        s[j][i] = tempS[j];
      }
    }
    for(int i = 1; i <= m+1; i++) {
      int ans1 = 0, ans2 = 0;
      for(int j = 0; j < n; j++) {
        ans1 += solve(j, 0, i-1, 0);
        ans2 += solve(j, 0, i-1, 1);
      }
      arr[i] = n * m - min(ans1, ans2);
    }
    for(int i = 0; i < k; i++) {
      int x;
      cin >> x;
      cout << " " << lower_bound(arr, arr+m+2, n * m - x) - arr;
    }
    cout << '\n';
  }
}
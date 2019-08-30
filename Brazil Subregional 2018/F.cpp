#include <bits/stdc++.h>
using namespace std;

const int ms = 1200;
pair<int, int> shows[ms];
int ending[ms], songs[ms], stage[ms];
int nxt[ms];
int dp[ms][ms];
int n;

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int k;
  cin >> k;
  for(int i = 0; i < k; i++) {
    int m;
    cin >> m;
    while(m--) {
      cin >> shows[n].first >> ending[n] >> songs[n];
      shows[n].second = n;
      stage[n++] = (1 << i);
    }
  }
  sort(shows, shows+n);
  for(int i = 0; i < n; i++) {
    nxt[i] = lower_bound(shows, shows+n, make_pair(ending[shows[i].second], 0)) - shows;
  }
  for(int bm = 0; bm < (1 << k)-1; bm++) {
    dp[n][bm] = -0x3f3f3f3f;
  }
  for(int i = n-1; i >= 0; i--) {
    for(int bm = 0; bm < (1 << k); bm++) {
      int idx = shows[i].second;
      dp[i][bm] = max(dp[i+1][bm], dp[nxt[i]][bm|stage[idx]] + songs[idx]);
   }
  }
  if(dp[0][0] < 0) cout << -1 << '\n';
  else cout << dp[0][0] << '\n';
}
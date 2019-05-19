// Seletiva UnB 2019
// H - Quantos Caminhos?
// https://codeforces.com/group/btcK4I5D5f/contest/244688/problem/H

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;

const int ms = 2e5+5;
const int mod = 1e9+7;

int fExp(int a, int b) {
  int ans = 1;
  while(b) {
    if(b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

int n, m, k;
ii holes[ms];
int ans[ms];
int fat[ms], iFat[ms];

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  cin >> n >> m >> k;
  n--; m--;
  for(int i = 0; i < k; i++) {
    cin >> holes[i].first >> holes[i].second;
    holes[i].first--; holes[i].second--;
  }
  fat[0] = 1; iFat[0] = 1;
  for(int i = 1; i <= n + m; i++) {
    fat[i] = fat[i-1] * i % mod;
    iFat[i] = iFat[i-1] * fExp(i, mod-2) % mod;
  }
  sort(holes, holes+k);
  holes[k] = {n, m};
  for(int i = 0; i <= k; i++) {
    int x = holes[i].first, y = holes[i].second;
    ans[i] = fat[x+y] * iFat[x] % mod * iFat[y] % mod;
    for(int j = 0; j < i; j++) {
      int x2 = holes[j].first, y2 = holes[j].second;
      if(y2 <= y) {
        int val = fat[x+y-x2-y2] * iFat[x-x2] % mod * iFat[y-y2] % mod;
        ans[i] = (ans[i] - ans[j] * val) % mod;
      }
    }
    if(ans[i] < 0) ans[i] += mod;
  }
  cout << ans[k] << endl;
}
// Seletiva UnB 2019
// I - Sequência Binomial Central
// https://codeforces.com/group/btcK4I5D5f/contest/244688/problem/I

#include <bits/stdc++.h>
using namespace std;

const int ms = 2e5+5;

int fat[ms];

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  fat[0] = 0;
  int n, p;
  cin >> n >> p;
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    fat[i] = fat[i-1];
    int x = i;
    while(x % p == 0) {
      x /= p;
      fat[i]++;
    }
    if(fat[i] - fat[i/2] - fat[i - i/2] > 0) ans++;
  }
  cout << ans << endl;
}
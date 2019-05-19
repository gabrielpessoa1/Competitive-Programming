// Benelux Algorithm Programming Contest preliminaries 2018
// I - Isomorphic Inversion
// https://open.kattis.com/problems/isomorphicinversion

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int SHIFT = 0xdefaced, MOD1 = 1e9+7, MOD2 = 1073676287;

string s;

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  cin >> s;
  int ans = 1;
  int left1 = 0, right1 = 0, left2 = 0, right2 = 0, mult1 = 1, mult2 = 1;
  for(int i = 0; i < s.size()/2; i++) {
    left1 = (left1*SHIFT + (s[i] - '0')) % MOD1;
    left2 = (left2*SHIFT + (s[i] - '0')) % MOD2;
    right1 = (right1 + (s[s.size() - 1 - i] - '0') * mult1) % MOD1;
    right2 = (right2 + (s[s.size() - 1 - i] - '0') * mult2) % MOD2;
    mult1 = (mult1 * SHIFT) % MOD1;
    mult2 = (mult2 * SHIFT) % MOD2;
    if(left1 == right1 && left2 == right2) {
      if(i + i + 2 == s.size()) ans++;
      else ans += 2;
      left1 = 0; left2 = 0;
      right1 = 0; right2 = 0;
      mult1 = 1; mult2 = 1;
    }
  }
  cout << ans << endl;
}